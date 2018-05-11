
// Generated from Asl.g4 by ANTLR 4.7.1


#include "AslListener.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

void AslParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AslParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(24);
      function();
      setState(27); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(29);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

std::vector<tree::TerminalNode *> AslParser::FunctionContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::FunctionContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::OutputContext* AslParser::FunctionContext::output() {
  return getRuleContext<AslParser::OutputContext>(0);
}

std::vector<AslParser::TypeContext *> AslParser::FunctionContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::FunctionContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

void AslParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AslParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    match(AslParser::FUNC);
    setState(32);
    match(AslParser::ID);
    setState(33);
    match(AslParser::T__0);
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(34);
      match(AslParser::ID);
      setState(35);
      match(AslParser::T__1);
      setState(36);
      type();
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__2) {
        setState(38);
        match(AslParser::T__2);
        setState(39);
        match(AslParser::ID);
        setState(40);
        match(AslParser::T__1);
        setState(41);
        type();
        setState(46);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(49);
    match(AslParser::T__3);
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__1) {
      setState(50);
      output();
    }
    setState(53);
    declarations();
    setState(54);
    statements();
    setState(55);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

void AslParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void AslParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(57);
      variable_decl();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

void AslParser::Variable_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_decl(this);
}

void AslParser::Variable_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_decl(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(AslParser::VAR);
    setState(64);
    match(AslParser::ID);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__2) {
      setState(65);
      match(AslParser::T__2);
      setState(66);
      match(AslParser::ID);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    match(AslParser::T__1);
    setState(73);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputContext ------------------------------------------------------------------

AslParser::OutputContext::OutputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::TypeContext* AslParser::OutputContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::OutputContext::getRuleIndex() const {
  return AslParser::RuleOutput;
}

void AslParser::OutputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutput(this);
}

void AslParser::OutputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutput(this);
}

AslParser::OutputContext* AslParser::output() {
  OutputContext *_localctx = _tracker.createInstance<OutputContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleOutput);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(AslParser::T__1);
    setState(76);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::Basic_typeContext* AslParser::TypeContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}

tree::TerminalNode* AslParser::TypeContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::TypeContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::TypeContext::OF() {
  return getToken(AslParser::OF, 0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

void AslParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AslParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::INT:
      case AslParser::BOOL:
      case AslParser::FLOAT:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        basic_type();
        break;
      }

      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        match(AslParser::ARRAY);
        setState(80);
        match(AslParser::T__4);
        setState(81);
        match(AslParser::INTVAL);
        setState(82);
        match(AslParser::T__5);
        setState(83);
        match(AslParser::OF);
        setState(84);
        basic_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Basic_typeContext ------------------------------------------------------------------

AslParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Basic_typeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::Basic_typeContext::getRuleIndex() const {
  return AslParser::RuleBasic_type;
}

void AslParser::Basic_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasic_type(this);
}

void AslParser::Basic_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasic_type(this);
}

AslParser::Basic_typeContext* AslParser::basic_type() {
  Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleBasic_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

void AslParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void AslParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(89);
      statement();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteExpr(this);
}
void AslParser::WriteExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteExpr(this);
}
//----------------- CallfunctionStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::CallfunctionStmtContext::ID() {
  return getToken(AslParser::ID, 0);
}

std::vector<AslParser::ExprContext *> AslParser::CallfunctionStmtContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::CallfunctionStmtContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::CallfunctionStmtContext::CallfunctionStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::CallfunctionStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallfunctionStmt(this);
}
void AslParser::CallfunctionStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallfunctionStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void AslParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReadStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadStmt(this);
}
void AslParser::ReadStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void AslParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- WhileContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileContext::WhileContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}
void AslParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteString(this);
}
void AslParser::WriteStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteString(this);
}
//----------------- ReturnContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

