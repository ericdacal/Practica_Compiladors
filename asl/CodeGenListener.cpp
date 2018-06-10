//////////////////////////////////////////////////////////////////////
//
//    CodeGenListener - Walk the parser tree to do
//                             the generation of code
//
//    Copyright (C) 2018  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenListener::CodeGenListener(TypesMgr       & Types,
				 SymTable       & Symbols,
				 TreeDecoration & Decorations,
				 code           & Code) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Code{Code} {
}

void CodeGenListener::enterProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
}
void CodeGenListener::exitProgram(AslParser::ProgramContext *ctx) {
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  subroutine subr(ctx->ID(0)->getText());
  Code.add_subroutine(subr);
  subroutine & subrRef = Code.get_last_subroutine();
  std::string name = ctx->ID(0)->getText();
  if (ctx->returnSt() != NULL) {
    subrRef.add_param("_result");
  }
  //add params
  for(uint i = 1; i < ctx->ID().size(); ++i){
      std::string name = ctx->ID(i)->getText();
      subrRef.add_param(name);
  }
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  codeCounters.reset();
}
void CodeGenListener::exitFunction(AslParser::FunctionContext *ctx) {
  subroutine & subrRef = Code.get_last_subroutine();
  instructionList code = getCodeDecor(ctx->statements());
  
  if (ctx->returnSt() != NULL) {
    instructionList codeReturn = getCodeDecor(ctx->returnSt());
    TypesMgr:: TypeId tRet = getTypeDecor(ctx->returnSt());
    std::string  addrRet = getAddrDecor(ctx->returnSt());
    code = code || codeReturn;
    //std::cout << Types.to_string(tRet) << std::endl;
    if (Types.isIntegerTy(tRet)){
      code = code || instruction::ILOAD("_result",addrRet);
    }
    else if (Types.isBooleanTy(tRet)){
      code = code || instruction::ILOAD("_result",addrRet);
    }
    else if (Types.isFloatTy(tRet)){
      code = code || instruction::FLOAD("_result",addrRet);
    }
    else if (Types.isCharacterTy(tRet)){
      code = code || instruction::CHLOAD("_result",addrRet);
    }
  }
  code = code || instruction::RETURN();
  subrRef.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterCallfunctionStmt(AslParser::CallfunctionStmtContext *ctx) {
    DEBUG_ENTER();
}

void CodeGenListener::exitCallfunctionStmt(AslParser::CallfunctionStmtContext *ctx) {
instructionList code;
  //std::string name = ctx->ident()->ID()->getSymbol()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  std::string name = ctx->ID()->getText();
  TypesMgr::TypeId t = Symbols.getType(name);
  TypesMgr:: TypeId tRet = Types.getFuncReturnType(t);
  
  if (!Types.isVoidTy(tRet)) {
    code = code || instruction::PUSH("");
  }
  
  for(uint i = 0; i < ctx->expr().size(); ++i){
      std::string param = getAddrDecor(ctx->expr(i));
      TypesMgr::TypeId texpr = getTypeDecor(ctx->expr(i));
      std::string f_addr = "%" + codeCounters.newTEMP();
      
      if (Types.isArrayTy(texpr)) {
            code = code || instruction::ALOAD(f_addr, param);
            param = f_addr;
      }
      instructionList codeArimetic = getCodeDecor(ctx->expr(i));
      TypesMgr::TypeId tparam = Types.getParameterType(t,i);
      code = code || codeArimetic;
      
      if(Types.isFloatTy(tparam) and Types.isIntegerTy(texpr)) {
        code = code || instruction::FLOAT(param,param);
      }
      code = code || instruction::PUSH(param);
  }
  code = code || instruction::CALL(name);
  
  for(uint i = 0; i < ctx->expr().size(); ++i){
      std::string param = getAddrDecor(ctx->expr(i));
      code = code || instruction::POP("");
  }
  if (!Types.isVoidTy(tRet)) {
    code = code || instruction::POP(temp);
  }
  putAddrDecor(ctx,temp);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterCallfunction(AslParser::CallfunctionContext *ctx) {
    DEBUG_ENTER();
}

void CodeGenListener::exitCallfunction(AslParser::CallfunctionContext *ctx) {
  instructionList code;
  //std::string name = ctx->ident()->ID()->getSymbol()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  std::string name = ctx->ID()->getText();
  TypesMgr::TypeId t = Symbols.getType(name);
  TypesMgr:: TypeId tRet = Types.getFuncReturnType(t);
  
  if (!Types.isVoidTy(tRet)) {
    code = code || instruction::PUSH("");
  }
  
  for(uint i = 0; i < ctx->expr().size(); ++i){
      std::string param = getAddrDecor(ctx->expr(i));
      TypesMgr::TypeId texpr = getTypeDecor(ctx->expr(i));
      std::string f_addr = "%" + codeCounters.newTEMP();
      
      if (Types.isArrayTy(texpr)) {
            code = code || instruction::ALOAD(f_addr, param);
            param = f_addr;
      }
      
      instructionList codeArimetic = getCodeDecor(ctx->expr(i));
      TypesMgr::TypeId tparam = Types.getParameterType(t,i);
      code = code || codeArimetic;
      
      if(Types.isFloatTy(tparam) and Types.isIntegerTy(texpr)) {
        code = code || instruction::FLOAT(param,param);
      }
      code = code || instruction::PUSH(param);
  }
  code = code || instruction::CALL(name);
  
  for(uint i = 0; i < ctx->expr().size(); ++i){
      std::string param = getAddrDecor(ctx->expr(i));
      code = code || instruction::POP("");
  }
  if (!Types.isVoidTy(tRet)) {
    code = code || instruction::POP(temp);
  }
  putAddrDecor(ctx,temp);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterReturnSt(AslParser::ReturnStContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitReturnSt(AslParser::ReturnStContext *ctx) {
  instructionList code;
  if (ctx->expr() != NULL){
    TypesMgr:: TypeId tRet = getTypeDecor(ctx->expr());
    std::string temp = "%"+codeCounters.newTEMP();
    std::string name = getAddrDecor(ctx->expr());
    code  = getCodeDecor(ctx->expr());
    if (Types.isIntegerTy(tRet)){
      code = code || instruction::ILOAD(temp,name);
    }
    else if (Types.isFloatTy(tRet)){
      code = code || instruction::FLOAD(temp,name);
    }
    else if (Types.isCharacterTy(tRet)){
      code = code || instruction::CHLOAD(temp,name);
    }
    else if (Types.isBooleanTy(tRet)) {
        code = code || instruction::ILOAD(temp,name);
    }
    putCodeDecor(ctx,code);
    putAddrDecor(ctx,temp);
  }
  DEBUG_EXIT();
}


void CodeGenListener::enterDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_EXIT();
}

void CodeGenListener::enterVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitVariable_decl(AslParser::Variable_declContext *ctx) {
  subroutine  & subrRef = Code.get_last_subroutine();
  TypesMgr::TypeId  t1 = getTypeDecor(ctx->type());
  std::size_t size = Types.getSizeOfType(t1);

  // add variables
  for (uint i = 0; i < ctx->ID().size(); ++i){
      std::string name = ctx->ID(i)->getText();
      subrRef.add_var(name, size);
  }
  DEBUG_EXIT();
}

void CodeGenListener::enterType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitType(AslParser::TypeContext *ctx) {
  DEBUG_EXIT();
}

void CodeGenListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitStatements(AslParser::StatementsContext *ctx) {
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    code = code || getCodeDecor(stCtx);
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
  instructionList code;
  
  std::string     addr1 = getAddrDecor(ctx->left_expr());
  std::string     offs1 = getOffsetDecor(ctx->left_expr());
  instructionList code1 = getCodeDecor(ctx->left_expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  
  std::string     addr2 = getAddrDecor(ctx->expr());
  std::string     offs2 = getOffsetDecor(ctx->expr());
  instructionList code2 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
  
  std::string temp = "%"+codeCounters.newTEMP();
  code = code1 || code2;
  
  if (offs1 != ""){
    code = code || instruction::XLOAD(addr1,offs1,addr2);
  }
  else{
    code = code || instruction::LOAD(addr1, addr2);
  }
  putCodeDecor(ctx, code);
  
  DEBUG_EXIT();
}

void CodeGenListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements(0));

  if (ctx->statements(1) != NULL) {
    std::string label = codeCounters.newLabelIF();
    std::string labelElse = "else" + codeCounters.newTEMP();
    std::string labelEndIf = "endif"+label;
    instructionList  codeElse = getCodeDecor(ctx->statements(1));
    
    code = code1 || instruction::FJUMP(addr1, labelElse) || code2 ||instruction::UJUMP(labelEndIf) || instruction::LABEL(labelElse) || codeElse || instruction::LABEL(labelEndIf);
    putCodeDecor(ctx, code);
  }
  else {
    std::string label = codeCounters.newLabelIF();
    std::string labelEndIf = "endif"+label;
    code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
          code2 || instruction::LABEL(labelEndIf);
    putCodeDecor(ctx, code);
  }
  DEBUG_EXIT();
}

void CodeGenListener::enterWhile(AslParser::WhileContext *ctx) {
    DEBUG_ENTER();
}

void CodeGenListener::exitWhile(AslParser::WhileContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements());
  
  std::string label = codeCounters.newLabelWHILE();
  std::string labelRightCondition = "loop" + codeCounters.newTEMP();
  std::string labelEndWhile = "endwhile"+label;
  

  code = code1 || instruction::FJUMP(addr1, labelEndWhile) 
  || instruction::LABEL(labelRightCondition) || code2
  || code1 || instruction::FJUMP(addr1, labelEndWhile) || instruction::UJUMP(labelRightCondition) ||instruction::LABEL(labelEndWhile);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}


void CodeGenListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
  instructionList  code;
  std::string     addr1 = getAddrDecor(ctx->left_expr());
  std::string     offs1 = getOffsetDecor(ctx->left_expr());
  instructionList code1 = getCodeDecor(ctx->left_expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  
  if (offs1 != ""){
    std::string temp = "%"+codeCounters.newTEMP();
    if(Types.isFloatTy(tid1)){
      code = code1 || instruction::READF(temp);
    }
    else if (Types.isCharacterTy(tid1)){
      code = code1 || instruction::READC(temp);
    }
    else{
      code = code1 || instruction::READI(temp);
    }
    code = code || instruction::XLOAD(addr1,offs1,temp);
  }
  
  else if(Types.isFloatTy(tid1)){
    code = code1 || instruction::READF(addr1);
  }
  else if (Types.isCharacterTy(tid1)){
    code = code1 || instruction::READC(addr1);
  }
  else{
    code = code1 || instruction::READI(addr1);
  }
  putAddrDecor(ctx, addr1);
  putCodeDecor(ctx, code);
  putOffsetDecor(ctx, "");
  
  DEBUG_EXIT();
}


void CodeGenListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
  instructionList code;
  std::string     addr1 = getAddrDecor(ctx->expr());
  std::string     offs1 = getOffsetDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx);

  if(Types.isFloatTy(tid1)){
    code = code1 || instruction::WRITEF(addr1);
  }
  else code = code1 || instruction::WRITEI(addr1);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteString(AslParser::WriteStringContext *ctx) {
  instructionList code;
  std::string s = ctx->STRING()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  int i = 1;
  while (i < int(s.size())-1) {
    if (s[i] != '\\') {
      code = code ||
	     instruction::CHLOAD(temp, s.substr(i,1)) ||
	     instruction::WRITEC(temp);
      i += 1;
    }
    else {
      assert(i < int(s.size())-2);
      if (s[i+1] == 'n') {
        code = code || instruction::WRITELN();
        i += 2;
      }
      else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,2)) ||
	       instruction::WRITEC(temp);
        i += 2;
      }
      else {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,1)) ||
	       instruction::WRITEC(temp);
        i += 1;
      }
    }
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
  if (ctx->expr() == NULL) {
    putAddrDecor(ctx, ctx->ID()->getText());
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, instructionList());
  }
  else {
    
    std::string addr = getAddrDecor(ctx->expr());
    instructionList code = getCodeDecor(ctx->expr());
    
    std::string nameVector = ctx->ID()->getText();
    std::string offset = "%"+codeCounters.newTEMP();
    std::string i = "%"+codeCounters.newTEMP();
    std::string temp = "%"+codeCounters.newTEMP();

    TypesMgr::TypeId t = Symbols.getType(nameVector);
    TypesMgr::TypeId tVector = Types.getArrayElemType(t);
    int size = Types.getSizeOfType(tVector);
  
    code = code || instruction::ILOAD(i,std::to_string(size)) || instruction::MUL(offset,i,addr);
    
    putAddrDecor(ctx, nameVector);
    putCodeDecor(ctx, code);
    putOffsetDecor(ctx, offset);
  }
  
  DEBUG_ENTER();
}

