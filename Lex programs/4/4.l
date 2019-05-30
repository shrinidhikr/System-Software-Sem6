%{
#include<stdio.h>
int chars=0,vow=0,num=0,sc=0;
%}
%%
" "    {}
"\n"    {}
[aeiouAEIOU]    {vow++;}
[a-zA-Z]    {chars++;}
[0-9]+    {num++;}
.    {sc++;}
%%
void main()
{
    yyin=fopen("in4.txt","r");
    yylex();

    printf("Consonants: %d\n",chars);
    printf("Vowels: %d\n",vow);
    printf("Numbers: %d\n",num);

    printf("Special Characters: %d\n",sc);
}
