%{
#include<stdio.h>
%}
%token A B
%left A B
%%
S: A S|S B|;
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
