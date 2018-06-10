//////////////////////////////////////////////////////////////////////
//
//    TypeCheckListener - Walk the parser tree to do the semantic
//                        typecheck for the Asl programming language
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

#include "TypeCheckListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckListener::TypeCheckListener(TypesMgr       & Types,
				     SymTable       & Symbols,
				     TreeDecoration & Decorations,
				     SemErrors      & Errors) :
  Types{Types},
  Symbols {Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

void TypeCheckListener::enterProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
}
void TypeCheckListener::exitProgram(AslParser::ProgramContext *ctx) {
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
}

void TypeCheckListener::enterFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  
  // Symbols.print();
}
void TypeCheckListener::exitFunction(AslParser::FunctionContext *ctx) {
  
  Symbols.popScope();
  DEBUG_EXIT();
}

void TypeCheckListener::enterDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitType(AslParser::TypeContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
}


void TypeCheckListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) 
{
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  //std::cout << Types.to_string(t1) << " " << Types.to_string(t2) << std::endl;
  if(Types.isFunctionTy(t2)) {
    if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and (not Types.equalTypes(t1, t2))) {
      Errors.incompatibleAssignment(ctx->ASSIGN());
    }
  } 
  else {
    if (Types.isVoidTy(t2)){
        Errors.isNotFunction(ctx->expr());
    }
    else if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and (not Types.copyableTypes(t1, t2))) {
      Errors.incompatibleAssignment(ctx->ASSIGN());
    }
  }
  
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
}

void TypeCheckListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  DEBUG_EXIT();
}

void TypeCheckListener::enterWhile(AslParser::WhileContext *ctx) {
    DEBUG_ENTER();
}

void TypeCheckListener::exitWhile(AslParser::WhileContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  DEBUG_EXIT();
}

void TypeCheckListener::enterCallfunctionStmt(AslParser::CallfunctionStmtContext *ctx) {
    DEBUG_ENTER();
}

void TypeCheckListener::exitCallfunctionStmt(AslParser::CallfunctionStmtContext *ctx) {
    std::string ident = ctx->ID()->getText();
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    
    if(Symbols.findInStack(ident) == -1) {
      Errors.undeclaredIdent(ctx->ID());
    }
  
    else if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
        Errors.isNotCallable(ctx);
    }
    else if (!Types.isErrorTy(t1)){
      if(Types.getNumOfParameters(t1) != ctx->expr().size()){
          Errors.numberOfParameters(ctx);
      }
      for(uint i = 0; i < Types.getNumOfParameters(t1); ++i) {
          TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(i));
          std::string name = ctx->expr(i)->getText();
          if(not Types.equalTypes(Types.getParameterType(t1,i), t2)) {
              Errors.incompatibleParameter(ctx->expr(i), i+1, ctx);
          }
          if(not getIsLValueDecor(ctx->expr(i)) and not Symbols.findInCurrentScope(name) and not Symbols.findInStack(name)) {
              Errors.nonReferenceableExpression(ctx);
          }
      }
    }
    DEBUG_EXIT();
}

void TypeCheckListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
}

void TypeCheckListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
}

void TypeCheckListener::enterWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_EXIT();
}

void TypeCheckListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
  std::string ident = ctx->ID()->getText();
  TypesMgr::TypeId t1 = Symbols.getType(ident);
  int error = 0;
  if(ctx->expr() != NULL and not Types.isErrorTy(t1)) 
  {
      if(!Types.isArrayTy(t1)) 
      {
        Errors.nonArrayInArrayAccess(ctx);
        TypesMgr::TypeId t = Types.createErrorTy();
        putTypeDecor(ctx, t);
        ++error;
      }
      
      TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
      if(!Types.isIntegerTy(t2)) 
      {
          Errors.nonIntegerIndexInArrayAccess(ctx->expr());
          TypesMgr::TypeId t = Types.createErrorTy();
          putTypeDecor(ctx, t);
          ++error;
      }

      if (error == 0 and Types.isArrayTy(t1)) putTypeDecor(ctx, Types.getArrayElemType(t1));
      else if(error == 0) putTypeDecor(ctx, t1);
  }
  else putTypeDecor(ctx, t1);
  if(Types.isFunctionTy(t1)) putIsLValueDecor(ctx, false); 
  else putIsLValueDecor(ctx, true); //LValueDecor cuando el contexto es referenciable
  DEBUG_EXIT();
}

