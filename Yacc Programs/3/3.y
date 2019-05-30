%{
#include<stdio.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
expr:e "\n" {printf("\nReslult: %d\n",$$); return;}
e: e'+'e {$$=$1+$3;}|
	e'-'e {$$=$1-$3;}|
	e'*'e {$$=$1*$3;}|
	e'/'e {$$=$1/$3;}|
	'('e')' {$$=$2;}|
	NUM {$$=$1;};
%%
void main()
{
	printf("\nEnter an Arithmetic Expression: ");
	yyparse();
}
void yyerror()
{
	printf("\nInvalid Expression\n");
}
