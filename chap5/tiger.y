%{
#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "errormsg.h"
#include "absyn.h"

#define YYDEBUG 1

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
  EM_error(EM_tokPos, "%s", s);
}
%}

%union {
	int pos;
	int ival;
	string sval;
  A_var var;
  A_exp exp;
  A_dec dec;
  A_ty ty;
  A_decList decList;
  A_expList expList;
  A_field field;
  A_fieldList fieldList;
  A_efield efield;
  A_efieldList efieldList;
}

%token <sval> ID STRING
%token <ival> INT

%type <exp> exp program funcall rec_creation
%type <var> lvalue
%type <expList> argseq expseq
%type <efieldList> efield_seq
%type <efield> efield
%type <decList> decs
%type <dec> dec tydec vardec fundec
%type <ty> ty
%type <fieldList> tyfields tail_tyfields
%type <field> tyfield

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

program:  exp           { absyn_root = $1; }
exp:  lvalue            { $$ = A_VarExp(EM_tokPos, $1); }
   |  lvalue ASSIGN exp { $$ = A_AssignExp(EM_tokPos, $1, $3); }
   |  funcall           { $$ = $1; }
   |  exp TIMES exp   { $$ = A_OpExp(EM_tokPos, A_timesOp, $1, $3); }
   |  exp DIVIDE exp  { $$ = A_OpExp(EM_tokPos, A_divideOp, $1, $3); }
   |  exp PLUS exp    { $$ = A_OpExp(EM_tokPos, A_plusOp, $1, $3); }
   |  exp MINUS exp   { $$ = A_OpExp(EM_tokPos, A_minusOp, $1, $3); }
   |  exp EQ exp      { $$ = A_OpExp(EM_tokPos, A_eqOp, $1, $3); }
   |  exp NEQ exp     { $$ = A_OpExp(EM_tokPos, A_neqOp, $1, $3); }
   |  exp LT exp      { $$ = A_OpExp(EM_tokPos, A_ltOp, $1, $3); }
   |  exp LE exp      { $$ = A_OpExp(EM_tokPos, A_leOp, $1, $3); }
   |  exp GT exp      { $$ = A_OpExp(EM_tokPos, A_gtOp, $1, $3); }
   |  exp GE exp      { $$ = A_OpExp(EM_tokPos, A_geOp, $1, $3); }
   |  exp AND exp     { $$ = A_IfExp(EM_tokPos, $1, $3, A_IntExp(EM_tokPos, 0)); }
   |  exp OR exp      { $$ = A_IfExp(EM_tokPos, $1, A_IntExp(EM_tokPos, 1), $3); }
   |  rec_creation    { $$ = $1; }
   |  NIL                             { $$ = A_NilExp(EM_tokPos); }
   |  LPAREN expseq RPAREN            { $$ = A_SeqExp(EM_tokPos, $2); }
   |  INT                             { $$ = A_IntExp(EM_tokPos, yylval.ival); }
   |  STRING                          { $$ = A_StringExp(EM_tokPos, yylval.sval); }
   |  MINUS exp %prec UMINUS          { $$ = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(0, 0), $2); }
   |  ID LBRACK exp RBRACK OF exp     { $$ = A_ArrayExp(EM_tokPos, S_Symbol($1), $3, $6); }
   |  IF exp THEN exp ELSE exp        { $$ = A_IfExp(EM_tokPos, $2, $4, $6); }
   |  IF exp THEN exp                 { $$ = A_IfExp(EM_tokPos, $2, $4, NULL); }
   |  WHILE exp DO exp                { $$ = A_WhileExp(EM_tokPos, $2, $4); }
   |  FOR ID ASSIGN exp TO exp DO exp { $$ = A_ForExp(EM_tokPos, S_Symbol($2), $4, $6, $8); }
   |  BREAK                           { $$ = A_BreakExp(EM_tokPos); }
   |  LET decs IN expseq END          { $$ = A_LetExp(EM_tokPos, $2, $4); }
   ;
expseq: exp SEMICOLON expseq  { $$ = A_ExpList($1, $3); }
      | exp                   { $$ = A_ExpList($1, NULL); }
      ;
funcall:  ID LPAREN RPAREN        { $$ = A_CallExp(EM_tokPos, S_Symbol($1), NULL); }
       |  ID LPAREN argseq RPAREN { $$ = A_CallExp(EM_tokPos, S_Symbol($1), $3); }
       ;
argseq: exp COMMA argseq  { $$ = A_ExpList($1, $3); }
      | exp               { $$ = A_ExpList($1, NULL); }
      ;
rec_creation: ID LBRACE RBRACE            { $$ = A_RecordExp(EM_tokPos, S_Symbol($1), NULL); }
            | ID LBRACE efield_seq RBRACE { $$ = A_RecordExp(EM_tokPos, S_Symbol($1), $3); }
            ;
efield_seq: efield COMMA efield_seq { $$ = A_EfieldList($1, $3); }
         |  efield                  { $$ = A_EfieldList($1, NULL); }
         ;
efield:  ID EQ exp  { $$ = A_Efield(S_Symbol($1), $3); }
     ;

decs: dec decs  { $$ = A_DecList($1, $2); }
    |           { $$ = NULL; }
    ;
dec:  tydec   { $$ = $1; }
   |  vardec  { $$ = $1; }
   |  fundec  { $$ = $1; }
   ;

tydec:  TYPE ID EQ ty { $$ = A_TypeDec(EM_tokPos, S_Symbol($2), $4); }
     ;
ty: ID                      { $$ = A_NameTy(S_Symbol($1)); }
  | LBRACE tyfields RBRACE  { $$ = A_RecordTy($2); }
  | ARRAY OF ID             { $$ = A_ArrayTy(S_Symbol($3)); }
  ;
tyfields: tyfield tail_tyfields { $$ = A_FieldList($1, $2); }
        |                       { $$ = NULL; }
        ;
tail_tyfields:  COMMA tyfield tail_tyfields { $$ = A_FieldList($2, $3); }
             |                              { $$ = NULL; }
             ;
tyfield:  ID COLON ID { $$ = A_Field(EM_tokPos, S_Symbol($1), S_Symbol($3)); }
       ;

vardec: VAR ID ASSIGN exp           { $$ = A_VarDec(EM_tokPos, S_Symbol($2), NULL, $4); }
      | VAR ID COLON ID ASSIGN exp  { $$ = A_VarDec(EM_tokPos, S_Symbol($2), S_Symbol($4), $6); }
      ;

fundec: FUNCTION ID LPAREN tyfields RPAREN EQ exp           {$$ = A_Fundec(EM_tokPos, S_Symbol($2), $4, NULL, $7); }
      | FUNCTION ID LPAREN tyfields RPAREN COLON ID EQ exp  {$$ = A_Fundec(EM_tokPos, S_Symbol($2), $4, S_Symbol($7), $9); }
      ;

lvalue: ID            { $$ = A_SimpleVar(EM_tokPos, S_Symbol($1)); }
      | ID DOT ID     { $$ = A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol($1)), S_Symbol($3)); }
      | lvalue DOT ID { $$ = A_FieldVar(EM_tokPos, $1, S_Symbol($3)); }
      | ID LBRACK exp RBRACK      { $$ = A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol($1)), $3); }
      | lvalue LBRACK exp RBRACK  { $$ = A_SubscriptVar(EM_tokPos, $1, $3); }
      ;
