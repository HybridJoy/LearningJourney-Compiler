%{
	#include <stdio.h>
	#include "treenode.h"
	#include "symboltable.h"
	#include "generatecode.h"
	#include <stdarg.h>
	#include <stdlib.h>

	// Syntax error number
	int syntaxErrorNum = 0;

	// Lexical error number
	extern int lexicalErrorNum;

	// 是否输出语法树
	int isPrintSyntaxTree = 0;
	
	// 是否输出符号表
	int isPrintSymbolTable = 0;

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
							CreateTreeNode(&$$, 1, @$.first_line, "Program", NULL, 1);
							$$->children[0] = $1;
						}
						root = $$;

						DoTheAfterSyntax();
				}			
				;
CodeDefList : CodeDef CodeDefList
						{
								CreateTreeNode(&$$, 1, @$.first_line, "CodeDefList", NULL, 2);
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
						CreateTreeNode(&$$, 1, @$.first_line, "CodeDef", NULL, 3);
						$$->children[0] = $1;
						$$->children[1] = $2;
						$$->children[2] = $3;
				}
				| TYPE FunDec Compst
				{
						CreateTreeNode(&$$, 1, @$.first_line, "CodeDef", NULL, 3);
						$$->children[0] = $1;
						$$->children[1] = $2;
						$$->children[2] = $3;
				}
				| TYPE FunDec SEMI
				{
						CreateTreeNode(&$$, 1, @$.first_line, "CodeDef", NULL, 3);
						$$->children[0] = $1;
						$$->children[1] = $2;
						$$->children[2] = $3;
				}
				// error-1 Declaring Function miss ";"
				| TYPE FunDec error
				{
						syntaxErrorNum = syntaxErrorNum + 1;
						printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", @$.first_line, @$.last_column);
						// make the syntax analysis to the normal state 
						yyerrok;
				}	
				;
CodeDecList : VarDec
						{
								CreateTreeNode(&$$, 1, @$.first_line, "CodeDecList", NULL, 1);
								$$->children[0] = $1;
						}
						| VarDec COMMA CodeDecList
						{
								CreateTreeNode(&$$, 1, @$.first_line, "CodeDecList", NULL, 3);
								$$->children[0] = $1;
								$$->children[1] = $2;
								$$->children[2] = $3;
						}
						;

VarDec : ID
			{
					CreateTreeNode(&$$, 1, @$.first_line, "VarDec", NULL, 1);
					$$->children[0] = $1;
			}
			| VarDec LB INTEGER RB
			{
					CreateTreeNode(&$$, 1, @$.first_line, "VarDec", NULL, 4);
					$$->children[0] = $1;
					$$->children[1] = $2;
					$$->children[2] = $3;
					$$->children[3] = $4;
			}
		 	| VarDec ASSIGNOP Exp
			{
					CreateTreeNode(&$$, 1, @$.first_line, "VarDec", NULL, 3);
					$$->children[0] = $1;
					$$->children[1] = $2;
					$$->children[2] = $3;
			}
			// error-2 Array variable "[ ]" is not number
			| VarDec LB error RB
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Expected type 'int'\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			;
FunDec : ID LP VarList RP
			{
					CreateTreeNode(&$$, 1, @$.first_line, "FunDec", NULL, 4);
					$$->children[0] = $1;
					$$->children[1] = $2;
					$$->children[2] = $3;
					$$->children[3] = $4;
			}
			| ID LP RP
			{
					CreateTreeNode(&$$, 1, @$.first_line, "FunDec", NULL, 3);
					$$->children[0] = $1;
					$$->children[1] = $2;
					$$->children[2] = $3;
			}
			// error-3 Function missing "("
			| ID error VarList RP
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			| ID error RP
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			// error-4 Function missing ")"
			| ID LP VarList error
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			| ID LP error
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			// error-5 Wrong Function Name
			| error LP VarList RP
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Wrong Function Name\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			| error LP RP
			{
					syntaxErrorNum = syntaxErrorNum + 1;
					printf("Line %d : %d (Syntax Error) Wrong Function Name\n", @$.first_line, @$.last_column);
					// make the syntax analysis to the normal state 
					yyerrok;
			}
			;
VarList : ParamDec COMMA VarList
				{
						CreateTreeNode(&$$, 1, @$.first_line, "VarList", NULL, 3);
						$$->children[0] = $1;
						$$->children[1] = $2;
						$$->children[2] = $3;
				}
				| ParamDec
				{
						CreateTreeNode(&$$, 1, @$.first_line, "VarList", NULL, 1);
						$$->children[0] = $1;
				}
;
ParamDec : TYPE VarDec
		 		{
						CreateTreeNode(&$$,1, @$.first_line, "ParamDec", NULL, 2);
						$$->children[0] = $1;
						$$->children[1] = $2;
				}
				;

