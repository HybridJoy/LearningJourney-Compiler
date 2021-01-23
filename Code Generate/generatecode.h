#ifndef __GENERATECODE_H__
#define __GENERATECODE_H__

#include "treenode.h"

struct tempCode // 四元式
{
    char op[5];                                 // 操作符
    char arg1[5];                               // 操作数1
    char arg2[5];                               // 操作数2
    char result[10];                            // 结果
    char reg[5];                                // 变量分配的寄存器编号
    int isAllocateReg;                          // 是否分配寄存器
    int isTempVari;                             // 结果是否是临时变量
    struct tempCode *next;                      // 下一个结点的指针
} * tempCodeHead, *tempCodeTail, *tempCodeCurr; // 当前结点指针以及头尾结点

void CreateTempCodeNode(char *op, char *arg1, char *arg2, char *result, int isTempVari); // 创建中间代码结点

void CreateTempCode(treeNode *root); // 创建中间代码表
void PrintTempCode();                // 打印中间代码
void FreeTempCode();                 // 释放中间代码表

void GenerateIntermediateCode(treeNode *p);      // 生成中间代码
void GenerateExpIntermediateCode(treeNode *exp); // 分析表达式的中间代码
void GenerateAssemblyCode();                     // 生成汇编代码

int CheckIsVari(char *arg);                                  // 检查是否变量
char* GetVariReg(char *arg);                                 // 获取给该变量分配的寄存器
char* GenerateArithmeticAssemblyCode(struct tempCode *node); // 生成 + - * / 的汇编代码

#endif