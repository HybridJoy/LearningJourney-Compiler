#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcID = 0;		 // 函数编号
int compstID = 0;	// 控制段编号
int globalScope = 0; // 作用域

void CreateHeadAndTail()
{
	varhead = (struct var *)malloc(sizeof(struct var));
	vartail = (struct var *)malloc(sizeof(struct var));
	varhead->next = vartail;
	varcurr = varhead; // 变量符号表当前位置位于头结点

	funchead = (struct func *)malloc(sizeof(struct func));
	functail = (struct func *)malloc(sizeof(struct func));
	funchead->next = functail;
	funccurr = funchead; // 函数符号表当前位置位于头结点
}

void CreateVarSymbolNode(char *type, char *name, int isArray, int size, int scope, int line)
{
	struct var *currvar = (struct var *)malloc(sizeof(struct var));
	strcpy(currvar->type, type);
	strcpy(currvar->name, name);
	currvar->isArray = isArray;
	currvar->size = size;
	currvar->scope = scope;
	currvar->funcID = funcID;
	currvar->compstID = compstID;
	currvar->line = line;
	if (scope == 0)
	{
		currvar->funcID = 0;
	}

	varcurr->next = currvar;
	currvar->next = vartail;
	varcurr = currvar;
}

void CreateFuncSymbolNode(int tag, char *type, char *name, int paramNum, int line)
{
	struct func *currfunc = (struct func *)malloc(sizeof(struct func));
	strcpy(currfunc->type, type);
	strcpy(currfunc->name, name);
	currfunc->tag = tag;
	currfunc->paramNum = paramNum;
	currfunc->line = line;

	funccurr->next = currfunc;
	currfunc->next = functail;
	funccurr = currfunc;

	funcID++; // 函数编号增加
}

void CreateSymbolTable(treeNode *parent)
{
	printf("\nstart create symbol table....\n");
	sleep(1);
	CreateHeadAndTail();
	GenerateSymbolTable(parent);
	printf("\ncreate symbol table finish....\n");
	sleep(1);
}

void PrintSymbolTable()
{
	printf("\nprint var symbol table\n\n");
	sleep(1);
	struct var *currvar = varhead->next;
	while (currvar != vartail)
	{
		printf("name : %s \ttype : %s \tisArray : %d \tsize : %d \tfuncID : %d \tcompstID : %d \tscope : %d\n",
			   currvar->name, currvar->type, currvar->isArray, currvar->size, currvar->funcID, currvar->compstID, currvar->scope);
		currvar = currvar->next;
	}
	
	printf("\nprint func symbol table\n");
	sleep(1);
	struct func *currfunc = funchead->next;
	while (currfunc != functail)
	{
		printf("name : %s \ttype : %s \ttag : %d \tparaNum : %d\n", currfunc->name, currfunc->type, currfunc->tag, currfunc->paramNum);
		currfunc = currfunc->next;
	}
}

void FreeSymbolTable()
{
	struct var *currvar = varhead;
	struct var *tempvar;
	while (currvar)
	{
		tempvar = currvar;
		currvar = currvar->next;
		free(tempvar);
	}

	struct func *currfunc = funchead;
	struct func *tempfunc;
	while (currfunc)
	{
		tempfunc = currfunc;
		currfunc = currfunc->next;
		free(tempfunc);
	}

	printf("\nSymbol Table already free.\n");
	sleep(1);
}

int IsExistVar(char *name, int scope)
{
	struct var *currvar = varhead->next;
	int flag = 0;
	while (currvar != vartail)
	{
		// 比较变量名
		if (strcmp(currvar->name, name) == 0)
		{
			// 比较作用域
			if (currvar->scope == scope)
			{
				// 全局变量不允许重复定义
				if (scope == 0)
				{
					flag = currvar->line;
					break;
				}
				else
				{
					// 同一控制段里不允许重复定义
					if (currvar->compstID == compstID)
					{
						flag = currvar->line;
						break;
					}
				}
			}
			else if (currvar->scope < scope)
			{
				// 同一函数里，不允许作用域小于已有变量的同名变量重定义
				if (currvar->funcID == funcID)
				{
					flag = currvar->line;
					break;
				}
			}
		}
		currvar = currvar->next;
	}
	return flag;
}

int IsExistFunc(char *name, int tag)
{
	struct func *currfunc = funchead->next;
	int flag = 0;
	while (currfunc != functail)
	{
		if (strcmp(currfunc->name, name) == 0)
		{
			// 查看是否定义
			if (currfunc->tag == tag)
			{
				flag = currfunc->line;
				break;
			}
		}
		currfunc = currfunc->next;
	}
	return flag;
}