Compst : LC DefList StmtList RC
			{
					CreateTreeNode(&$$, 1, @$.first_line, "Compst", NULL, 4);
					$$->children[0] = $1;
					$$->children[1] = $2;
					$$->children[2] = $3;
					$$->children[3] = $4;
			}
			// many shift/reduce conflicts reduce/reduce conflicts
			// //error-6 code segment Missing "{"
			// | error DefList StmtList RC
			// {
			// 		syntaxErrorNum = syntaxErrorNum + 1;
			// 		printf("Line %d : %d (Syntax Error) Missing \" { \"\n", @$.first_line);
			//   // make the syntax analysis to the normal state 
			//   yyerrok;
			// }
			// //error-7 code segment Missing "}"
			// | error DefList StmtList RC
			// {
			// 		syntaxErrorNum = syntaxErrorNum + 1;
			// 		printf("Line %d : %d (Syntax Error) Missing \" } \"\n", @$.first_line);
			//   // make the syntax analysis to the normal state 
			//   yyerrok;
			// }
	   	;
StmtList : Stmt StmtList
				{
						CreateTreeNode(&$$, 1, @$.first_line, "StmtList", NULL, 2);
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
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 2);
				$$->children[0] = $1;
				$$->children[1] = $2;
		}
		| Compst
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 1);
				$$->children[0] = $1;
		} 
		| RETURN Exp SEMI
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
		}
		| CONTINUE SEMI
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 2);
				$$->children[0] = $1;
				$$->children[1] = $2;
		}
		| BREAK SEMI 
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 2);
				$$->children[0] = $1;
				$$->children[1] = $2;
		}
		| IF LP Exp RP Stmt 
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 5);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->children[3] = $4;
				$$->children[4] = $5;
		}
		| IF LP Exp RP Stmt ELSE Stmt
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 7);
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
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 5);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->children[3] = $4;
				$$->children[4] = $5;
		}
		| DO Stmt WHILE LP Exp RP
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 6);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->children[3] = $4;
				$$->children[4] = $5;
				$$->children[5] = $6;
		} 
		| FOR LP Exp SEMI Exp SEMI Exp RP Stmt
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Stmt", NULL, 9);
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
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| RETURN Exp error
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| CONTINUE error
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| BREAK error
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		// error-7 Control Statement Missing "("
		// Consider code refactoring (Not need)
		| IF error Exp RP Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| IF error Exp RP Stmt ELSE Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| WHILE error Exp RP Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| DO Stmt WHILE error Exp RP
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| FOR error Exp SEMI Exp SEMI Exp RP Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		// error-8 Control Statement Missing ")"
		| IF LP Exp error Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		// there is a shift/reduce conflicts(find the reason)
		// | IF LP Exp error Stmt ELSE Stmt
		// {
		// 		syntaxErrorNum = syntaxErrorNum + 1;
		//     printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line);
		//     // make the syntax analysis to the normal state 
		//     yyerrok;
		// }
		| WHILE LP Exp error Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| DO Stmt WHILE LP Exp error
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		| FOR LP Exp SEMI Exp SEMI Exp error Stmt
		{
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
		;

/*Local Definitions*/
DefList : Def DefList
				{
						CreateTreeNode(&$$, 1, @$.first_line, "DefList", NULL, 2);
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
    		CreateTreeNode(&$$, 1, @$.first_line, "Def", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    // error-9 Not Defination Type 
    | error DecList SEMI
    {
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Not Defination Type\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
    }
    // error-10 Code Missing ";"
    | TYPE DecList error
    {
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
    }
    ;
DecList : Dec 
				{
						CreateTreeNode(&$$, 1, @$.first_line, "DecList", NULL, 1);
						$$->children[0] = $1;
				}
				| Dec COMMA DecList
				{
						CreateTreeNode(&$$, 1, @$.first_line, "DecList", NULL, 3);
						$$->children[0] = $1;
						$$->children[1] = $2;
						$$->children[2] = $3;
				} 
				;
Dec : VarDec
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Dec", NULL, 1);
				$$->children[0] = $1;
		} 
		// error-11 Not allowed 
		// Consider to solve shift/reduce conflict
		// | VarDec error Exp
		// {
		// 		syntaxErrorNum = syntaxErrorNum + 1;
		// 		printf("Line %d : %d (Syntax Error) Illegal Symbol\n", @$.first_line, @$.last_column);
		// 		// make the syntax analysis to the normal state 
		// 		yyerrok;
		// }
		;

/*Expressions*/
Exp : Exp ASSIGNOP Exp
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
		}
    | Exp AND Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    | Exp OR Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    | NOT Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 2);
				$$->children[0] = $1;
				$$->children[1] = $2;
    }
    | Exp COMPARE Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    | Exp ADD Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->value = ($1->value) + ($2->value);
    }
    | Exp SUB Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->value = ($1->value) - ($2->value);
    }
    | Exp MULT Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->value = ($1->value) * ($2->value);
    }
    | Exp DIV Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->value = ($1->value) / ($2->value);
    }
    | LP Exp RP
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    | SUB Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 2);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->value = -($2->value);
    } 
    | Exp LOGICAND Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->value = ($1->value) && ($2->value);
    }
    | Exp LOGICOR Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->value = ($1->value) || ($2->value);
    }
    | LOGICNOT Exp
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 2);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->value = ! ($2->value);
    } 
    | ID LP Args RP
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 4);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->children[3] = $4;
    } 
    | ID LP RP 
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    | Exp LB Exp RB
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 4);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
				$$->children[3] = $4;
    } 
    | Exp DOT ID 
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
    }
    | ID 
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 1);
				$$->children[0] = $1;
    }
    | INTEGER 
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 1);
				$$->children[0] = $1;
				$$->value = $1->value;
    }
    | FLOATING
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 1);
				$$->children[0] = $1;
				$$->value = $1->value;
    }
    | STRING
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 1);
				$$->children[0] = $1;
    }
    | CHAR
    {
				CreateTreeNode(&$$, 1, @$.first_line, "Exp", NULL, 1);
				$$->children[0] = $1;
    }
    // error-12 a = array[10] [ ] is not int number
    | Exp LB error RB
    {
    	 	syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Expected type 'int'\n", @$.first_line, @$.last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
    }
		// | error Exp RP
		// {
		// 		syntaxErrorNum = syntaxErrorNum + 1;
		// 		printf("Line %d : %d (Syntax Error) Missing \" ( \" \n", @$.first_line, @$.last_column);
		// 		// make the syntax analysis to the normal state 
		// 		yyerrok;
		// }
		// | LP Exp error
		// {
		// 		syntaxErrorNum = syntaxErrorNum + 1;
		// 		printf("Line %d : %d (Syntax Error) Missing \" ) \" \n", @$.first_line, @$.last_column);
		// 		// make the syntax analysis to the normal state 
		// 		yyerrok;
		// }
    ;
