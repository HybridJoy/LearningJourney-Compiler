
%{
	#include <stdio.h>
	#include "treenode.h"
	#include <stdarg.h>
	#include <stdlib.h>

	// Syntax mistake number
	int errorNum = 0;
%}

/* declare types */
%union {
	struct treeNode* node;
}

/* declare tokens */
%token <node> TYPE
%token <node> ID
%token <node> INTEGER FLOATING STRING CHAR
%token <node> IF ELSE DO WHILE FOR BREAK CONTINUE RETURN QUALIFIER
%token <node> ADD SUB MULT DIV AND OR NOT ASSIGNOP COMPARE LOGICAND LOGICOR LOGICNOT
%token <node> LP RP LB RB LC RC SEMI COMMA DOT
%token <node> EOL SPACE COMMENT
%token <node> AERROR 

/* declared non-terminals */
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
		  		CreateTreeNode(&$$, 1, @$.first_line, "Program", NULL);
		  		$$->children[0] = $1;
		  	}
		  	root = $$;
		  	if(errorNum == 0)
		  	{
		  		printf("print syntax tree\n");
			  	PrintTreeNode($$, 0);
			  	printf("syntax print finish!\n");
		  	}
		  	else
		  	{
		  		printf("Total Mistake Numbers : %d .\n", errorNum);
		  		printf("please correct the mistake.\n");
		  	}
		}			
		;
CodeDefList : CodeDef CodeDefList
			{
			  	CreateTreeNode(&$$, 1, @$.first_line, "CodeDefList", NULL);
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
			CreateTreeNode(&$$, 1, @$.first_line, "CodeDef", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
		}
	    | TYPE FunDec Compst
	    {
	    	CreateTreeNode(&$$, 1, @$.first_line, "CodeDef", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	    }
	    | TYPE FunDec SEMI
	    {
	    	CreateTreeNode(&$$, 1, @$.first_line, "CodeDef", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	    }
	    // error-1 Declaring Function miss ";"
	    | TYPE FunDec error
	    {
	    	errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ; \"\n", @$.first_line);
	    }	
	   	;
CodeDecList : VarDec
			{
				CreateTreeNode(&$$, 1, @$.first_line, "CodeDecList", NULL);
				$$->children[0] = $1;
			}
	   		| VarDec COMMA CodeDecList
	   		{
	   			CreateTreeNode(&$$, 1, @$.first_line, "CodeDecList", NULL);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
	   		}
	   		;

VarDec : ID
	   {
	   		CreateTreeNode(&$$, 1, @$.first_line, "VarDec", NULL);
			$$->children[0] = $1;
	   }
	   | VarDec LB INTEGER RB
	   {
	   		CreateTreeNode(&$$, 1, @$.first_line, "VarDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
	   }
	   // error-2 Array variable "[ ]" is not number
	   | VarDec LB error RB
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Expected type 'int'\n", @$.first_line);
	   }
	   ;
FunDec : ID LP VarList RP
	   {
	   		CreateTreeNode(&$$, 1, @$.first_line, "FunDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
	   }
	   | ID LP RP
	   {
	   		CreateTreeNode(&$$, 1, @$.first_line, "FunDec", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	   }
	   // error-3 Function missing "("
	   | ID error VarList RP
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ( \"\n", @$.first_line);
	   }
	   | ID error RP
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ( \"\n", @$.first_line);
	   }
	   // error-4 Function missing ")"
	   | ID LP VarList error
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ) \"\n", @$.first_line);
	   }
	   | ID LP error
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ) \"\n", @$.first_line);
	   }
	   // error-5 Wrong Function Name
	   | error LP VarList RP
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Wrong Function Name\n", @$.first_line);
	   }
	   | error LP RP
	   {
		    errorNum = errorNum + 1;
		    printf("Line %d:(Error) Wrong Function Name\n", @$.first_line);
	   }
	   ;
