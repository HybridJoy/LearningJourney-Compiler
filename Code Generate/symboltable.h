#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include "treenode.h"

// 变量符号表结点
struct var
{
    char type[10]; // 变量类型
    char name[20]; // 变量名
    int isArray;   // 是否数组类型(0为不是, 1是)
    int size;      // 大小,数组类型才有的字段(非数组为0)
    int scope;     // 作用域(从0递增,越大表明作用域越小)
    int funcID;    // 函数编号
    int compstID;  // 控制段编号
    int line;      // 行号
    struct var *next;
} *varhead, *varcurr, *vartail; // 当前结点指针以及头尾结点

/*函数符号表的结点*/
struct func
{
    char type[10]; // 函数类型
    char name[20]; // 函数名
    int tag;       // 0表示未定义，1表示定义
    int paramNum;  // 形参个数
    int line;      // 行号
    struct func *next;
} *funchead, *funccurr, *functail; // 当前结点指针以及头尾结点

void CreateHeadAndTail();                 // 建立头尾结点
void CreateSymbolTable(treeNode *parent); // 创建符号表
void PrintSymbolTable();                  // 打印符号表
void FreeSymbolTable();                   // 释放符号表

void CreateVarSymbolNode(char *type, char *name, int isArray, int size, int scope, int line); // 创建变量符号表结点
void CreateFuncSymbolNode(int tag, char *type, char *name, int paramNum, int line);           // 创建函数符号表结点

int IsExistVar(char *name, int scope);  // 变量符号表内是否存在该变量
int IsExistFunc(char *name, int tag);   // 函数符号表内是否存在该函数
int IsDefineVar(char *name, int scope); // 变量是否定义
int IsDefineFunc(char *name);           // 函数是否定义

char* GetVarType(char *name, char *mark, int scope); // 获取变量类型
char* CheckExpType(treeNode *exp);                   // 检查运算式中类型是否匹配

void GenerateSymbolTable(treeNode *p);                        // 生成符号表
void GenerateFuncSymbol(treeNode *func, int tag, char *type); // 生成函数符号信息
void GenerateVarSymbol(treeNode *var, char *type, int scope); // 生成变量符号信息

#endif