std::vector<AslParser::ExprContext *> AslParser::ReturnContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ReturnContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ReturnContext::ReturnContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}
void AslParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(95);
      left_expr();
      setState(96);
      match(AslParser::ASSIGN);
      setState(97);
      expr(0);
      setState(98);
      match(AslParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(100);
      match(AslParser::IF);
      setState(101);
      expr(0);
      setState(102);
      match(AslParser::THEN);
      setState(103);
      statements();
      setState(106);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(104);
        match(AslParser::ELSE);
        setState(105);
        statements();
      }
      setState(108);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(110);
      match(AslParser::READ);
      setState(111);
      left_expr();
      setState(112);
      match(AslParser::T__6);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(114);
      match(AslParser::WHILE);
      setState(115);
      expr(0);
      setState(116);
      match(AslParser::DO);
      setState(117);
      statements();
      setState(118);
      match(AslParser::ENDWHILE);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(120);
      match(AslParser::WRITE);
      setState(121);
      expr(0);
      setState(122);
      match(AslParser::T__6);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(124);
      match(AslParser::WRITE);
      setState(125);
      match(AslParser::STRING);
      setState(126);
      match(AslParser::T__6);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::CallfunctionStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(127);
      match(AslParser::ID);
      setState(128);
      match(AslParser::T__0);
      setState(130);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(129);
        expr(0);
      }
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__2) {
        setState(132);
        match(AslParser::T__2);
        setState(133);
        expr(0);
        setState(138);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(139);
      match(AslParser::T__3);
      setState(140);
      match(AslParser::T__6);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(141);
      match(AslParser::RETURN);
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(142);
        expr(0);
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(148);
      match(AslParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Left_exprContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::ExprContext* AslParser::Left_exprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft_expr(this);
}

void AslParser::Left_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft_expr(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(151);
      match(AslParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(152);
      match(AslParser::ID);
      setState(153);
      match(AslParser::T__4);
      setState(154);
      expr(0);
      setState(155);
      match(AslParser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallfunctionContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::CallfunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

std::vector<AslParser::ExprContext *> AslParser::CallfunctionContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::CallfunctionContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::CallfunctionContext::CallfunctionContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::CallfunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallfunction(this);
}
void AslParser::CallfunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallfunction(this);
}
//----------------- BooleanContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::BooleanContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BooleanContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}
void AslParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}
//----------------- AtomruleContext ------------------------------------------------------------------

AslParser::AtomContext* AslParser::AtomruleContext::atom() {
  return getRuleContext<AslParser::AtomContext>(0);
}

AslParser::AtomruleContext::AtomruleContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::AtomruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomrule(this);
}
void AslParser::AtomruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomrule(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic(this);
}
void AslParser::ArithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::DIFF() {
  return getToken(AslParser::DIFF, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LTE() {
  return getToken(AslParser::LTE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GTE() {
  return getToken(AslParser::GTE, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::RelationalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational(this);
}
void AslParser::RelationalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParenthesisContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ParenthesisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesis(this);
}
void AslParser::ParenthesisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesis(this);
}
//----------------- ValueContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ValueContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::ValueContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ValueContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}
void AslParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}
//----------------- ArrayvalueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ArrayvalueContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::ExprContext* AslParser::ArrayvalueContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ArrayvalueContext::ArrayvalueContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArrayvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayvalue(this);
}
void AslParser::ArrayvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayvalue(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(160);
      match(AslParser::T__0);
      setState(161);
      expr(0);
      setState(162);
      match(AslParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BooleanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(164);
      dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::NOT);
      setState(165);
      expr(7);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(166);
      dynamic_cast<ValueContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AslParser::PLUS

      || _la == AslParser::SUB)) {
        dynamic_cast<ValueContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(167);
      expr(4);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CallfunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(168);
      match(AslParser::ID);
      setState(169);
      match(AslParser::T__0);
      setState(171);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(170);
        expr(0);
      }
      setState(177);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__2) {
        setState(173);
        match(AslParser::T__2);
        setState(174);
        expr(0);
        setState(179);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(180);
      match(AslParser::T__3);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ArrayvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      match(AslParser::ID);
      setState(182);
      match(AslParser::T__4);
      setState(183);
      expr(0);
      setState(184);
      match(AslParser::T__5);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<AtomruleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      atom();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(206);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(204);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(189);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(190);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::MUL

          || _la == AslParser::DIV)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(191);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(192);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(193);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::SUB)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(194);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(195);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(196);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::EQUAL)
            | (1ULL << AslParser::LT)
            | (1ULL << AslParser::GT)
            | (1ULL << AslParser::LTE)
            | (1ULL << AslParser::GTE)
            | (1ULL << AslParser::DIFF))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(197);
          expr(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(198);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(199);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::AND);
          setState(200);
          expr(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(201);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(202);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::OR);
          setState(203);
          expr(6);
          break;
        }

        } 
      }
      setState(208);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

AslParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::AtomContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

tree::TerminalNode* AslParser::AtomContext::ID() {
  return getToken(AslParser::ID, 0);
}

tree::TerminalNode* AslParser::AtomContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::AtomContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::AtomContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}


size_t AslParser::AtomContext::getRuleIndex() const {
  return AslParser::RuleAtom;
}

void AslParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void AslParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

AslParser::AtomContext* AslParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 22, AslParser::RuleAtom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::BOOLVAL)
      | (1ULL << AslParser::ID)
      | (1ULL << AslParser::INTVAL)
      | (1ULL << AslParser::FLOATVAL)
      | (1ULL << AslParser::CHARVAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "declarations", "variable_decl", "output", "type", 
  "basic_type", "statements", "statement", "left_expr", "expr", "atom"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'('", "':'", "','", "')'", "'['", "']'", "';'", "'='", "'=='", "'<'", 
  "'>'", "'<='", "'>='", "'!='", "'+'", "'-'", "'*'", "'/'", "'and'", "'or'", 
  "'not'", "'var'", "'int'", "'bool'", "'float'", "'char'", "'array'", "'of'", 
  "'if'", "'then'", "'else'", "'endif'", "'func'", "'endfunc'", "'while'", 
  "'endwhile'", "'do'", "'read'", "'return'", "'write'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "ASSIGN", "EQUAL", "LT", "GT", "LTE", 
  "GTE", "DIFF", "PLUS", "SUB", "MUL", "DIV", "AND", "OR", "NOT", "VAR", 
  "INT", "BOOL", "FLOAT", "CHAR", "ARRAY", "OF", "IF", "THEN", "ELSE", "ENDIF", 
  "FUNC", "ENDFUNC", "WHILE", "ENDWHILE", "DO", "READ", "RETURN", "WRITE", 
  "BOOLVAL", "ID", "INTVAL", "FLOATVAL", "CHARVAL", "STRING", "COMMENT", 
  "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x32, 0xd6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 0x2, 0x6, 0x2, 0x1c, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x30, 0xb, 0x3, 0x5, 0x3, 0x32, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x36, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x7, 
    0x4, 0x3d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x40, 0xb, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x46, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x49, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x58, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x7, 0x9, 
    0x5d, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x60, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x6d, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x85, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x89, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0x8c, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x92, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x95, 0xb, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x98, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0xa0, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xae, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xb2, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xb5, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xbe, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0xcf, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xd2, 0xb, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x2, 0x3, 0x16, 0xe, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x2, 0x7, 0x3, 0x2, 0x19, 
    0x1c, 0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 0x13, 0x14, 0x3, 0x2, 0xb, 0x10, 
    0x3, 0x2, 0x2b, 0x2f, 0x2, 0xe9, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x4d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x59, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x97, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x1c, 0x5, 0x4, 0x3, 0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x2, 
    0x2, 0x3, 0x20, 0x3, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x7, 0x23, 0x2, 
    0x2, 0x22, 0x23, 0x7, 0x2c, 0x2, 0x2, 0x23, 0x31, 0x7, 0x3, 0x2, 0x2, 
    0x24, 0x25, 0x7, 0x2c, 0x2, 0x2, 0x25, 0x26, 0x7, 0x4, 0x2, 0x2, 0x26, 
    0x27, 0x5, 0xc, 0x7, 0x2, 0x27, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 
    0x7, 0x5, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x2c, 0x2, 0x2, 0x2a, 0x2b, 0x7, 
    0x4, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0xc, 0x7, 0x2, 0x2c, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x24, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 
    0x7, 0x6, 0x2, 0x2, 0x34, 0x36, 0x5, 0xa, 0x6, 0x2, 0x35, 0x34, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x5, 0x6, 0x4, 0x2, 0x38, 0x39, 0x5, 0x10, 0x9, 
    0x2, 0x39, 0x3a, 0x7, 0x24, 0x2, 0x2, 0x3a, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x18, 0x2, 0x2, 0x42, 0x47, 0x7, 0x2c, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0x5, 0x2, 0x2, 0x44, 0x46, 0x7, 0x2c, 0x2, 
    0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 
    0x7, 0x4, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0xc, 0x7, 0x2, 0x4c, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x4, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0xc, 
    0x7, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x50, 0x58, 0x5, 0xe, 0x8, 
    0x2, 0x51, 0x52, 0x7, 0x1d, 0x2, 0x2, 0x52, 0x53, 0x7, 0x7, 0x2, 0x2, 
    0x53, 0x54, 0x7, 0x2d, 0x2, 0x2, 0x54, 0x55, 0x7, 0x8, 0x2, 0x2, 0x55, 
    0x56, 0x7, 0x1e, 0x2, 0x2, 0x56, 0x58, 0x5, 0xe, 0x8, 0x2, 0x57, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x51, 0x3, 0x2, 0x2, 0x2, 0x58, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5a, 0x9, 0x2, 0x2, 0x2, 0x5a, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5d, 0x5, 0x12, 0xa, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x5, 0x14, 0xb, 0x2, 0x62, 0x63, 
    0x7, 0xa, 0x2, 0x2, 0x63, 0x64, 0x5, 0x16, 0xc, 0x2, 0x64, 0x65, 0x7, 
    0x9, 0x2, 0x2, 0x65, 0x98, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x1f, 
    0x2, 0x2, 0x67, 0x68, 0x5, 0x16, 0xc, 0x2, 0x68, 0x69, 0x7, 0x20, 0x2, 
    0x2, 0x69, 0x6c, 0x5, 0x10, 0x9, 0x2, 0x6a, 0x6b, 0x7, 0x21, 0x2, 0x2, 
    0x6b, 0x6d, 0x5, 0x10, 0x9, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 
    0x7, 0x22, 0x2, 0x2, 0x6f, 0x98, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 
    0x28, 0x2, 0x2, 0x71, 0x72, 0x5, 0x14, 0xb, 0x2, 0x72, 0x73, 0x7, 0x9, 
    0x2, 0x2, 0x73, 0x98, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x25, 0x2, 
    0x2, 0x75, 0x76, 0x5, 0x16, 0xc, 0x2, 0x76, 0x77, 0x7, 0x27, 0x2, 0x2, 
    0x77, 0x78, 0x5, 0x10, 0x9, 0x2, 0x78, 0x79, 0x7, 0x26, 0x2, 0x2, 0x79, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x2a, 0x2, 0x2, 0x7b, 0x7c, 
    0x5, 0x16, 0xc, 0x2, 0x7c, 0x7d, 0x7, 0x9, 0x2, 0x2, 0x7d, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x2a, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x30, 
    0x2, 0x2, 0x80, 0x98, 0x7, 0x9, 0x2, 0x2, 0x81, 0x82, 0x7, 0x2c, 0x2, 
    0x2, 0x82, 0x84, 0x7, 0x3, 0x2, 0x2, 0x83, 0x85, 0x5, 0x16, 0xc, 0x2, 
    0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x5, 0x2, 0x2, 0x87, 0x89, 
    0x5, 0x16, 0xc, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x8e, 0x7, 0x6, 0x2, 0x2, 0x8e, 0x98, 0x7, 0x9, 0x2, 0x2, 
    0x8f, 0x93, 0x7, 0x29, 0x2, 0x2, 0x90, 0x92, 0x5, 0x16, 0xc, 0x2, 0x91, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 0x7, 0x9, 
    0x2, 0x2, 0x97, 0x61, 0x3, 0x2, 0x2, 0x2, 0x97, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x70, 0x3, 0x2, 0x2, 0x2, 0x97, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x97, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x97, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x98, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0xa0, 0x7, 0x2c, 0x2, 0x2, 0x9a, 0x9b, 0x7, 
    0x2c, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x7, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x16, 
    0xc, 0x2, 0x9d, 0x9e, 0x7, 0x8, 0x2, 0x2, 0x9e, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x8, 0xc, 0x1, 0x2, 0xa2, 
    0xa3, 0x7, 0x3, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x16, 0xc, 0x2, 0xa4, 0xa5, 
    0x7, 0x6, 0x2, 0x2, 0xa5, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 
    0x17, 0x2, 0x2, 0xa7, 0xbe, 0x5, 0x16, 0xc, 0x9, 0xa8, 0xa9, 0x9, 0x3, 
    0x2, 0x2, 0xa9, 0xbe, 0x5, 0x16, 0xc, 0x6, 0xaa, 0xab, 0x7, 0x2c, 0x2, 
    0x2, 0xab, 0xad, 0x7, 0x3, 0x2, 0x2, 0xac, 0xae, 0x5, 0x16, 0xc, 0x2, 
    0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x5, 0x2, 0x2, 0xb0, 0xb2, 
    0x5, 0x16, 0xc, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0xbe, 0x7, 0x6, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x2c, 0x2, 0x2, 
    0xb8, 0xb9, 0x7, 0x7, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x16, 0xc, 0x2, 0xba, 
    0xbb, 0x7, 0x8, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbe, 
    0x5, 0x18, 0xd, 0x2, 0xbd, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0xc, 0xc, 0x2, 0x2, 
    0xc0, 0xc1, 0x9, 0x4, 0x2, 0x2, 0xc1, 0xcf, 0x5, 0x16, 0xc, 0xd, 0xc2, 
    0xc3, 0xc, 0xb, 0x2, 0x2, 0xc3, 0xc4, 0x9, 0x3, 0x2, 0x2, 0xc4, 0xcf, 
    0x5, 0x16, 0xc, 0xc, 0xc5, 0xc6, 0xc, 0xa, 0x2, 0x2, 0xc6, 0xc7, 0x9, 
    0x5, 0x2, 0x2, 0xc7, 0xcf, 0x5, 0x16, 0xc, 0xb, 0xc8, 0xc9, 0xc, 0x8, 
    0x2, 0x2, 0xc9, 0xca, 0x7, 0x15, 0x2, 0x2, 0xca, 0xcf, 0x5, 0x16, 0xc, 
    0x9, 0xcb, 0xcc, 0xc, 0x7, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x16, 0x2, 0x2, 
    0xcd, 0xcf, 0x5, 0x16, 0xc, 0x8, 0xce, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xd4, 0x9, 0x6, 0x2, 0x2, 0xd4, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x15, 0x1d, 0x2e, 0x31, 0x35, 0x3e, 0x47, 0x57, 0x5e, 0x6c, 0x84, 0x8a, 
    0x93, 0x97, 0x9f, 0xad, 0xb3, 0xbd, 0xce, 0xd0, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
