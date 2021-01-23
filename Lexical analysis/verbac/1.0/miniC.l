%{
	#include <stdio.h>
	#include <string.h>
	#define Type "short" || "int" || "long" || "float" || "double" || "char" || "void"

	#define MAX_NUM 50

	struct LexicalError
	{
		int line;
		int charPos;
		int words;
		char * reason;
	}LexError[MAX_NUM];

	enum NodeType{
		INTEGER = "[INTEGER]",
		FLOATING = "[FLOATING]",
		VARINAME = "[VARINAME]",
		TYPE = "[TYPE]",
		QUALIFIER = "[QUALIFIER]",
		KEYWORD = "[KEYWORD]",
		OPT = "[OPT]",
		ASSIGN = "[ASSIGN]",
		COMPARE = "[COMPARE]",
		EOL = "[EOL]"
	};

	struct GramTreeNode
	{
		NodeType type;
		char * name;
	}GTN[MAX_NUM * 3];

	int chars = 0;
	int words = 0;
	int lines = 0;

	int errorCount = 0;
	int variNum = 0;
	int nodeNum = 0;

	char * vari[MAX_NUM];
	char * lastchar;
%}

DIGIT [0-9]
INTEGER {DIGIT}+
FLOATING {DIGIT}+\.{DIGIT}*
VARINAME [a-z_A-Z][a-z_A-Z0-9]*
TYPE short | int | long | float | double | char | void
QUALIFIER signed | unsigned | const | static
KEYWORD if | else | for | while | do | switch | case
OPT + | - | * | /
ASSIGN =
COMPARE > | < | >= | <= | ==
EOL \n
AERROR .

%%
{EOL}	{chars = 0; words = 0; lines++;
		if(lastchar != (";" || "{" || ")"))
		{
			LexError[errorCount].line = lines;
			LexError[errorCount].charPos = chars;
			LexError[errorCount].words = words;
			LexError[errorCount].reason = "reduce some symbol";
			errorCount++;
		}}
{INTEGER} {chars += strlen(yytext);words++;lastchar = yytext;}
{VARINAME} {chars += strlen(yytext);words++;lastchar = yytext;
           int flag = 0;
           int i = 0;
           for(i = 0;i < variNum;i++)
           {
           		if(vari[i] == yytext)
           		{
           			flag = 1;
           			break;
           		}
           }
           if(flag == 0)
           {
           		if(lastchar != Type)
           		{
           			LexError[errorCount].line = lines;
					LexError[errorCount].charPos = chars;
					LexError[errorCount].words = words;
					LexError[errorCount].reason = "variable is not declared";
					errorCount++;
           		}
           		else
           		{
           			vari[variNum] = yytext;
           			variNum++;
           		}
           }
           lastchar = yytext;
           }

%%

int main()
{
	while(yylex())
	{

	}

	int i = 0;
	for(i = 0;i < nodeNum;i++)
	{
		printf("%3s  %3s\n", GTN[i].type, GTN[i].name );
	}

	printf("ERROR INFORMATION\n");
	for(i = 0;i < errorCount;i++)
	{
		//printf("Error(%d)---- line : %d  pos : %d  reason : %s\n", i + 1，LexError[i].line, LexError[i].charPos, LexError[i].reason);
		printf("Error -- %d  ", i + 1);
		printf("Line : %d  ", LexError[i].line);
		printf("Pos : %d  ", LexError[i].charPos);
		printf("Reason : %s\n", LexError[i].reason);
	}
	return 0;
}

int yywrap()
{
	return 1;
}

