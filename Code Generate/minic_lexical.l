%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
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
				CreateTreeNode(&(yylval.node), 0, yylineno, "TYPE", yytext, 0);
				return TYPE;
			}
{QUALIFIER}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "QUALIFIER", yytext, 0);
				return QUALIFIER;
			}	

{IF}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "IF", NULL, 0);
				return IF;
			}
{ELSE}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ELSE", NULL, 0);
				return ELSE;
			}
{WHILE}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "WHILE", NULL, 0);
				return WHILE;
			}
{DO}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "DO", NULL, 0);
				return DO;
			}
{FOR}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "FOR", NULL, 0);
				return FOR;
			}
{CONTINUE}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "CONTINUE", NULL, 0);
				return CONTINUE;
			}
{BREAK}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "BREAK", NULL, 0);
				return BREAK;
			}
{RETURN}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RETURN", NULL, 0);
				return RETURN;
			}

{ASSIGNOP} 	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ASSIGNOP", NULL, 0);
				return ASSIGNOP;
			}
{COMPARE}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "COMPARE", yytext, 0);
				return COMPARE;
			}
{LP}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LP", NULL, 0);
				return LP;
			}
{RP}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RP", NULL, 0);
				return RP;
			}
{LB}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LB", NULL, 0);
				return LB;
			}
{RB}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RB", NULL, 0);
				return RB;
			}
{LC}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LC", NULL, 0);
				return LC;
			}
{RC}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "RC", NULL, 0);
				return RC;
			}
{SEMI}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "SEMI", NULL, 0);
				return SEMI;
			}
{COMMA}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "COMMA", NULL, 0);
				return COMMA;
			}
{DOT}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "DOT", NULL, 0);
				return DOT;
			}

{ADD}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ADD", yytext, 0);
				return ADD;
			}
{SUB}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "SUB", yytext, 0);
				return SUB;
			}
{MULT}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "MULT", yytext, 0);
				return MULT;
			}
{DIV}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "DIV", yytext, 0);
				return DIV;
			}

{AND}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "AND", yytext, 0);
				return AND;
			}
{OR}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "OR", yytext, 0);
				return OR;
			}
{NOT}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "NOT", yytext, 0);
				return NOT;
			}

{LOGICAND}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICAND", yytext, 0);
				return LOGICAND;
			}
{LOGICOR}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICOR", yytext, 0);
				return LOGICOR;
			}
{LOGICNOT}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICNOT", yytext, 0);
				return LOGICNOT;
			}

{ID} 		{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "ID", yytext, 0);
				return ID;
           	}

{INTEGER} 	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "INTEGER", yytext, 0);
				yylval.node->value = atoi(yytext);
				return INTEGER;
		  	}
{FLOATING}	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "FLOATING", yytext, 0);
				yylval.node->value = atof(yytext);
				return FLOATING;
			}
{OCTNUM}	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "OCTNUM", yytext, 0);
				return INTEGER;
			}
{HEXNUM}	{	
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "HEXNUM", yytext, 0);
				return INTEGER;
			}
{STRING}	{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "STRING", yytext, 0);
				return STRING;
			}
{CHAR}		{
				charPos = charPos + yyleng;
				CreateTreeNode(&(yylval.node), 0, yylineno, "CHAR", yytext, 0);
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
