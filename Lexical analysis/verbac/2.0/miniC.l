%{
	#include <stdio.h>
	#include <string.h>

	#define MAX_NUM 50

	struct LexicalError
	{
		int line;
		int charPos;
		char * reason;
	}LexError[MAX_NUM];

	enum NodeType{
		INTEGER,
		FLOATING,
		VARINAME,
		TYPE,
		QUALIFIER,
		KEYWORD,
		ARIOPT,
		BITOPT,
		ASSIGN,
		COMPARE,
		LOGIC,
		SPACE,
		BRACKET,
		SPLITSYMBOL,
		EOL
	};

	struct GramTreeNode
	{
		int type;
		char * name;
	}GTN[MAX_NUM * 3];

	int chars = 0;
	int words = 0;
	int lines = 1;

	int errorCount = 0;
	int nodeNum = 0;
%}

DIGIT [0-9]
INTEGER {DIGIT}+
FLOATING {DIGIT}+\.{DIGIT}*
VARINAME [a-z_A-Z][a-z_A-Z0-9]*
ERRORVARI [0-9].+

TYPE short|int|long|float|double|char|void
QUALIFIER signed|unsigned|static|const
KEYWORD if|else|for|while|do|switch|case|break|continue|return

ARIOPT \+|-|\*|\/|%
BITOPT &|\||~|^|<<|>>
ASSIGN =
COMPARE >|<|>=|<=|==|!=
LOGIC	&&|\|\||!

EOL \n
SPACE [ \t\r]*
BRACKET \{|\}|\[|\]|\(|\)
SPLITSYMBOL ,|;
AERROR .

%%
{SPACE}     {}
{EOL}		{	
				chars = 0; words++; lines++;
				GTN[nodeNum].type = EOL;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{BRACKET}	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = BRACKET;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(yytext,GTN[nodeNum].name);
				nodeNum++;
			}
{SPLITSYMBOL}	{
					chars += strlen(yytext); words++;
					GTN[nodeNum].type = SPLITSYMBOL;
					GTN[nodeNum].name = yytext;
					nodeNum++;
			}
{INTEGER} 	{	
				chars += strlen(yytext); words++;
		  	 	GTN[nodeNum].type = INTEGER;
				GTN[nodeNum].name = yytext;
				nodeNum++;
		  	}
{FLOATING}	{	
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = FLOATING;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{TYPE}		{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = TYPE;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{QUALIFIER}	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = QUALIFIER;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{KEYWORD} 	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = KEYWORD;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{VARINAME} 	{	
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = VARINAME;
				GTN[nodeNum].name = yytext;
				nodeNum++;           
				printf("%s\n", yytext);
           	}
{ARIOPT}	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = ARIOPT;
				strcpy(yytext,GTN[nodeNum].name);
				nodeNum++;
			}
{BITOPT}	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = BITOPT;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{ASSIGN} 	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = ASSIGN;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{COMPARE}	{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = COMPARE;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{LOGIC}		{
				chars += strlen(yytext); words++;
				GTN[nodeNum].type = LOGIC;
				GTN[nodeNum].name = yytext;
				nodeNum++;
			}
{ERRORVARI}	{
				chars += strlen(yytext); words++;
				LexError[errorCount].line = lines;
				LexError[errorCount].charPos = chars;
				LexError[errorCount].reason = "invalid variable name";
				errorCount++;
			}
{AERROR}	{
				chars += strlen(yytext); words++;
				LexError[errorCount].line = lines;
				LexError[errorCount].charPos = chars;
				LexError[errorCount].reason = "invalid character";
				errorCount++;
			}
%%

int main()
{
	yylex();
	int i = 0;
	for(i = 0;i < nodeNum;i++)
	{
		switch(GTN[i].type)
		{
			case INTEGER:
				printf("[INTEGER]  ");
				break;
			case FLOATING:
				printf("[FLOATING]  ");
				break;
			case VARINAME:
				printf("[VARINAME]  ");
				break;
			case TYPE:
				printf("[TYPE]  ");
				break;
			case QUALIFIER:
				printf("[QUALIFIER]  ");
				break;
			case KEYWORD:
				printf("[KEYWORD]  ");
				break;
			case ARIOPT:
				printf("[ARIOPT]  ");
				break;
			case BITOPT:
				printf("[BITOPT]  ");
				break;
			case ASSIGN:
				printf("[ASSIGN]  ");
				break;
			case COMPARE:
				printf("[COMPARE]  ");
				break;
			case LOGIC:
				printf("[LOGIC]  ");
				break;
			case BRACKET:
				printf("[BRACKET]  ");
				break;
			case SPLITSYMBOL:
				printf("[SPLITSYMBOL]  ");
				break;
			case EOL:
				printf("[EOL]  ");
				break;
		}
		printf("%s\n",GTN[i].name);
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