int IsDefineVar(char *name, int scope)
{
	struct var *currvar = varhead->next;
	int flag = 0;
	while (currvar != vartail)
	{
		// 比较变量名
		if (strcmp(currvar->name, name) == 0)
		{
			// 比较作用域(可以使用比当前作用域大的变量)
			if (currvar->scope <= scope)
			{
				flag = currvar->line;
				break;
			}
		}
		currvar = currvar->next;
	}
	return flag;
}

int IsDefineFunc(char *name)
{
	struct func *currfunc = funchead->next;
	int flag = 0;
	while (currfunc != functail)
	{
		if (strcmp(currfunc->name, name) == 0)
		{
			flag = currfunc->line;
			break;
		}
		currfunc = currfunc->next;
	}
	return flag;
}

char* GetVarType(char *name, char *mark, int scope)
{
	char *type = (char *)malloc(sizeof(char) * 10);
	// 变量查找符号表得到类型
	if (strcmp(mark, "ID") == 0)
	{
		struct var *currvar = varhead->next;
		while (currvar != vartail)
		{
			// 找到同名变量
			if (strcmp(currvar->name, name) == 0)
			{
				// 作用域必须大于等于当前变量的作用域
				if (currvar->scope <= scope)
				{
					strcpy(type, currvar->type);
				}
			}
			currvar = currvar->next;
		}
	}
	// 常量直接返回对应类型
	else if (strcmp(mark, "INTEGER") == 0)
	{
		strcpy(type, "int");
	}
	else if (strcmp(mark, "FLOATING") == 0)
	{
		strcpy(type, "float");
	}
	else if (strcmp(mark, "CHAR") == 0)
	{
		strcpy(type, "char");
	}
	else
	{
		strcpy(type, "null");
	}
	return type;
}

char* CheckExpType(treeNode *exp)
{
	if (exp->childrenNum == 1)
	{
		return GetVarType(exp->children[0]->content, exp->children[0]->name, globalScope);
	}

	char *result = (char *)malloc(sizeof(char) * 10);
	struct treeNode *exp_1 = exp->children[0];
	struct treeNode *exp_2 = exp->children[2];

	char *type_exp_1 = (char *)malloc(sizeof(char) * 10);
	char *type_exp_2 = (char *)malloc(sizeof(char) * 10);

	if (exp_1->childrenNum == 1)
	{
		type_exp_1 = GetVarType(exp_1->children[0]->content, exp_1->children[0]->name, globalScope);
	}
	else if (exp_1->childrenNum == 2)
	{
		type_exp_1 = CheckExpType(exp_1->children[1]);
	}
	else if (exp_1->childrenNum == 3)
	{
		// 递归调用求解运算表达式类型检查结果
		if (strcmp(exp_1->children[0]->name, "LP") == 0)
		{
			type_exp_1 = CheckExpType(exp_1->children[1]);
		}
		else
		{
			type_exp_1 = CheckExpType(exp_1);
		}
	}

	if (exp_2->childrenNum == 1)
	{
		type_exp_2 = GetVarType(exp_2->children[0]->content, exp_2->children[0]->name, globalScope);
	}
	else if (exp_2->childrenNum == 2)
	{
		type_exp_2 = CheckExpType(exp_2->children[1]);
	}
	else if (exp_2->childrenNum == 3)
	{
		// 递归调用求解运算表达式类型检查结果
		if (strcmp(exp_2->children[0]->name, "LP") == 0)
		{
			type_exp_2 = CheckExpType(exp_2->children[1]);
		}
		else
		{
			type_exp_2 = CheckExpType(exp_2);
		}
	}
	if (strcmp(type_exp_1, type_exp_2) == 0)
	{
		strcpy(result, type_exp_1);
	}
	else
	{
		strcpy(result, "null");
	}
	return result;
}

