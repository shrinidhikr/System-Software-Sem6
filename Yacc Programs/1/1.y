%{
#include<stdio.h>
%}
%token ID
%left '+' '-'
%left '*' '/'
%%
E: E '+' E|
	E '-' E|
	E '*' E|
	E '/' E|
	ID;
%%
void main()
{
	printf("Enter an Expression: ");
	yyparse();
	printf("\nValid Expression\n");
}
void yyerror()
{
	printf("\nInvalid Expression\n");
	exit(0);
}
