#include<stdio.h>
#include<stdlib.h>

void main()
{
	char c,t;
	int line=0,space=0,word=0,cha=0;
	FILE *f = fopen("hello.txt","r");
	if(f)
	{
		while((c=fgetc(f))!=EOF)
		{
			cha++;
			if(c=='\n'||c==' ')
			{
				if(t!=c)
					word++;
				if(c==' ')
					space++;
				if(c=='\n')
					line++;
			}
			t=c;
		}
	}
	printf("No. of characters: %d\n",cha-line-space);
	printf("No. of lines: %d\n",line);
	printf("No. of spaces: %d\n",space);
	printf("No. of words: %d\n",word);
}
