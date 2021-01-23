%{
	#include <stdio.h>
	#include <string.h>
	#include "treenode.h"
	#include "minic_syntax.tab.h"

	#define YY_USER_ACTION \
	 yylloc.first_line = yylloc.last_line = yylineno; 
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

{SPACE}     { }
{EOL}		{ }

		
{TYPE}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "TYPE", yytext);
				return TYPE;
			}
{QUALIFIER}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "QUALIFIER", yytext);
				return QUALIFIER;
			}	

{IF}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "IF", NULL);
				return IF;
			}
{ELSE}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "ELSE", NULL);
				return ELSE;
			}
{WHILE}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "WHILE", NULL);
				return WHILE;
			}
{DO}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "DO", NULL);
				return DO;
			}
{FOR}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "FOR", NULL);
				return FOR;
			}
{CONTINUE}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "CONTINUE", NULL);
				return CONTINUE;
			}
{BREAK}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "BREAK", NULL);
				return BREAK;
			}
{RETURN}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "RETURN", NULL);
				return RETURN;
			}

{ASSIGNOP} 	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "ASSIGNOP", NULL);
				return ASSIGNOP;
			}
{COMPARE}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "COMPARE", yytext);
				return COMPARE;
			}
{LP}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "LP", NULL);
				return LP;
			}
{RP}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "RP", NULL);
				return RP;
			}
{LB}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "LB", NULL);
				return LB;
			}
{RB}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "RB", NULL);
				return RB;
			}
{LC}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "LC", NULL);
				return LC;
			}
{RC}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "RC", NULL);
				return RC;
			}
{SEMI}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "SEMI", NULL);
				return SEMI;
			}
{COMMA}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "COMMA", NULL);
				return COMMA;
			}
{DOT}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "DOT", NULL);
				return DOT;
			}

{ADD}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "ADD", NULL);
				return ADD;
			}
{SUB}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "SUB", NULL);
				return SUB;
			}
{MULT}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "MULT", NULL);
				return MULT;
			}
{DIV}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "DIV", NULL);
				return DIV;
			}

{AND}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "AND", NULL);
				return AND;
			}
{OR}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "OR", NULL);
				return OR;
			}
{NOT}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "NOT", NULL);
				return NOT;
			}

{LOGICAND}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICAND", NULL);
				return LOGICAND;
			}
{LOGICOR}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICOR", NULL);
				return LOGICOR;
			}
{LOGICNOT}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "LOGICNOT", NULL);
				return LOGICNOT;
			}

{ID} 		{	
				CreateTreeNode(&(yylval.node), 0, yylineno, "ID", yytext);
				return ID;
           	}

{INTEGER} 	{	
				CreateTreeNode(&(yylval.node), 0, yylineno, "INTEGER", yytext);
				return INTEGER;
		  	}
{FLOATING}	{	
				CreateTreeNode(&(yylval.node), 0, yylineno, "FLOATING", yytext);
				return FLOATING;
			}
{OCTNUM}	{	
				CreateTreeNode(&(yylval.node), 0, yylineno, "OCTNUM", yytext);
				return INTEGER;
			}
{HEXNUM}	{	
				CreateTreeNode(&(yylval.node), 0, yylineno, "HEXNUM", yytext);
				return INTEGER;
			}
{STRING}	{
				CreateTreeNode(&(yylval.node), 0, yylineno, "STRING", yytext);
				return STRING;
			}
{CHAR}		{
				CreateTreeNode(&(yylval.node), 0, yylineno, "CHAR", yytext);
				return CHAR;
			}

{AERROR}	{
				printf("Line %d:(Lexical Error) Mysterious characters \"%s\"\n", yylineno, yytext);
				return AERROR;
			}
%%

int yywrap()
{
	return 1;
}
