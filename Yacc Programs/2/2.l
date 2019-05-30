%{
  #include "y.tab.h"
%}
%%
[0-9]+ {return NUMBER;}
[a-zA-Z] {return LETTER;}
[_]* {return UND;}
[\n] {return NL;}
. {return yytext[0];}
%%