void TypeCheckListener::enterArithmetic(AslParser::ArithmeticContext *ctx) 
{
  DEBUG_ENTER();
}
void TypeCheckListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  //if(Types.isFunctionTy(t1)) t1 = Types.getFuncReturnType(t1); 
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  //if(Types.isFunctionTy(t2)) t2 = Types.getFuncReturnType(t2); 

  /*std::string oper = ctx->op->getText();
  std::cout <<"Typecheck "<< Types.to_string(t1) << " " << Types.to_string(t2) << " " << oper << std::endl;*/
  
  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    Errors.incompatibleOperator(ctx->op);
    
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
  }
 
  else{
    TypesMgr::TypeId t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
  }
  DEBUG_EXIT();
}

void TypeCheckListener::enterFloatExpr(AslParser::FloatExprContext *ctx){
  DEBUG_ENTER();
}
void TypeCheckListener::exitFloatExpr(AslParser::FloatExprContext *ctx){
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if(Types.isFunctionTy(t1)) t1 = Types.getFuncReturnType(t1); 
  
  if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))))
    Errors.incompatibleOperator(ctx->op);
    
  if(Types.isIntegerTy(t1)){
    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
  }
  DEBUG_EXIT();
}

void TypeCheckListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitRelational(AslParser::RelationalContext *ctx) {

  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t); 
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitValue(AslParser::ValueContext *ctx) {
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterParenthesis(AslParser::ParenthesisContext *ctx){
  DEBUG_ENTER();
    
}
void TypeCheckListener::exitParenthesis(AslParser::ParenthesisContext *ctx){ 
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());
  putTypeDecor(ctx,t);
  DEBUG_EXIT();
}

void TypeCheckListener::enterBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
    
}
void TypeCheckListener::exitBoolean(AslParser::BooleanContext *ctx) {
  if(ctx->expr().size() > 1) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and ((not Types.isBooleanTy(t1)) or (not Types.isBooleanTy(t2)))) Errors.incompatibleOperator(ctx->op);
  }
  else {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    if ((not Types.isErrorTy(t1)) and ((not Types.isBooleanTy(t1)))) Errors.incompatibleOperator(ctx->op);
  }
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}

void TypeCheckListener::enterCallfunction(AslParser::CallfunctionContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitCallfunction(AslParser::CallfunctionContext *ctx) {
  std::string ident = ctx->ID()->getText();
  TypesMgr::TypeId t1 = Symbols.getType(ident);
  
  if(Symbols.findInStack(ident) == -1) {
      Errors.undeclaredIdent(ctx->ID());
  }

  else if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
        Errors.isNotCallable(ctx);
  }
  else {
    int errors = 0;
    if ((Types.getNumOfParameters(t1) < ctx->expr().size()) or (Types.getNumOfParameters(t1) > ctx->expr().size())) Errors.numberOfParameters(ctx);
    else {
        for(uint i = 0; i < Types.getNumOfParameters(t1); ++i) {
            if(ctx->expr(i) == NULL) {
                if (errors == 0) Errors.numberOfParameters(ctx);
                ++errors;
            }
            else {
                if(!Types.copyableTypes(Types.getParameterType(t1,i),getTypeDecor(ctx->expr(i)))) Errors.incompatibleParameter(ctx->expr(i),i + 1,ctx);
            }
        }
       
    }
     putTypeDecor(ctx, Types.getFuncReturnType(t1));
     t1 = getTypeDecor(ctx);
  }
  DEBUG_EXIT();
  
}