Args : Exp COMMA Args 
	 	{
				CreateTreeNode(&$$, 1, @$.first_line, "Args", NULL, 3);
				$$->children[0] = $1;
				$$->children[1] = $2;
				$$->children[2] = $3;
		}
    | Exp 
		{
				CreateTreeNode(&$$, 1, @$.first_line, "Args", NULL, 1);
				$$->children[0] = $1;
		}
		;
%%

int yyerror(char* msg) 
{
    return 0;
}

int main()
{
		char inputOp[10];
		printf("Print the syntax tree ?(please input Yes/No)\n");
		scanf("%s", &inputOp);
		if(strcmp(inputOp, "Yes") == 0)
		{
				isPrintSyntaxTree = 1;
		}
		else if (strcmp(inputOp, "No") == 0)
		{
				isPrintSyntaxTree = 0;
		}
		else
		{
				printf("Invalid instruction !!!, so not print the syntax tree\n");
				isPrintSyntaxTree = 0;
		}

		printf("Print the symbol table ?(please input Yes/No)\n");
		scanf("%s", &inputOp);
		if(strcmp(inputOp, "Yes") == 0)
		{
				isPrintSymbolTable = 1;
		}
		else if (strcmp(inputOp, "No") == 0)
		{
				isPrintSymbolTable = 0;
		}
		else
		{
				printf("Invalid instruction !!!, so not print the symbol table\n");
				isPrintSymbolTable = 0;
		}
		printf("\ncreate syntax tree start...\n");
		sleep(1);
		printf("\nsyntax tree created finish...\n");
		sleep(1);

    yyparse();
    return 0;
}

int DoTheAfterSyntax()
{
		if(syntaxErrorNum + lexicalErrorNum > 0)
		{
				printf("Total Error Numbers   : %d \n", syntaxErrorNum + lexicalErrorNum);
				printf("Lexical Error Numbers : %d \n", lexicalErrorNum);
				printf("Syntax Error Numbers  : %d \n", syntaxErrorNum);
				printf("please correct the mistake.\n");	  		
		}
		if(isPrintSyntaxTree == 1)
		{
				printf("\nprint syntax tree start!\n\n");
				sleep(1);
				PrintTreeNode(root, 0);
				printf("\nsyntax tree print finish!\n");
				sleep(1);
		}

		// 创建、打印和释放符号表
		CreateSymbolTable(root);
		if(isPrintSymbolTable == 1)
		{
				PrintSymbolTable();
		}
		FreeSymbolTable();

		// 生成和打印中间代码
		CreateTempCode(root);
		PrintTempCode();

		// 生成和打印汇编
		printf("\ncreate assembly code start...\n\n");
		GenerateAssemblyCode();
		printf("\nassembly code created finish...\n");
		sleep(1);

		// 释放中间代码
		FreeTempCode();

		// 释放语法树
		FreeTreeNode(root);
		printf("\nSyntax Tree already free.\n");
		sleep(1);
		
		return 0;
}