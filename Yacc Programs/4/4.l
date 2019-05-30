%{
#include<stdio.h>
#include"y.tab.h"
%}
%%
"\n"	{}
"a"	{return A;}
"b"	{return B;}
.	{return yytext[0];}
%%
