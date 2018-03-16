
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AslParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AslParser.
 */
class  AslListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(AslParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(AslParser::ProgramContext *ctx) = 0;

  virtual void enterFunction(AslParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(AslParser::FunctionContext *ctx) = 0;

  virtual void enterDeclarations(AslParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(AslParser::DeclarationsContext *ctx) = 0;

  virtual void enterVariable_decl(AslParser::Variable_declContext *ctx) = 0;
  virtual void exitVariable_decl(AslParser::Variable_declContext *ctx) = 0;

  virtual void enterParameters(AslParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(AslParser::ParametersContext *ctx) = 0;

  virtual void enterOutput(AslParser::OutputContext *ctx) = 0;
  virtual void exitOutput(AslParser::OutputContext *ctx) = 0;

  virtual void enterType(AslParser::TypeContext *ctx) = 0;
  virtual void exitType(AslParser::TypeContext *ctx) = 0;

  virtual void enterBasic_type(AslParser::Basic_typeContext *ctx) = 0;
  virtual void exitBasic_type(AslParser::Basic_typeContext *ctx) = 0;

  virtual void enterStatements(AslParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(AslParser::StatementsContext *ctx) = 0;

  virtual void enterAssignStmt(AslParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(AslParser::AssignStmtContext *ctx) = 0;

  virtual void enterIfStmt(AslParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(AslParser::IfStmtContext *ctx) = 0;

  virtual void enterProcCall(AslParser::ProcCallContext *ctx) = 0;
  virtual void exitProcCall(AslParser::ProcCallContext *ctx) = 0;

  virtual void enterReadStmt(AslParser::ReadStmtContext *ctx) = 0;
  virtual void exitReadStmt(AslParser::ReadStmtContext *ctx) = 0;

  virtual void enterWhile(AslParser::WhileContext *ctx) = 0;
  virtual void exitWhile(AslParser::WhileContext *ctx) = 0;

  virtual void enterWriteExpr(AslParser::WriteExprContext *ctx) = 0;
  virtual void exitWriteExpr(AslParser::WriteExprContext *ctx) = 0;

  virtual void enterWriteString(AslParser::WriteStringContext *ctx) = 0;
  virtual void exitWriteString(AslParser::WriteStringContext *ctx) = 0;

  virtual void enterCallfunctionStmt(AslParser::CallfunctionStmtContext *ctx) = 0;
  virtual void exitCallfunctionStmt(AslParser::CallfunctionStmtContext *ctx) = 0;

  virtual void enterReturn(AslParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(AslParser::ReturnContext *ctx) = 0;

  virtual void enterLeft_expr(AslParser::Left_exprContext *ctx) = 0;
  virtual void exitLeft_expr(AslParser::Left_exprContext *ctx) = 0;

  virtual void enterCallfunction(AslParser::CallfunctionContext *ctx) = 0;
  virtual void exitCallfunction(AslParser::CallfunctionContext *ctx) = 0;

  virtual void enterBoolean(AslParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(AslParser::BooleanContext *ctx) = 0;

  virtual void enterAtomrule(AslParser::AtomruleContext *ctx) = 0;
  virtual void exitAtomrule(AslParser::AtomruleContext *ctx) = 0;

  virtual void enterArithmetic(AslParser::ArithmeticContext *ctx) = 0;
  virtual void exitArithmetic(AslParser::ArithmeticContext *ctx) = 0;

  virtual void enterRelational(AslParser::RelationalContext *ctx) = 0;
  virtual void exitRelational(AslParser::RelationalContext *ctx) = 0;

  virtual void enterParenthesis(AslParser::ParenthesisContext *ctx) = 0;
  virtual void exitParenthesis(AslParser::ParenthesisContext *ctx) = 0;

  virtual void enterValue(AslParser::ValueContext *ctx) = 0;
  virtual void exitValue(AslParser::ValueContext *ctx) = 0;

  virtual void enterArrayvalue(AslParser::ArrayvalueContext *ctx) = 0;
  virtual void exitArrayvalue(AslParser::ArrayvalueContext *ctx) = 0;

  virtual void enterAtom(AslParser::AtomContext *ctx) = 0;
  virtual void exitAtom(AslParser::AtomContext *ctx) = 0;


};

