%{
	#include <stdio.h>
	#include <string.h>

	#define MAX_NUM 100

	struct LexicalError
	{
		int line;
		int charPos;
		char * reason;
	}LexError[MAX_NUM];

	enum NodeType{
		INTEGER,
		FLOATING,
		OCTNUM,
		HEXNUM,
		STRING,
		CHAR,
		VARINAME,
		TYPE,
		QUALIFIER,
		KEYWORD,
		ARIOPT,
		BITOPT,
		ASSIGN,
		COMPARE,
		LOGIC,
		BRACKET,
		SPLITSYMBOL,
		EOL
	};

	struct GramTreeNode
	{
		int type;
		char * name;
	}GTN[MAX_NUM * 10];

	int chars = 0;

	int errorCount = 0;
	int nodeNum = 0;
%}

%option yylineno

DIGIT 		[0-9]
EXP			[e][\+-]?{DIGIT}+
INTEGER 	([\+-]?[1-9]{DIGIT}*|0){EXP}?
FLOATING 	({INTEGER}[\.]{DIGIT}*)({EXP}|f)?
OCTNUM		[0][0-7]+
HEXNUM		[0][Xx][0-9a-fA-F]+

STRING 		["][^"]*["]
CHAR 		['][^'][']

VARINAME 	[a-z_A-Z][a-z_A-Z0-9]*

BTYPE 		short|int|long|float|double|char|void
TYPE 		{BTYPE}[*]?
QUALIFIER 	signed|unsigned|static|const
KEYWORD 	if|else|for|while|do|switch|case|break|continue|return

DOT			\.
ARIOPT 		\+|-|\*|\/|%|(\+\+)|(\-\-)
BITOPT 		&|\||~|^|<<|>>
ASSIGN 		=|(\+=)|(-=)|(\*=)|(\/=)|(%=)|(>>=)|(<<=)|(&=)|(^=)|(\|=)
COMPARE 	>|<|>=|<=|==|!=
LOGIC		&&|\|\||!

EOL 		\n
SPACE 		[ \t\r\f\v]*
BRACKET 	\{|\}|\[|\]|\(|\)
SPLITSYMBOL ,|;

COMMENT 	(\/\/.*\n)|(\/\*(.|\n)*\/)

ERRORVARI	{DIGIT}+([^ ;)])*

AERROR 		.


%%

{COMMENT}	{}

{SPACE}     {}
{EOL}		{	
				chars = 0;
				GTN[nodeNum].type = EOL;
				GTN[nodeNum].name = (char *)malloc(1);
				strcpy(GTN[nodeNum].name," ");
				nodeNum++;
			}
{BRACKET}	{
				chars += strlen(yytext);
				GTN[nodeNum].type = BRACKET;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{SPLITSYMBOL}	{
					chars += strlen(yytext);
					GTN[nodeNum].type = SPLITSYMBOL;
					GTN[nodeNum].name = (char *)malloc(strlen(yytext));
					strcpy(GTN[nodeNum].name,yytext);
					nodeNum++;
			}
{INTEGER} 	{	
				chars += strlen(yytext);
		  	 	GTN[nodeNum].type = INTEGER;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
		  	}
{FLOATING}	{	
				chars += strlen(yytext);
				GTN[nodeNum].type = FLOATING;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{OCTNUM}	{	
				chars += strlen(yytext);
				GTN[nodeNum].type = OCTNUM;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{HEXNUM}	{	
				chars += strlen(yytext);
				GTN[nodeNum].type = HEXNUM;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}			
{TYPE}		{
				chars += strlen(yytext);
				GTN[nodeNum].type = TYPE;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{QUALIFIER}	{
				chars += strlen(yytext);
				GTN[nodeNum].type = QUALIFIER;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{KEYWORD} 	{
				chars += strlen(yytext);
				GTN[nodeNum].type = KEYWORD;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{VARINAME} 	{	
				chars += strlen(yytext);
				GTN[nodeNum].type = VARINAME;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
           	}
{ARIOPT}	{
				chars += strlen(yytext);
				GTN[nodeNum].type = ARIOPT;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{BITOPT}	{
				chars += strlen(yytext);
				GTN[nodeNum].type = BITOPT;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{ASSIGN} 	{
				chars += strlen(yytext);
				GTN[nodeNum].type = ASSIGN;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{COMPARE}	{
				chars += strlen(yytext);
				GTN[nodeNum].type = COMPARE;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{LOGIC}		{
				chars += strlen(yytext);
				GTN[nodeNum].type = LOGIC;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{STRING}	{
				chars += strlen(yytext);
				GTN[nodeNum].type = STRING;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{CHAR}		{
				chars += strlen(yytext);
				GTN[nodeNum].type = CHAR;
				GTN[nodeNum].name = (char *)malloc(strlen(yytext));
				strcpy(GTN[nodeNum].name,yytext);
				nodeNum++;
			}
{ERRORVARI}	{
				chars += strlen(yytext);
				LexError[errorCount].line = yylineno;
				LexError[errorCount].charPos = chars;
				LexError[errorCount].reason = "invalid variable name";
				errorCount++;
			}
{AERROR}	{
				chars += strlen(yytext);
				LexError[errorCount].line = yylineno;
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
			case OCTNUM:
				printf("[OCTNUM]  ");
				break;
			case HEXNUM:
				printf("[HEXNUM]  ");
				break;
			case STRING:
				printf("[STRING]  ");
				break;
			case CHAR:
				printf("[CHAR]  ");
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
		printf("\t%s\n",GTN[i].name);
	}

	printf("\nERROR INFORMATION\n");
	for(i = 0;i < errorCount;i++)
	{
		printf("Error -- %2d  ", i + 1);
		printf("Line : %2d  ", LexError[i].line);
		printf("Pos : %2d  ", LexError[i].charPos);
		printf("Reason : %s\n", LexError[i].reason);
	}
	return 0;
}

int yywrap()
{
	return 1;
}
