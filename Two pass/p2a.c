//Pass-2 of two-pass assembler
#include<stdio.h>
#include<string.h>

void main()
{
	FILE *f1,*f2,*f3,*f4;
	char label[20],opcode[20],operand[20];
	int address,sa,len,i;
	f1=fopen("input.txt","r");
	f4=fopen("output.txt","w");
	fscanf(f1,"%x %s %s %s",&address,label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		fprintf(f4,"%X\t%s\t%s\t%s\t-\n",address,label,opcode,operand);
		sa=address;
	}
	
	fscanf(f1,"%x %s %s %s",&address,label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fprintf(f4,"%X\t%s\t%s\t%s\t",address,label,opcode,operand);
		f2=fopen("optab.txt","r");
		char tempcode[20],tempval[20];
		fscanf(f2,"%s %s",tempcode,tempval);
		while(!feof(f2))
		{
			if(strcmp(opcode,tempcode)==0)
			{
				fprintf(f4,"%s",tempval);
				break;
			}
			else
				fscanf(f2,"%s %s",tempcode,tempval);
		}
		fclose(f2);
		char actoperand[20];
		strcpy(actoperand,"");
		if(operand[strlen(operand)-1]=='X')
		{
			int i;
			for(i=0;i<strlen(operand)-2;i++)
				actoperand[i]=operand[i];
			actoperand[i]='\0';
		}
		else
			strcpy(actoperand,operand);
		f3=fopen("symtab.txt","r");
		char symcode[20],symval[20];
		fscanf(f3,"%s %s",symcode,symval);
		while(!feof(f3))
		{
			if(strcmp(actoperand,symcode)==0)
			{
				
				int lval=strtol(symval,NULL,16);
				if(operand[strlen(operand)-1]=='X')
					lval=lval+0x8000;
				fprintf(f4,"%X\n",lval);
				break;
			}
			else
				fscanf(f3,"%s %s",symcode,symval);
			
		}
		fclose(f3);

		if(strcmp(opcode,"WORD")==0)
		{
			int val=strtol(operand,NULL,16);
			char num[10];
			sprintf(num,"%X",val);
			int l=strlen(num);
			while(l<6)
			{
				fprintf(f4,"0");
				l++;
			}
			fprintf(f4,"%s\n",num);
		}

		if(strcmp(opcode,"BYTE")==0)
		{
			if(operand[0]=='X')
			{
				for(i=2;i<strlen(operand)-1;i++)
					fprintf(f4,"%c",operand[i]);
				fprintf(f4,"\n");
			}
			else if(operand[0]=='C')
			{

				for(i=2;i<strlen(operand)-1;i++)
				{
					fprintf(f4,"%02X",operand[i]);
				}
				fprintf(f4,"\n");
			}
		}

		if(strcmp(opcode,"RESB")==0||strcmp(opcode,"RESW")==0)
			fprintf(f4,"-\n");		

		fscanf(f1,"%x %s %s %s",&address,label,opcode,operand);

	}
	fprintf(f4,"%X\t%s\t%s\t%s\n",address,label,opcode,operand);

	len=address-sa;
	
	printf("\nOutput File generated as output.txt\n");	

	fclose(f1);
	fclose(f4);

}