void CodeGenListener::enterArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId t  = getTypeDecor(ctx);

  //std::cout << ctx->getText() << " " << Types.to_string(t) << ": " << ctx->expr(0)->getText() << " " << Types.to_string(t1) << " " << ctx->expr(1)->getText() << " " << Types.to_string(t2) << std::endl;
  
  std::string temp = "%"+codeCounters.newTEMP();

  
  if (Types.isIntegerTy(t)){
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->PLUS())
      code = code || instruction::ADD(temp, addr1, addr2);
    else if (ctx->SUB())
      code = code || instruction::SUB(temp, addr1, addr2);
  }
  else{
    std::string faddr1,faddr2;
    if (Types.isIntegerTy(getTypeDecor(ctx->expr(0)))) {
        faddr1 = "%"+codeCounters.newTEMP();
        faddr2 = addr2;
        code = code  || instruction::FLOAT(faddr1,addr1);
    }
    else if (Types.isIntegerTy(getTypeDecor(ctx->expr(1)))) {
        faddr2 = "%"+codeCounters.newTEMP();
        faddr1 = addr1;
        code = code  || instruction::FLOAT(faddr2,addr2);
    }
    else {
        faddr1 = addr1;
        faddr2 = addr2;
    }
    
    if (ctx->MUL()){
      //std::cout <<"MULT"<<  std::endl;
      code = code || instruction::FMUL(temp, faddr1, faddr2);
    }
    else if (ctx->DIV()){
      //std::cout <<"DIV"<<  std::endl;
      code = code || instruction::FDIV(temp, faddr1, faddr2);
    }
    else if (ctx->PLUS()){
      //std::cout <<"PLUS"<<  std::endl;
      code = code || instruction::FADD(temp, faddr1, faddr2);
    }
    else if (ctx->SUB()){
      //std::cout <<"SUB"<<  std::endl;
      code = code || instruction::FSUB(temp, faddr1, faddr2);
    }
  }
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitRelational(AslParser::RelationalContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId t  = getTypeDecor(ctx);
  
  std::string temp = "%"+codeCounters.newTEMP();
  
  if (!Types.isFloatTy(t1) and !Types.isFloatTy(t2) ){
    //std::cout << "Relational " << Types.to_string(t1) << " " << Types.to_string(t2) << " " << Types.to_string(t) <<  std::endl;
    if (ctx->EQUAL()){
        code = code || instruction::EQ(temp, addr1, addr2);
    }
    else if (ctx->DIFF()){
        code = code || instruction::EQ(temp, addr1, addr2);
        code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->LT()){
        code = code || instruction::LT(temp, addr1, addr2);
    }
    else if (ctx->GT()){
        code = code || instruction::LE(temp, addr1, addr2);
        code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->LTE()){
        code = code || instruction::LE(temp, addr1, addr2);
    }
    else if (ctx->GTE()){
        code = code || instruction::LT(temp, addr1, addr2);
        code = code || instruction::NOT(temp, temp);
    }
  }
  else{
    std::string faddr1,faddr2;
    if (Types.isIntegerTy(getTypeDecor(ctx->expr(0)))) {
        faddr1 = "%"+codeCounters.newTEMP();
        faddr2 = addr2;
        code = code  || instruction::FLOAT(faddr1,addr1);
    }
    else if (Types.isIntegerTy(getTypeDecor(ctx->expr(1)))) {
        faddr2 = "%"+codeCounters.newTEMP();
        faddr1 = addr1;
        code = code  || instruction::FLOAT(faddr2,addr2);
    }
    else {
        faddr1 = addr1;
        faddr2 = addr2;
    }
    
    if (ctx->EQUAL()){
        code = code || instruction::FEQ(temp, addr1, addr2);
    }
    else if (ctx->DIFF()){
        code = code || instruction::FEQ(temp, addr1, addr2);
        code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->LT()){
        code = code || instruction::FLT(temp, addr1, addr2);
    }
    else if (ctx->GT()){
        code = code || instruction::FLE(temp, addr1, addr2);
        code = code || instruction::NOT(temp, temp);
    }
    else if (ctx->LTE()){
        code = code || instruction::FLE(temp, addr1, addr2);
    }
    else if (ctx->GTE()){
        code = code || instruction::FLT(temp, addr1, addr2);
        code = code || instruction::NOT(temp, temp);
    }
    
  }
  
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}


