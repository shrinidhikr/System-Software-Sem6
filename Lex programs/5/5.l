%{
     #include <stdio.h>
     int pi=0,ni=0,pf=0,nf=0;
%}
%%
[-][0-9]+    {ni++;}
[+]?[0-9]+    {pi++;}
[-][0-9]*\.[0-9]+    {nf++;}
[+]?[0-9]*\.[0-9]+    {pf++;}
"\n"    {}
" "    {}

%%

void main()
{

 yyin=fopen("in5.txt","r");
 yylex();
 printf("No. of positive integer %d \n",pi);
 printf("No. of negative integer %d \n",ni);
 printf("No. of positive fraction %d \n",pf);
 printf("No. of negative fraction %d \n",nf);
}

