//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
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
//    contact: José Miguel Rivero (rivero@cs.upc.es)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

grammar Asl;


//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

        
//func f(a : int, b: bool) : int        
        
// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' parameters? ')' output? declarations statements ENDFUNC
        ;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR ID (',' ID)* ':' type  
        ;
        
parameters
        : (ID ':' type)  (',' ID ':' type)*
        ;
output
        : (':' type)
        ;

type
    : basic_type
    | ARRAY '[' INTVAL ']' OF basic_type
    ;
        
basic_type    
        : INT
        | BOOL
        | FLOAT
        | CHAR
        ;

statements
        : (statement)*
        ;
// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           # assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF       # ifStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ID '(' ')' ';'                      # procCall
          // Read a variable
        | READ left_expr ';'                  # readStmt
          // While loop
        | WHILE expr DO statements ENDWHILE    # while
          // Write an expression
        | WRITE expr ';'                      # writeExpr
          // Write a string
        | WRITE STRING ';'                    # writeString
          //Call a function
        | ID '(' (expr)? (',' expr)* ')' ';'     # callfunctionStmt
        
        | RETURN (expr)* ';'                  # return
        ;
// Grammar for left expressions (l-values in C++)
left_expr
        : ID
        | ID '[' expr ']'
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr     
        : '(' expr ')'                               # parenthesis   
        | expr op=(MUL|DIV) expr                     # arithmetic
        | expr op=(PLUS|SUB) expr                    # arithmetic
        | expr AND expr                              # boolean
        | expr OR expr                               # boolean
        | NOT expr                                   # boolean
        | expr op=(EQUAL|DIFF|LT|GT|LTE|GTE) expr    # relational
        | op=(PLUS|SUB) expr                         # value
        | ID '(' (expr)? (',' expr)* ')'             # callfunction        
        | ID '[' expr ']'                            # arrayvalue
        | atom                                       # atomrule
        ;

atom    : ID
        | INTVAL
        | FLOATVAL
        | CHARVAL
        ;
        

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '=' ;
EQUAL     : '==' ;
LT        : '<' ;
GT        : '>' ;
LTE       : '<=' ;
GTE       : '>=' ;
DIFF      : '!=' ;
PLUS      : '+' ;
SUB       : '-' ;
MUL       : '*' ;
DIV       : '/' ;
AND       : 'and' ;
OR        : 'or'  ;
NOT       : 'not' ;
VAR       : 'var';
INT       : 'int';
BOOL      : 'bool';
FLOAT     : 'float';
CHAR      : 'char';
ARRAY     : 'array';
OF        : 'of';
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
WHILE     : 'while' ;
ENDWHILE  : 'endwhile' ;
DO        : 'do' ;
READ      : 'read' ;
RETURN    : 'return';
WRITE     : 'write' ;
ID        : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : ('0'..'9')+ '.' ('0'..'9')* ;
CHARVAL   : '\'' ('a'..'z'|'A'..'Z'|'0'..'9') '\'' ;
// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