void CodeGenListener::enterBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitBoolean(AslParser::BooleanContext *ctx) {
  
  std::string temp = "%"+codeCounters.newTEMP();
  
  if (ctx->NOT()){
    std::string     addr1 = getAddrDecor(ctx->expr(0));
    instructionList code1 = getCodeDecor(ctx->expr(0));
    code1 = code1 || instruction::NOT(temp, addr1);
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code1);
  }
  else if (ctx->AND()){
    std::string     addr1 = getAddrDecor(ctx->expr(0));
    instructionList code1 = getCodeDecor(ctx->expr(0));
    std::string     addr2 = getAddrDecor(ctx->expr(1));
    instructionList code2 = getCodeDecor(ctx->expr(1));
    instructionList code  = code1 || code2;
    code = code || instruction::AND(temp, addr1, addr2);
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  }
  else if (ctx->OR()){
    std::string     addr1 = getAddrDecor(ctx->expr(0));
    instructionList code1 = getCodeDecor(ctx->expr(0));
    std::string     addr2 = getAddrDecor(ctx->expr(1));
    instructionList code2 = getCodeDecor(ctx->expr(1));
    instructionList code  = code1 || code2;
    code = code || instruction::OR(temp, addr1, addr2);
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  }
}
    
void CodeGenListener::enterParenthesis(AslParser::ParenthesisContext *ctx){
  DEBUG_ENTER();
    
}

