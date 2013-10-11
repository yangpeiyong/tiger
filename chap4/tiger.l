%{
#include <string.h>
#include "util.h"
#include "y.tab.h"
#include "errormsg.h"

// nested comment level, 0 means not in comment
int g_comment_level=0;
int charPos=1;
void adjust(void);
%}

digit [0-9]
alpha [a-zA-Z]
algit [0-9a-zA-Z_]

%START INIT COMMENT

%%

<INIT>" "	      {adjust(); continue;}
<INIT>"\t"	    {adjust(); continue;}
<INIT>\n	      {adjust(); EM_newline(); continue;}
<INIT>,	        {adjust(); return COMMA;}
<INIT>:	        {adjust(); return COLON;}
<INIT>;	        {adjust(); return SEMICOLON;}
<INIT>"("       {adjust(); return LPAREN;}
<INIT>")"       {adjust(); return RPAREN;}
<INIT>"["       {adjust(); return LBRACK;}
<INIT>"]"       {adjust(); return RBRACK;}
<INIT>"{"       {adjust(); return LBRACE;}
<INIT>"}"       {adjust(); return RBRACE;}
<INIT>"."       {adjust(); return DOT;}
<INIT>"+"       {adjust(); return PLUS;}
<INIT>"-"       {adjust(); return MINUS;}
<INIT>"*"       {adjust(); return TIMES;}
<INIT>"/"       {adjust(); return DIVIDE;}
<INIT>"="       {adjust(); return EQ;}
<INIT>"<>"      {adjust(); return NEQ;}
<INIT>"<"       {adjust(); return LT;}
<INIT>"<="      {adjust(); return LE;}
<INIT>">"       {adjust(); return GT;}
<INIT>">="      {adjust(); return GE;}
<INIT>"&"       {adjust(); return AND;}
<INIT>"|"       {adjust(); return OR;}
<INIT>":="      {adjust(); return ASSIGN;}
<INIT>array     {adjust(); return ARRAY;}
<INIT>if        {adjust(); return IF;}
<INIT>then      {adjust(); return THEN;}
<INIT>else      {adjust(); return ELSE;}
<INIT>while     {adjust(); return WHILE;}
<INIT>for       {adjust(); return FOR;}
<INIT>to        {adjust(); return TO;}
<INIT>do        {adjust(); return DO;}
<INIT>let       {adjust(); return LET;}
<INIT>in  	    {adjust(); return IN;}
<INIT>end       {adjust(); return END;}
<INIT>of  	    {adjust(); return OF;}
<INIT>break     {adjust(); return BREAK;}
<INIT>nil       {adjust(); return NIL;}
<INIT>function  {adjust(); return FUNCTION;}
<INIT>var       {adjust(); return VAR;}
<INIT>type      {adjust(); return TYPE;}
<INIT>{digit}+          {adjust(); yylval.ival=atoi(yytext); return INT;}
<INIT>{alpha}{algit}*	  {adjust(); yylval.sval=String(yytext); return ID;}
<INIT>\"[^"]+\"         {adjust(); yylval.sval=String(yytext); return STRING;}
<INIT>"/*"        {
                    charPos+=yyleng;
                    g_comment_level++;
                    BEGIN COMMENT;
                  }
<INIT>.           {adjust(); EM_error(EM_tokPos,"illegal token");}
<COMMENT>"/*"     {
                    charPos+=yyleng;
                    g_comment_level++;
                  }
<COMMENT>"*/"     {
                    charPos+=yyleng;
                    if (--g_comment_level == 0) {
                      BEGIN INIT;
                    }
                  }
<COMMENT>.        {charPos+=yyleng;}
.	                {BEGIN INIT; yyless(0);}

%%

int yywrap(void)
{
  charPos=1;
  return 1;
}

void adjust(void)
{
  EM_tokPos=charPos;
  charPos+=yyleng;
}
