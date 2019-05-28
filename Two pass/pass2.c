#include<stdio.h>
#include<string.h>

void main()
{
	FILE *f1,*f2,*f3,*f4;
	char operand[20],label[20],opcode[20],actoperand[20],tempcode[20],tempval[20],symcode[20],symval[20];
	int len,address,sa;
	f1 = fopen("input2.txt","r");
	f4 = fopen("output2.txt","w");
	
	fscanf(f1,"%X %s %s %s",&address,label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		fprintf(f4,"%X\t%s\t%s\t%s\t-\n",address,label,opcode,operand);
		sa = address;
	}
	
	fscanf(f1,"%X %s %s %s",&address,label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fprintf(f4,"%X\t%s\t%s\t%s\t",address,label,opcode,operand);
		f2 = fopen("optab.txt","r");
		fscanf(f2,"%s %s",tempcode,tempval);
			while(!feof(f2))
			{
				if(strcmp(opcode,tempcode)==0)
				{
					fprintf(f4,"%s",tempval);
					break;
				}
				fscanf(f2,"%s %s",tempcode,tempval);
			}
		fclose(f2);
		
		strcpy(actoperand,"");
		if(operand[strlen(operand)-1]=='X')
		{
			int i=0;
			for(i=0;i<strlen(operand)-2;i++)
			{
				actoperand[i]=operand[i];
			}
			actoperand[i]='\0';
		}
		else
			strcpy(actoperand,operand);
		f3 = fopen("symtab.txt","r");
		fscanf(f3,"%s %s",symcode,symval);
		while(!feof(f3))
		{
			if(strcmp(symcode,actoperand)==0)
			{  
				printf("%s",actoperand);
				int len = strtol(symval,NULL,16);
				if(operand[strlen(operand)-1]=='X')
				{
					len=len+0x8000;
				}
				fprintf(f4,"%X\n",len);
			}
			fscanf(f3,"%s %s",symcode,symval);
		}
		fclose(f3);
		if(strcmp(opcode,"WORD")==0)
		{
			int l = strlen(operand);
			int num = strtol(operand,NULL,16);
			while(l<6)
			{
				fprintf(f4,"0");
				l++;
			}
			fprintf(f4,"%X\n",num);
		}
		if(strcmp(opcode,"BYTE")==0)
		{
			if(operand[0]=='C')
			{
				int i =0;
				for(i=2;i<strlen(operand)-1;i++)
				{
					fprintf(f4,"%02X",operand[i]);
				}
				fprintf(f4,"\n");
			}
			else if(operand[0]=='X')
			{
				char temp[20];
				int i = 0;
				for(i=2;i<strlen(operand)-1;i++)
					fprintf(f4,"%c",operand[i]);
				fprintf(f4,"\n");
			}
		}	
		
		if(strcmp(opcode,"RESW")==0||strcmp(opcode,"RESB")==0)
		{
			fprintf(f4,"-\n");			
		}
		
		fscanf(f1,"%X %s %s %s",&address,label,opcode,operand);
	}
	fprintf(f4,"%X\t%s\t%s\t%s\t\n",address,label,opcode,operand);
	fclose(f1);
	fclose(f4);	
}