void CodeGenListener::exitParenthesis(AslParser::ParenthesisContext *ctx){ 
  putCodeDecor(ctx,getCodeDecor(ctx->expr()));
  putAddrDecor(ctx, getAddrDecor(ctx->expr()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->expr()));
  DEBUG_EXIT();
}

void CodeGenListener::enterValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitValue(AslParser::ValueContext *ctx) {
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->PLUS()){
    putCodeDecor(ctx,getCodeDecor(ctx->expr()));
    putAddrDecor(ctx, getAddrDecor(ctx->expr()));
    putOffsetDecor(ctx, getOffsetDecor(ctx->expr()));
  }
  else if (ctx->SUB()){
    std::string     addr = getAddrDecor(ctx->expr());
    TypesMgr::TypeId t = getTypeDecor(ctx->expr());
    instructionList code = getCodeDecor(ctx->expr());
    if (Types.isFloatTy(t)){
      code  = code || instruction::FNEG(temp, addr);
    }
    else{
      code  = code || instruction::NEG(temp, addr);
    }
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  }
  DEBUG_EXIT();
}


void CodeGenListener::enterArrayvalue(AslParser::ArrayvalueContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitArrayvalue(AslParser::ArrayvalueContext *ctx) {

  std::string addr = getAddrDecor(ctx->expr());
  instructionList code = getCodeDecor(ctx->expr());
  
  std::string nameVector = ctx->ID()->getText();
  std::string offset = "%"+codeCounters.newTEMP();
  std::string i = "%"+codeCounters.newTEMP();
  std::string temp = "%"+codeCounters.newTEMP();
  TypesMgr::TypeId t = Symbols.getType(nameVector);
  TypesMgr::TypeId tVector = Types.getArrayElemType(t);
  int size = Types.getSizeOfType(tVector);

  code = code || instruction::ILOAD(i,std::to_string(size)) || instruction::MUL(offset,i,addr) || instruction::LOADX(temp, nameVector,offset);
  
  putAddrDecor(ctx, temp);
  putCodeDecor(ctx, code);
  putOffsetDecor(ctx, "");
  DEBUG_EXIT();
}


void CodeGenListener::enterAtomrule(AslParser::AtomruleContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitAtomrule(AslParser::AtomruleContext *ctx) {
  putCodeDecor(ctx,getCodeDecor(ctx->atom()));
  putAddrDecor(ctx, getAddrDecor(ctx->atom()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->atom()));
  DEBUG_EXIT();
  
}

void CodeGenListener::enterAtom(AslParser::AtomContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitAtom(AslParser::AtomContext *ctx) {
  std::string temp = "%"+codeCounters.newTEMP();
  instructionList code;
  
  if(ctx->ID() != NULL) {
    putAddrDecor(ctx, ctx->ID()->getText());
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, instructionList());
  }
  else if(ctx->INTVAL() != NULL) {
    code = instruction::ILOAD(temp, ctx->getText());
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  }
  else if(ctx->FLOATVAL() != NULL) {
    code = instruction::FLOAD(temp, ctx->getText());
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    
  }
  else if(ctx->CHARVAL() != NULL) {
    code = instruction::CHLOAD(temp, ctx->getText());
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  }
  else if(ctx->BOOLVAL() != NULL) {
    if (ctx->getText() == "false") {
      code = instruction::ILOAD(temp,"0");
    }
    else if (ctx->getText() == "true") {
      code = instruction::ILOAD(temp,"1");
    }
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  }
  DEBUG_EXIT();
}

/*void CodeGenListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}*/

/*void CodeGenListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  DEBUG_EXIT();
}*/

/*void CodeGenListener::enterIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIdent(AslParser::IdentContext *ctx) {
  putAddrDecor(ctx, ctx->ID()->getText());
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, instructionList());
  DEBUG_EXIT();
}*/

// void CodeGenListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void CodeGenListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void CodeGenListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG(">>> visit " << node->getSymbol()->getLine() << ":" << node->getSymbol()->getCharPositionInLine() << " CodeGen TerminalNode");
// }
// void CodeGenListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type, Addr, Offset and Code
SymTable::ScopeId CodeGenListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
std::string CodeGenListener::getAddrDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getAddr(ctx);
}
std::string  CodeGenListener::getOffsetDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getOffset(ctx);
}
instructionList CodeGenListener::getCodeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getCode(ctx);
}

// Setters for the necessary tree node attributes:
//   Addr, Offset and Code
void CodeGenListener::putAddrDecor(antlr4::ParserRuleContext *ctx, const std::string & a) {
  Decorations.putAddr(ctx, a);
}
void CodeGenListener::putOffsetDecor(antlr4::ParserRuleContext *ctx, const std::string & o) {
  Decorations.putOffset(ctx, o);
}
void CodeGenListener::putCodeDecor(antlr4::ParserRuleContext *ctx, const instructionList & c) {
  Decorations.putCode(ctx, c);
}
