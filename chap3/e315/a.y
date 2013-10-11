%token WHILE DO ID ASSIGN PLUS

%right ASSIGN
%left  PLUS
%left  DO

%%

S:  E
 ;
E:  WHILE E DO E
 |  ID ASSIGN E
 |  E PLUS E
 |  ID
 ;

%%

int main()
{
  return yyparse();
}
