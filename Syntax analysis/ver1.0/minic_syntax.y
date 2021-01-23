
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
%token <node> TYPE 
%token <node> ID
%token <node> INTEGER FLOATING STRING CHAR
%token <node> IF ELSE DO WHILE FOR BREAK CONTINUE RETURN
%token <node> ADD SUB MULT DIV AND OR NOT ASSIGNOP COMPARE LOGICAND LOGICOR LOGICNOT
%token <node> LP RP LB RB LC RC SEMI COMMA DOT
%token <node> EOL SPACE COMMENT
%token <node> AERROR QUALIFIER

/* declare non-terminals */
%type <node> Program CodeDefList CodeDef CodeDecList 
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
		{
		  	if($1 == NULL)
		  	{
		  		$$ = NULL;
		  	}
		  	else
		  	{
		  		CreateTreeNode(&$$, 1, yylineno, "Program", NULL);
		  		$$->children[0] = $1;
		  	}
		  	root = $$;
		  	printf("print syntax tree\n");
		  	PrintTreeNode($$, 0);
		  	printf("syntax print finish!\n");
		}			
		;
CodeDefList : CodeDef CodeDefList
			{
			  	CreateTreeNode(&$$, 1, yylineno, "CodeDefList", NULL);
			  	$$->children[0] = $1;
			  	$$->children[1] = $2;
			}
			| /* empty */
			{
				$$ = NULL;
			}
		    ;
CodeDef : TYPE CodeDecList SEMI
		{
			CreateTreeNode(&$$, 1, yylineno, "CodeDef", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
		}
	    | TYPE FunDec Compst
	    {
	    	CreateTreeNode(&$$, 1, yylineno, "CodeDef", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	    }	
	   	;
CodeDecList : VarDec
			{
				CreateTreeNode(&$$, 1, yylineno, "CodeDecList", NULL);
				$$->children[0] = $1;
			}
	   		| VarDec COMMA CodeDecList
	   		{
	   			CreateTreeNode(&$$, 1, yylineno, "CodeDecList", NULL);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
	   		}
	   		;


VarDec : ID
	   {
	   		CreateTreeNode(&$$, 1, yylineno, "VarDec", NULL);
			$$->children[0] = $1;
	   }
	   | VarDec LB INTEGER RB
	   {
	   		CreateTreeNode(&$$, 1, yylineno, "VarDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
	   }
	   ;
FunDec : ID LP VarList RP
	   {
	   		CreateTreeNode(&$$, 1, yylineno, "FunDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
	   }
	   | ID LP RP
	   {
	   		CreateTreeNode(&$$, 1, yylineno, "FunDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	   }
	   ;
VarList : ParamDec COMMA VarList
		{
			CreateTreeNode(&$$, 1, yylineno, "VarList", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
		}
	   	| ParamDec
	   	{
	   		CreateTreeNode(&$$, 1, yylineno, "VarList", NULL);
			$$->children[0] = $1;
	   	}
	   	;
ParamDec : TYPE VarDec
		 {
		 	CreateTreeNode(&$$, 1, yylineno, "ParamDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
		 }
		 ;

Compst : LC DefList StmtList RC
	   {
	   		CreateTreeNode(&$$, 1, yylineno, "Compst", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
	   }
	   ;
StmtList : Stmt StmtList
		 {
		 	CreateTreeNode(&$$, 1, yylineno, "StmtList", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
		 }
	     | /*empty*/
	     {
	     	$$ = NULL;
	     }
	     ;
Stmt : Exp SEMI 
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
	 }
	 | Compst
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
	 } 
	 | RETURN Exp SEMI
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	 }
	 | CONTINUE SEMI
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
	 }
	 | BREAK SEMI 
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
	 }
	 | IF LP Exp RP Stmt 
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
	 }
	 | IF LP Exp RP Stmt ELSE Stmt
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
			$$->children[5] = $6;
			$$->children[6] = $7;
	 } 
	 | WHILE LP Exp RP Stmt
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
	 }
	 | DO Stmt WHILE LP Exp RP
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
			$$->children[5] = $6;
	 } 
	 | FOR LP Exp SEMI Exp SEMI Exp RP Stmt
	 {
	 		CreateTreeNode(&$$, 1, yylineno, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
			$$->children[5] = $6;
			$$->children[6] = $7;
			$$->children[7] = $8;
			$$->children[8] = $9;
	 }
	 ;

/*Local Definitions*/
DefList : Def DefList
		{
			CreateTreeNode(&$$, 1, yylineno, "DefList", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
		}
	    | /* empty */
	    {
	    	$$ = NULL;
	    }
	    ;
Def : TYPE DecList SEMI 
    {
    	CreateTreeNode(&$$, 1, yylineno, "Def", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
	;
    
DecList : Dec 
		{
			CreateTreeNode(&$$, 1, yylineno, "DecList", NULL);
			$$->children[0] = $1;
		}
	    | Dec COMMA DecList
	    {
	    	CreateTreeNode(&$$, 1, yylineno, "DecList", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	    } 
	    ;
Dec : VarDec
	{
		CreateTreeNode(&$$, 1, yylineno, "Dec", NULL);
		$$->children[0] = $1;
	} 
	| VarDec ASSIGNOP Exp
	{
		CreateTreeNode(&$$, 1, yylineno, "Dec", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
	} 
	;

/*Expressions*/
Exp : Exp ASSIGNOP Exp
	{
		CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
	}
    | Exp AND Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp OR Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | NOT Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
    }
    | Exp COMPARE Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp ADD Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp SUB Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp MULT Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp DIV Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | LP Exp RP
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | SUB Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
    } 
    | Exp LOGICAND Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp LOGICOR Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | LOGICNOT Exp
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
    } 
    | ID LP Args RP
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
		$$->children[3] = $4;
    } 
    | ID LP RP 
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp LB Exp RB
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
		$$->children[3] = $4;
    } 
    | Exp DOT ID 
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | ID 
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
    }
    | INTEGER 
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
    }
    | FLOATING
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
    }
    | STRING
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
    }
    | CHAR
    {
    	CreateTreeNode(&$$, 1, yylineno, "Exp", NULL);
		$$->children[0] = $1;
    }
    ;
Args : Exp COMMA Args 
	 {
    	CreateTreeNode(&$$, 1, yylineno, "Args", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
     }
     | Exp 
     {
     	CreateTreeNode(&$$, 1, yylineno, "Args", NULL);
		$$->children[0] = $1;
     }
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