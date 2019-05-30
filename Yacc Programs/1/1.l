%{
#include<stdio.h>
#include"y.tab.h"
%}
%%
[a-zA-Z0-9]+ {return ID;}
"\n" {}
. {return yytext[0];}
%%
