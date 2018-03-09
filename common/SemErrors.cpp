/////////////////////////////////////////////////////////////////
//
//    SemErrors - Semantic errors for the Asl programming language
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
////////////////////////////////////////////////////////////////

#include "SemErrors.h"

#include "antlr4-runtime.h"

#include <iostream>

// using namespace std;


SemErrors::SemErrors() : numErrors{0} {
}

unsigned int SemErrors::getNumberOfErrors() const {
  return numErrors;
}

void SemErrors::declaredIdent(antlr4::tree::TerminalNode *node) {
  ++numErrors;
  printErrorLoc(node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine());
  std::cout << "Identifier '" << node->getSymbol()->getText() << "' already declared." << std::endl;
}

void SemErrors::undeclaredIdent(antlr4::tree::TerminalNode *node) {
  ++numErrors;
  printErrorLoc(node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine());
  std::cout << "Identifier '" << node->getSymbol()->getText() << "' is undeclared." << std::endl;
}

void SemErrors::incompatibleAssignment(antlr4::tree::TerminalNode *node) {
  ++numErrors;
  printErrorLoc(node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine());
  std::cout << "Assignment with incompatible types." << std::endl;
}

void SemErrors::nonReferenceableLeftExpr(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Left expression of assignment is not referenceable." << std::endl;
}

void SemErrors::incompatibleOperator(antlr4::Token* tok) {
  ++numErrors;
  printErrorLoc(tok->getLine(), tok->getCharPositionInLine());
  std::cout << "Operator '" << tok->getText() << "' with incompatible types." << std::endl;
}

void SemErrors::nonArrayInArrayAccess(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Array access to a non array operand." << std::endl;
}

void SemErrors::nonIntegerIndexInArrayAccess(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Array access witn non integer index." << std::endl;
}

void SemErrors::booleanRequired(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Instruction '" << ctx->getStart()->getText() << "' requires a boolean condition." << std::endl;
}

void SemErrors::isNotCallable(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Identifier '" << ctx->getStart()->getText() << "' is not a callable function." << std::endl;
}

void SemErrors::isNotProcedure(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Identifier '" << ctx->getStart()->getText() << "' is not a procedure." << std::endl;
}

void SemErrors::isNotFunction(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Identifier '" << ctx->getStart()->getText() << "' is a void returning function." << std::endl;
}

void SemErrors::numberOfParameters(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "The number of parameters in the call to '" << ctx->getStart()->getText() << "' does not match." << std::endl;
}

void SemErrors::incompatibleParameter(antlr4::ParserRuleContext *pCtx,
				      unsigned int n,
				      antlr4::ParserRuleContext *cCtx) {
  ++numErrors;
  printErrorLoc(pCtx->getStart()->getLine(), pCtx->getStart()->getCharPositionInLine());
  std::cout << "Parameter #" << n << " with incompatible types in call to '" << cCtx->getStart()->getText() << "'." << std::endl;
}

void SemErrors::referenceableParameter(antlr4::ParserRuleContext *pCtx,
				       unsigned int n,
				       antlr4::ParserRuleContext *cCtx) {
  ++numErrors;
  printErrorLoc(pCtx->getStart()->getLine(), pCtx->getStart()->getCharPositionInLine());
  std::cout << "Parameter #" << n << " is expected to be referenceable in call to '" << cCtx->getStart()->getText() << "'." << std::endl;
}

void SemErrors::incompatibleReturn(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Return with incompatible type." << std::endl;
}

void SemErrors::readWriteRequireBasic(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Basic type required in '" << ctx->getStart()->getText() << "'." << std::endl;
}

void SemErrors::nonReferenceableExpression(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
  std::cout << "Referenceable expression required in '" << ctx->getStart()->getText() << "'." << std::endl;
}

void SemErrors::noMainProperlyDeclared(antlr4::ParserRuleContext *ctx) {
  ++numErrors;
  printErrorLoc(ctx->getStop()->getLine(), ctx->getStop()->getCharPositionInLine());
  std::cout << "There is no 'main' function properly declared." << std::endl;
}

void SemErrors::printErrorLoc(unsigned int line, unsigned int col) const {
  // std::cout << "[" << line << ":" << col << "] error: ";
  std::cout << "Line " << line << ":" << col << " error: ";
}
