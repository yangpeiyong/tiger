%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"

#define YYDEBUG 1

int yylex(void); /* function prototype */

void yyerror(char *s)
{
  EM_error(EM_tokPos, "%s", s);
}
%}

%union {
	int pos;
	int ival;
	string sval;
}

%token <sval> ID STRING
%token <ival> INT

%left AND OR
%nonassoc EQ NEQ LT LE GT GE
%left PLUS MINUS
%left TIMES DIVIDE
%right UMINUS

%token 
  COMMA COLON SEMICOLON LPAREN RPAREN LBRACK RBRACK 
  LBRACE RBRACE DOT 
  PLUS MINUS TIMES DIVIDE EQ NEQ LT LE GT GE
  AND OR ASSIGN
  ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF 
  BREAK NIL
  FUNCTION VAR TYPE 

%start program

%%

program:  exp
exp:  lvalue
   |  lvalue ASSIGN exp
   |  funcall
   |  exp TIMES exp
   |  exp DIVIDE exp
   |  exp PLUS exp
   |  exp MINUS exp
   |  exp EQ exp
   |  exp NEQ exp
   |  exp LT exp
   |  exp LE exp
   |  exp GT exp
   |  exp GE exp
   |  exp AND exp
   |  exp OR exp
   |  rec_creation
   |  NIL
   |  LPAREN expseq RPAREN
   |  INT
   |  STRING
   |  MINUS exp %prec UMINUS
   |  ID LBRACK exp RBRACK OF exp
   |  IF exp THEN exp ELSE exp
   |  IF exp THEN exp
   |  WHILE exp DO exp
   |  FOR ID ASSIGN exp TO exp DO exp
   |  BREAK
   |  LET decs IN expseq END
   ;
expseq: exp SEMICOLON expseq
      | exp
      ;
funcall:  ID LPAREN RPAREN
       |  ID LPAREN argseq RPAREN
       ;
argseq: exp COMMA argseq
      | exp
      ;
rec_creation: ID LBRACE RBRACE
            | ID LBRACE field_seq RBRACE
            ;
field_seq:  ID EQ exp COMMA field_seq
         |  ID EQ exp
         ;

decs: dec decs
    |
    ;
dec:  tydec
   |  vardec
   |  fundec
   ;

tydec:  TYPE ID EQ ty
     ;
ty: ID
  | LBRACE tyfields RBRACE
  | ARRAY OF ID
  ;
tyfields: tyfield tail_tyfields
        |
        ;
tail_tyfields:  COMMA tyfield tail_tyfields
             |
             ;
tyfield:  ID COLON ID 
       ;

vardec: VAR ID ASSIGN exp
      | VAR ID COLON ID ASSIGN exp
      ;

fundec: FUNCTION ID LPAREN tyfields RPAREN EQ exp
      | FUNCTION ID LPAREN tyfields RPAREN COLON ID EQ exp
      ;

lvalue: ID
      | ID DOT ID
      | lvalue DOT ID
      | ID LBRACK exp RBRACK
      | lvalue LBRACK exp RBRACK
      ;
