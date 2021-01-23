%{
	#include <stdio.h>
	#include <string.h>
	#include "treenode.h"
	#include "minic_syntax.tab.h"

	int lexicalErrorNum = 0;

	int charPos = 1;

	#define YY_USER_ACTION \
	 yylloc.first_line = yylineno; \
	 yylloc.last_line = yylineno; \
	 yylloc.first_column = charPos; \
	 yylloc.last_column = charPos + yyleng; 
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

ID 			[a-z_A-Z][a-z_A-Z0-9]*

BTYPE 		short|int|long|float|double|char|void
TYPE 		{BTYPE}[*]?
QUALIFIER 	signed|unsigned|static|const
IF  		if 
ELSE        else 
WHILE       while
DO   		do
FOR    		for
CONTINUE    continue 
BREAK  		break
RETURN      return 


DOT			\.
ADD			\+
SUB			-
MULT		\*
DIV			\/
AND			&
OR			\|
NOT 		~
LOGICAND 	&&
LOGICOR		\|\|
LOGICNOT	!
ASSIGNOP	=
COMPARE 	>|<|>=|<=|==|!=

SEMI		;
COMMA		,

LP 			\(
RP 			\)
LB 			\[
RB 			\]
LC 			\{
RC 			\}

COMMENT 	(\/\/.*\n)|(\/\*(.|\n)*\/)


EOL 		\n
SPACE 		[ \t\r\f\v]*

AERROR 		.

%%


{COMMENT}	{ }

{SPACE}     { charPos = charPos + 1; }
{EOL}		{ charPos = 0; }

		
{TYPE}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "TYPE", yytext);
				return TYPE;
			}
{QUALIFIER}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "QUALIFIER", yytext);
				return QUALIFIER;
			}	

{IF}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "IF", NULL);
				return IF;
			}
{ELSE}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ELSE", NULL);
				return ELSE;
			}
{WHILE}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "WHILE", NULL);
				return WHILE;
			}
{DO}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "DO", NULL);
				return DO;
			}
{FOR}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "FOR", NULL);
				return FOR;
			}
{CONTINUE}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "CONTINUE", NULL);
				return CONTINUE;
			}
{BREAK}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "BREAK", NULL);
				return BREAK;
			}
{RETURN}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RETURN", NULL);
				return RETURN;
			}

{ASSIGNOP} 	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ASSIGNOP", NULL);
				return ASSIGNOP;
			}
{COMPARE}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "COMPARE", yytext);
				return COMPARE;
			}
{LP}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LP", NULL);
				return LP;
			}
{RP}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RP", NULL);
				return RP;
			}
{LB}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LB", NULL);
				return LB;
			}
{RB}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RB", NULL);
				return RB;
			}
{LC}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LC", NULL);
				return LC;
			}
{RC}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RC", NULL);
				return RC;
			}
{SEMI}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "SEMI", NULL);
				return SEMI;
			}
{COMMA}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "COMMA", NULL);
				return COMMA;
			}
{DOT}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "DOT", NULL);
				return DOT;
			}

{ADD}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ADD", NULL);
				return ADD;
			}
{SUB}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "SUB", NULL);
				return SUB;
			}
{MULT}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "MULT", NULL);
				return MULT;
			}
{DIV}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "DIV", NULL);
				return DIV;
			}

{AND}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "AND", NULL);
				return AND;
			}
{OR}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "OR", NULL);
				return OR;
			}
{NOT}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "NOT", NULL);
				return NOT;
			}

{LOGICAND}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICAND", NULL);
				return LOGICAND;
			}
{LOGICOR}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICOR", NULL);
				return LOGICOR;
			}
{LOGICNOT}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICNOT", NULL);
				return LOGICNOT;
			}

{ID} 		{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ID", yytext);
				return ID;
           	}

{INTEGER} 	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "INTEGER", yytext);
				return INTEGER;
		  	}
{FLOATING}	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "FLOATING", yytext);
				return FLOATING;
			}
{OCTNUM}	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "OCTNUM", yytext);
				return INTEGER;
			}
{HEXNUM}	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "HEXNUM", yytext);
				return INTEGER;
			}
{STRING}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "STRING", yytext);
				return STRING;
			}
{CHAR}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "CHAR", yytext);
				return CHAR;
			}

{AERROR}	{
				printf("Line %d : %d (Lexical Error) Mysterious characters \"%s\"\n", yylineno, charPos, yytext);
				charPos = charPos + yyleng;
				lexicalErrorNum = lexicalErrorNum + 1;
				return AERROR;
			}
%%

int yywrap()
{
	return 1;
}