void TypeCheckListener::enterReturnSt(AslParser::ReturnStContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitReturnSt(AslParser::ReturnStContext *ctx) {

  if(ctx->expr() != NULL) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    TypesMgr::TypeId t2 = Symbols.getCurrentFunctionTy();
    
    if(not Types.equalTypes(t1, Types.getFuncReturnType(t2))) {
      Errors.incompatibleReturn(ctx);
    }
  }
  else 
  {

    TypesMgr::TypeId t1 = Types.createVoidTy();
    TypesMgr::TypeId t2 = Symbols.getCurrentFunctionTy();
    if(not Types.equalTypes(t1, Types.getFuncReturnType(t2))) {
      Errors.incompatibleReturn(ctx);
       
    }
    
  }
  DEBUG_EXIT();
}

void TypeCheckListener::enterReturn(AslParser::ReturnContext *ctx) {
  DEBUG_ENTER();
}


void TypeCheckListener::exitReturn(AslParser::ReturnContext *ctx) {
  TypesMgr::TypeId t2 = Symbols.getCurrentFunctionTy();
  
  if(ctx->expr() != NULL) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    TypesMgr::TypeId t3 = Types.getFuncReturnType(t2);
    
    if(not Types.equalTypes(t1, t3) and (not Types.copyableTypes(t3,t1))) {
      Errors.incompatibleReturn(ctx);
    }
  }
  else {
    if (!Types.isVoidFunction(t2)){
      Errors.incompatibleReturn(ctx);
    }
  }
  DEBUG_EXIT();
}

void TypeCheckListener::enterArrayvalue(AslParser::ArrayvalueContext *ctx) {
  DEBUG_ENTER();
}
  

void TypeCheckListener::exitArrayvalue(AslParser::ArrayvalueContext *ctx) {
  std::string ident = ctx->ID()->getText();
  TypesMgr::TypeId t1 = Symbols.getType(ident);
  
  if(!Types.isArrayTy(t1) and not Types.isErrorTy(t1)) {
    Errors.nonArrayInArrayAccess(ctx);
  }
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());
  if(!Types.isIntegerTy(t)) Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  else {
    if(!Types.isErrorTy(t1) && Types.isArrayTy(t1)) putTypeDecor(ctx, Types.getArrayElemType(t1));
    else putTypeDecor(ctx, t1);
  }
  DEBUG_EXIT();
}

void TypeCheckListener::enterAtomrule(AslParser::AtomruleContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitAtomrule(AslParser::AtomruleContext *ctx) {
  TypesMgr::TypeId t = getTypeDecor(ctx->atom());
  putTypeDecor(ctx,t);
  DEBUG_EXIT();
}

void TypeCheckListener::enterAtom(AslParser::AtomContext *ctx) {
  DEBUG_ENTER();
}

void TypeCheckListener::exitAtom(AslParser::AtomContext *ctx) {
  if(ctx->ID() != NULL) {
    std::string ident = ctx->ID()->getText();
    if(Symbols.findInStack(ident) > -1) {
      TypesMgr::TypeId t1 = Symbols.getType(ident);
      putTypeDecor(ctx, t1);
      t1 = getTypeDecor(ctx);
    }
  }
  else if(ctx->INTVAL() != NULL) {
    TypesMgr::TypeId t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
    t = getTypeDecor(ctx);
  }
  else if(ctx->FLOATVAL() != NULL) {
    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
    
  }
  else if(ctx->CHARVAL() != NULL) {
    TypesMgr::TypeId t = Types.createCharacterTy();
    putTypeDecor(ctx, t);
  }
  else if(ctx->BOOLVAL() != NULL)  {
    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
  }
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
}



// Getters for the necessary tree node atributes:t
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckListener::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckListener::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckListener::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckListener::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
