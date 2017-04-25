%{
/*#include <math.h> */
#include "y.tab.h"
#include "sym.h"
%}

%%

PI |
PHI {
  yylval.symptr = symLookup(yytext);
  return CONST;
  }

([0-9]+|([0-9]*\.[0-9]+)([eE][+-]?[0-9]+)?) {
  yylval.dval = atof(yytext);
  return NUMBER;
  }

[ \t] ; /* ignore whitespace */

[A-Za-z][A-Za-z0-9]* {
  /* return symbol pointer */
  yylval.symptr = symLookup(yytext);
  return NAME;
  }

"$" { return 0; }
\n |
. { return yytext[0]; };

%%

int main()
{
  symInit();
  yyparse();
}

int yywrap() { return 1; }
