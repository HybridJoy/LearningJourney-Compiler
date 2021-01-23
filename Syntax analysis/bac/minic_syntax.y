
%{
	#include <stdio.h>
	#include "treeNode.h"
	#include <stdarg.h>
	extern int yylineno;
	int yyerrornum = 0;
%}

/* declare types */
%union {
	struct treeNode* node;
}

/* declare tokens */
%token <node> TYPE STRUCT
%token <node> ID
%token <node> INTEGER FLOATING STRING CHAR
%token <node> IF ELSE DO WHILE FOR BREAK CONTINUE RETURN
%token <node> ADD SUB MULT DIV AND OR NOT ASSIGNOP COMPARE LOGICAND LOGICOR LOGICNOT
%token <node> LP RP LB RB LC RC SEMI COMMA DOT
%token <node> EOL SPACE COMMENT
%token <node> AERROR QUALIFIER

/* declare non-terminals */
%type <node> Program CodeDefList CodeDef CodeDecList 
%type <node> Specifier
%type <node> VarDec FunDec VarList ParamDec Compst
%type <node> StmtList Stmt DefList Def DecList Dec 
%type <node> Exp Args


/* priority */
%left  COMMA
%right ASSIGNOP
%left  LOGICOR LOGICAND 
%left  COMPARE
%left  AND OR
%left  ADD SUB
%left  MULT DIV
%right NOT
%right LOGICNOT
%left  LP RP 
%left  LB RB 
%left  DOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

Program : CodeDefList			
		;
CodeDefList : CodeDef CodeDefList
			| /* empty */
		    ;
CodeDef : TYPE CodeDecList SEMI
	    | TYPE FunDec Compst
	    | TYPE FunDec SEMI	
	   	;
CodeDecList : VarDec
	   		| VarDec COMMA CodeDecList
	   		;

VarDec : ID
	   | VarDec LB INTEGER RB
	   ;
FunDec : ID LP VarList RP
	   | ID LP RP
	   ;
VarList : ParamDec COMMA VarList
	   	| ParamDec
	   	;
ParamDec : TYPE VarDec
		 ;

Compst : LC DefList StmtList RC
	   ;
StmtList : Stmt StmtList
	     | /*empty*/
	     ;
Stmt : Exp SEMI 
	 | Compst
	 | RETURN Exp SEMI
	 | CONTINUE SEMI
	 | BREAK SEMI 
	 | IF LP Exp RP Stmt 
	 | IF LP Exp RP Stmt ELSE Stmt
	 | WHILE LP Exp RP Stmt
	 | DO Stmt WHILE LP Exp RP
	 | FOR LP Exp SEMI Exp SEMI Exp RP Stmt
	 ;

/* Local Definitions */
DefList : Def DefList
	    | /* empty */
	    ;
Def : TYPE DecList SEMI 
	;
    
DecList : Dec 
	    | Dec COMMA DecList
	    ;
Dec : VarDec
	| VarDec ASSIGNOP Exp
	;

/* Expressions */
Exp : Exp ASSIGNOP Exp
    | Exp AND Exp
    | Exp OR Exp
    | NOT Exp
    | Exp COMPARE Exp
    | Exp ADD Exp
    | Exp SUB Exp
    | Exp MULT Exp
    | Exp DIV Exp
    | LP Exp RP
    | SUB Exp
    | Exp LOGICAND Exp
    | Exp LOGICOR Exp
    | LOGICNOT Exp
    | ID LP Args RP
    | ID LP RP 
    | Exp LB Exp RB
    | Exp DOT ID 
    | ID 
    | INTEGER 
    | FLOATING
    | STRING
    | CHAR
    ;
Args : Exp COMMA Args 
     | Exp 
     ;
%%

int main()
{
	yyparse();
	return 0;
}

yyerror(char* msg) {
    if(yyerrornum > 0)
        exit(0);
    
    //printf("Error type B at Line %d: %s\n",yylineno, msg);
}