void GenerateSymbolTable(treeNode *p)
{
	if (p == NULL)
	{
		return;
	}
	if (p->childrenNum == 0)
	{
		return;
	}
	if (strcmp(p->name, "Compst") == 0)
	{
		compstID++;
		globalScope++; // 进入compst 作用域减小
	}
	int i;
	for (i = 0; i < p->childrenNum; i++)
	{
		if (p->children[i] == NULL)
		{
			continue;
		}
		// 构建符号表
		if (strcmp(p->children[i]->name, "TYPE") == 0)
		{
			if (strcmp(p->children[i + 1]->name, "FunDec") == 0)
			{
				int tag = 1;
				if (strcmp(p->children[i + 2]->name, "SEMI") == 0)
				{
					tag = 0;
				}
				struct treeNode *func = p->children[i + 1];
				GenerateFuncSymbol(func, tag, p->children[i]->content);
			}
			else if (strcmp(p->children[i + 1]->name, "CodeDecList") == 0)
			{
				struct treeNode *codeDecList = p->children[i + 1];
				// bug need fix (fixed)
				if (codeDecList->childrenNum == 1)
				{
					GenerateVarSymbol(codeDecList->children[0], p->children[i]->content, 0);
				}
				else
				{
					while (codeDecList->childrenNum != 1)
					{
						GenerateVarSymbol(codeDecList->children[0], p->children[i]->content, 0);
						codeDecList = codeDecList->children[2];
					}
					GenerateVarSymbol(codeDecList->children[0], p->children[i]->content, 0);
				}
			}
			else if (strcmp(p->children[i + 1]->name, "DecList") == 0)
			{
				struct treeNode *decList = p->children[i + 1];
				struct treeNode *dec = decList->children[0];
				if (decList->childrenNum == 1)
				{
					GenerateVarSymbol(dec->children[0], p->children[i]->content, 1);
				}
				else
				{
					while (decList->childrenNum != 1)
					{
						dec = decList->children[0];
						GenerateVarSymbol(dec->children[0], p->children[i]->content, 1);
						decList = decList->children[2];
					}
					dec = decList->children[0];
					GenerateVarSymbol(dec->children[0], p->children[i]->content, 1);
				}
			}
			continue;
		}
		// 变量声明检查
		if (strcmp(p->children[i]->name, "ID") == 0)
		{
			int result = 0;
			if (i + 1 < p->childrenNum)
			{
				if (strcmp(p->children[i + 1]->name, "LP") == 0)
				{
					result = IsDefineFunc(p->children[i]->content);
					if (result == 0)
					{
						printf("Line : %d (Error) Not define func %s\n", p->children[i]->line, p->children[i]->content);
						sleep(1);
					}
					continue;
				}
			}
			result = IsDefineVar(p->children[i]->content, globalScope);
			if (result == 0)
			{
				printf("Line : %d (Error) Not define var %s\n", p->children[i]->line, p->children[i]->content);
				sleep(1);
			}
		}
		// 表达式类型检查
		if (strcmp(p->children[i]->name, "Exp") == 0)
		{
			struct treeNode *exp = p->children[i];
			if (exp->childrenNum == 3 && strcmp(exp->children[1]->name, "ASSIGNOP") == 0)
			{
				char *result = (char *)malloc(sizeof(char) * 10);
				strcpy(result, CheckExpType(exp));
				if (strcmp(result, "null") == 0)
				{
					printf("Line : %d (Error) Expression type not match \n", p->children[i]->line);
					sleep(1);
				}
			}
		}
		GenerateSymbolTable(p->children[i]);
	}
	if (strcmp(p->name, "Compst") == 0)
	{
		globalScope--; // 退出compst, 作用域增大
	}
}

void GenerateFuncSymbol(treeNode *func, int tag, char *type)
{
	int paramNum = 0;
	if (func->childrenNum != 3)
	{
		struct treeNode *varList = func->children[2];
		paramNum = 1;
		while (varList->childrenNum != 1)
		{
			varList = varList->children[2];
			paramNum = paramNum + 1;
		}
	}
	int result = IsExistFunc(func->children[0]->content, tag);
	if (result != 0)
	{
		printf("Line : %d (Error) Redefination Func %s, already define at line %d\n", func->line, func->children[0]->content, result);
		sleep(1);
		return;
	}
	CreateFuncSymbolNode(tag, type, func->children[0]->content, paramNum, func->line);
}

void GenerateVarSymbol(treeNode *var, char *type, int scope)
{
	if (var->childrenNum == 3)
	{
		var = var->children[0];
	}
	int isArray = 0;
	int size = 0;
	if (var->childrenNum == 4)
	{
		isArray = 1;
		size = strtol(var->children[2]->content, NULL, 0);
		while (var->childrenNum != 1)
		{
			var = var->children[0];
		}
	}
	int result = IsExistVar(var->children[0]->content, globalScope);
	if (result != 0)
	{
		printf("Line : %d (Error) Redefination Var %s, already define at line %d\n", var->line, var->children[0]->content, result);
		sleep(1);
		return;
	}
	CreateVarSymbolNode(type, var->children[0]->content, isArray, size, globalScope, var->line);
}