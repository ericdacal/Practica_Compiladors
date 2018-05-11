
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AslListener.h"


/**
 * This class provides an empty implementation of AslListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AslBaseListener : public AslListener {
public:

  virtual void enterProgram(AslParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(AslParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunction(AslParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(AslParser::FunctionContext * /*ctx*/) override { }

  virtual void enterDeclarations(AslParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(AslParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterVariable_decl(AslParser::Variable_declContext * /*ctx*/) override { }
  virtual void exitVariable_decl(AslParser::Variable_declContext * /*ctx*/) override { }

  virtual void enterOutput(AslParser::OutputContext * /*ctx*/) override { }
  virtual void exitOutput(AslParser::OutputContext * /*ctx*/) override { }

  virtual void enterType(AslParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(AslParser::TypeContext * /*ctx*/) override { }

  virtual void enterBasic_type(AslParser::Basic_typeContext * /*ctx*/) override { }
  virtual void exitBasic_type(AslParser::Basic_typeContext * /*ctx*/) override { }

  virtual void enterStatements(AslParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(AslParser::StatementsContext * /*ctx*/) override { }

  virtual void enterAssignStmt(AslParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(AslParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(AslParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(AslParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterReadStmt(AslParser::ReadStmtContext * /*ctx*/) override { }
  virtual void exitReadStmt(AslParser::ReadStmtContext * /*ctx*/) override { }

  virtual void enterWhile(AslParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(AslParser::WhileContext * /*ctx*/) override { }

  virtual void enterWriteExpr(AslParser::WriteExprContext * /*ctx*/) override { }
  virtual void exitWriteExpr(AslParser::WriteExprContext * /*ctx*/) override { }

  virtual void enterWriteString(AslParser::WriteStringContext * /*ctx*/) override { }
  virtual void exitWriteString(AslParser::WriteStringContext * /*ctx*/) override { }

  virtual void enterCallfunctionStmt(AslParser::CallfunctionStmtContext * /*ctx*/) override { }
  virtual void exitCallfunctionStmt(AslParser::CallfunctionStmtContext * /*ctx*/) override { }

  virtual void enterReturn(AslParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(AslParser::ReturnContext * /*ctx*/) override { }

  virtual void enterLeft_expr(AslParser::Left_exprContext * /*ctx*/) override { }
  virtual void exitLeft_expr(AslParser::Left_exprContext * /*ctx*/) override { }

  virtual void enterCallfunction(AslParser::CallfunctionContext * /*ctx*/) override { }
  virtual void exitCallfunction(AslParser::CallfunctionContext * /*ctx*/) override { }

  virtual void enterBoolean(AslParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(AslParser::BooleanContext * /*ctx*/) override { }

  virtual void enterAtomrule(AslParser::AtomruleContext * /*ctx*/) override { }
  virtual void exitAtomrule(AslParser::AtomruleContext * /*ctx*/) override { }

  virtual void enterArithmetic(AslParser::ArithmeticContext * /*ctx*/) override { }
  virtual void exitArithmetic(AslParser::ArithmeticContext * /*ctx*/) override { }

  virtual void enterRelational(AslParser::RelationalContext * /*ctx*/) override { }
  virtual void exitRelational(AslParser::RelationalContext * /*ctx*/) override { }

  virtual void enterParenthesis(AslParser::ParenthesisContext * /*ctx*/) override { }
  virtual void exitParenthesis(AslParser::ParenthesisContext * /*ctx*/) override { }

  virtual void enterValue(AslParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(AslParser::ValueContext * /*ctx*/) override { }

  virtual void enterArrayvalue(AslParser::ArrayvalueContext * /*ctx*/) override { }
  virtual void exitArrayvalue(AslParser::ArrayvalueContext * /*ctx*/) override { }

  virtual void enterAtom(AslParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(AslParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