VarList : ParamDec COMMA VarList
		{
			CreateTreeNode(&$$, 1, @$.first_line, "VarList", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
		}
	   	| ParamDec
	   	{
	   		CreateTreeNode(&$$, 1, @$.first_line, "VarList", NULL);
			$$->children[0] = $1;
	   	}
;
ParamDec : TYPE VarDec
		 {
		    CreateTreeNode(&$$,1, @$.first_line,"ParamDec",NULL);
		    $$->children[0] = $1;
		    $$->children[1] = $2;
  	     }
         ;

Compst : LC DefList StmtList RC
	   {
	   		CreateTreeNode(&$$, 1, @$.first_line, "Compst", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
	   }
	   ;
StmtList : Stmt StmtList
		 {
		 	CreateTreeNode(&$$, 1, @$.first_line, "StmtList", NULL);
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
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
	 }
	 | Compst
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
	 } 
	 | RETURN Exp SEMI
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	 }
	 | CONTINUE SEMI
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
	 }
	 | BREAK SEMI 
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
	 }
	 | IF LP Exp RP Stmt 
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
	 }
	 | IF LP Exp RP Stmt ELSE Stmt
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
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
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
	 }
	 | DO Stmt WHILE LP Exp RP
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
			$$->children[3] = $4;
			$$->children[4] = $5;
			$$->children[5] = $6;
	 } 
	 | FOR LP Exp SEMI Exp SEMI Exp RP Stmt
	 {
	 		CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL);
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
	 // error-6 Expression Missing ";"
	 | Exp error
	 {
	 		errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ; \"\n", @$.first_line);
	 }
	 | RETURN Exp error
	 {
	 		errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ; \"\n", @$.first_line);
	 }
	 | CONTINUE error
	 {
	 		errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ; \"\n", @$.first_line);
	 }
	 | BREAK error
	 {
	 		errorNum = errorNum + 1;
		    printf("Line %d:(Error) Missing \" ; \"\n", @$.first_line);
	 }
	 // error-7 Control Statement Missing "("
	 // Consider code refactoring 
	 ;

/*Local Definitions*/
DefList : Def DefList
		{
			CreateTreeNode(&$$, 1, @$.first_line, "DefList", NULL);
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
    	CreateTreeNode(&$$, 1, @$.first_line, "Def", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    // error-8 Not Defination Type 
    | error DecList SEMI
    {
    	errorNum = errorNum + 1;
		printf("Line %d:(Error) Not Defination Type\n", @$.first_line);
    }
    // error-9 Code Missing ";"
    | TYPE DecList error
    {
    	errorNum = errorNum + 1;
		printf("Line %d:(Error) Missing \" ; \"\n", @$.first_line);
    }
    ;
DecList : Dec 
		{
			CreateTreeNode(&$$, 1, @$.first_line, "DecList", NULL);
			$$->children[0] = $1;
		}
	    | Dec COMMA DecList
	    {
	    	CreateTreeNode(&$$, 1, @$.first_line, "DecList", NULL);
			$$->children[0] = $1;
			$$->children[1] = $2;
			$$->children[2] = $3;
	    } 
	    ;
Dec : VarDec
	{
		CreateTreeNode(&$$, 1, @$.first_line, "Dec", NULL);
		$$->children[0] = $1;
	} 
	| VarDec ASSIGNOP Exp
	{
		CreateTreeNode(&$$, 1, @$.first_line, "Dec", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
	}
	// error-10 Not allowed 
	// Consider to solve shift/reduce conflict
	| VarDec error Exp
	{
		errorNum = errorNum + 1;
		printf("Line %d:(Error) Illegal Symbol\n", @$.first_line);
	}
	;

/*Expressions*/
Exp : Exp ASSIGNOP Exp
	{
		CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
	}
    | Exp AND Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp OR Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | NOT Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
    }
    | Exp COMPARE Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp ADD Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp SUB Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp MULT Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp DIV Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | LP Exp RP
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | SUB Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
    } 
    | Exp LOGICAND Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp LOGICOR Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | LOGICNOT Exp
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
    } 
    | ID LP Args RP
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
		$$->children[3] = $4;
    } 
    | ID LP RP 
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | Exp LB Exp RB
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
		$$->children[3] = $4;
    } 
    | Exp DOT ID 
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
    }
    | ID 
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
    }
    | INTEGER 
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
    }
    | FLOATING
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
    }
    | STRING
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
    }
    | CHAR
    {
    	CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL);
		$$->children[0] = $1;
    }
    // error-11 a = array[10] [ ] is not int number
    | Exp LB error RB
    {
    	 errorNum = errorNum + 1;
		 printf("Line %d:(Error) Expected type 'int'\n", @$.first_line);
    }
    ;
Args : Exp COMMA Args 
	 {
    	CreateTreeNode(&$$, 1, @$.first_line, "Args", NULL);
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;
     }
     | Exp 
     {
     	CreateTreeNode(&$$, 1, @$.first_line, "Args", NULL);
		$$->children[0] = $1;
     }
     ;
%%

int yyerror(char* msg) 
{
   // printf("%s\n", msg);
    return 0;
}

int main()
{
    yyparse();
    return 0;
}