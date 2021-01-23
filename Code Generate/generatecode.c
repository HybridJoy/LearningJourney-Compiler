#include "generatecode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempNum = 0; // 临时变量编号

void CreateTempCodeNode(char *op, char *arg1, char *arg2, char *result, int isTempVari)
{
    struct tempCode *currTempCode = (struct tempCode *)malloc(sizeof(struct tempCode));
    strcpy(currTempCode->op, op);
    strcpy(currTempCode->arg1, arg1);
    strcpy(currTempCode->arg2, arg2);
    strcpy(currTempCode->result, result);
    currTempCode->isAllocateReg = 0;
    currTempCode->isTempVari = isTempVari;

    tempCodeCurr->next = currTempCode;
    currTempCode->next = tempCodeTail;
    tempCodeCurr = currTempCode;
}

void CreateTempCode(treeNode *root)
{
    printf("\nstart create temp code....\n");
	sleep(1);
    // 创建头尾结点
    tempCodeHead = (struct tempCode *)malloc(sizeof(struct tempCode));
    tempCodeTail = (struct tempCode *)malloc(sizeof(struct tempCode));
    tempCodeHead->next = tempCodeTail;
    tempCodeCurr = tempCodeHead;

    GenerateIntermediateCode(root);

    printf("\ncreate temp code finish....\n");
	sleep(1);
}

void PrintTempCode()
{
    printf("\nstart print temp code!\n\n");
	sleep(1);
    struct tempCode *currTempCode = tempCodeHead->next;
    while (currTempCode != tempCodeTail)
    {
        printf("%s \t%s \t%s \t%s\n", currTempCode->op, currTempCode->arg1, currTempCode->arg2, currTempCode->result);
        currTempCode = currTempCode->next;
    }
    printf("\nprint temp code finish !\n");
	sleep(1);
}

void FreeTempCode()
{
    struct tempCode *currTempCode = tempCodeHead;
    struct tempCode *tempTempCode;
    while (currTempCode)
    {
        tempTempCode = currTempCode;
        currTempCode = currTempCode->next;
        free(tempTempCode);
    }
    printf("\nTemp Code already free.\n");
	sleep(1);
}

void GenerateIntermediateCode(treeNode *p)
{
    if (p == NULL || p->childrenNum == 0)
    {
        return;
    }
    int i;
    for (i = 0; i < p->childrenNum; i++)
    {
        if (p->children[i] == NULL)
        {
            continue;
        }
        if (strcmp(p->children[i]->name, "DecList") == 0)
        {
            treeNode *decList = p->children[i];
            while (decList->childrenNum != 1) // 逗号连续定义变量
            {
                decList = decList->children[2];
            }
            // declist->dec(1) || declist->dec comma declist(3),  dec->vardec
            treeNode *vardec = decList->children[0]->children[0]; // 最后一个定义变量

            char *value = malloc(sizeof(char) * 5);
            // vardec->id(1), vardec->id [ int ](4), vardec->id = exp(3)
            if (vardec->childrenNum == 3)
            {
                treeNode *exp = vardec->children[2];
                GenerateExpIntermediateCode(exp);
                strcpy(value, exp->place);
            }
            else if (vardec->childrenNum == 1) // vardec->id(1)
            {
                strcpy(value, "0");
            }

            decList = p->children[i];
            while (decList->childrenNum != 1)
            {
                vardec = decList->children[0]->children[0];
                CreateTempCodeNode("=", value, " ", vardec->children[0]->content, 0);
                decList = decList->children[2];
            }
            // 处理最后一个定义变量 declist->dec->vardec->vardec assignop exp(3), vardec->id(1)
            vardec = decList->children[0]->children[0];
            if (vardec->childrenNum == 3)
            {
                vardec = vardec->children[0];
            }
            CreateTempCodeNode("=", value, " ", vardec->children[0]->content, 0);

            continue;
        }
        if (strcmp(p->children[i]->name, "Exp") == 0)
        {
            treeNode *exp = p->children[i];
            if (exp->childrenNum == 3)
            {
                if (strcmp(exp->children[1]->name, "ASSIGNOP") == 0)
                {
                    treeNode *exp_1 = exp->children[0];
                    treeNode *exp_2 = exp->children[2];
                    GenerateExpIntermediateCode(exp_2);
                    CreateTempCodeNode("=", exp_2->place, " ", exp_1->children[0]->content, 0);
                }
            }
            continue;
        }
        GenerateIntermediateCode(p->children[i]);
    }
}

void GenerateExpIntermediateCode(treeNode *exp)
{
    // exp-> id | int | float | char | string
    if (exp->childrenNum == 1)
    {
        strcpy(exp->place, exp->children[0]->content);
    }
    // exp-> - exp(2) || ! exp(2) || ~ exp(2)
    else if (exp->childrenNum == 2)
    {
        treeNode *exp_1 = exp->children[1];

        char *arg_1;
        if (exp_1->childrenNum == 1)
        {
            arg_1 = (char *)malloc(strlen(exp_1->children[0]->content) + 1);
            strcpy(arg_1, exp_1->children[0]->content);
        }
        else
        {
            GenerateExpIntermediateCode(exp_1);
            arg_1 = (char *)malloc(strlen(exp_1->place) + 1);
            strcpy(arg_1, exp_1->place);
        }

        char tempVariableNum[2];
        itoa(tempNum, tempVariableNum, 10);
        char *result = malloc(strlen(tempVariableNum) + 2);
        strcpy(result, "t");
        strcat(result, tempVariableNum);
        CreateTempCodeNode(exp->children[0]->content, arg_1, " ", result, 1);

        tempNum++; // 临时变量编号 +1
        strcpy(exp->place, result);
    }
    // exp-> exp + exp || exp - exp || exp * exp || exp / exp || ( exp )
    else if (exp->childrenNum == 3)
    {
        if (strcmp(exp->children[0]->name, "LP") == 0)
        {
            GenerateExpIntermediateCode(exp->children[1]);
            strcpy(exp->place, exp->children[1]->place);
        }
        else
        {
            treeNode *exp_1 = exp->children[0];
            treeNode *exp_2 = exp->children[2];

            char *arg_1;
            char *arg_2;
            if (exp_1->childrenNum == 1)
            {
                arg_1 = (char *)malloc(strlen(exp_1->children[0]->content) + 1);
                strcpy(arg_1, exp_1->children[0]->content);
            }
            else
            {
                GenerateExpIntermediateCode(exp_1);
                arg_1 = (char *)malloc(strlen(exp_1->place) + 1);
                strcpy(arg_1, exp_1->place);
            }
            if (exp_2->childrenNum == 1)
            {
                arg_2 = (char *)malloc(strlen(exp_2->children[0]->content) + 1);
                strcpy(arg_2, exp_2->children[0]->content);
            }
            else
            {
                GenerateExpIntermediateCode(exp_2);
                arg_2 = (char *)malloc(strlen(exp_2->place) + 1);
                strcpy(arg_2, exp_2->place);
            }

            char tempVariableNum[2];
            itoa(tempNum, tempVariableNum, 10);
            char *result = malloc(strlen(tempVariableNum) + 2);
            strcpy(result, "t");
            strcat(result, tempVariableNum);
            CreateTempCodeNode(exp->children[1]->content, arg_1, arg_2, result, 1);

            tempNum++; // 临时变量编号 +1
            strcpy(exp->place, result);
        }
    }
    else
    {
        return;
    }
}

void GenerateAssemblyCode()
{
    struct tempCode *currTempCode = tempCodeHead->next;
    FILE *out = fopen("output.asm", "w");
    if(out == NULL)
    {
        printf("open output file failed!\n");
        return;
    }
    sleep(1);
    printf(".main\n");
    fprintf(out, ".main\n");

    int regNum = 0;
    char *reg;
    char tempRegNum[2];
    while (currTempCode != tempCodeTail)
    {
        if (strcmp(currTempCode->op, "=") == 0)
        {
            strcpy(reg, GetVariReg(currTempCode->result));
            if (strcmp(reg, "null") == 0)
            {
                itoa(regNum++, tempRegNum, 10);
                reg = (char *)malloc(strlen(tempRegNum) + 2);
                strcpy(reg, "r");
                strcat(reg, tempRegNum);
            }
            currTempCode->isAllocateReg = 1;
            strcpy(currTempCode->reg, reg);
            printf("mov %s %s\n", reg, currTempCode->arg1);
            fprintf(out, "mov %s %s\n", reg, currTempCode->arg1);
        }
        else if (strcmp(currTempCode->op, "+") == 0 || strcmp(currTempCode->op, "-") == 0 ||
                 strcmp(currTempCode->op, "*") == 0 || strcmp(currTempCode->op, "/") == 0)
        {
            char* result = GenerateArithmeticAssemblyCode(currTempCode);
            printf("%s\n", result);
            fprintf(out, "%s\n", result);
        }

        currTempCode = currTempCode->next;
    }

    fclose(out);
    printf("\noutput.asm file already create....\n");
}

int CheckIsVari(char *arg)
{
    int flag = 1;
    if (strcmp(arg, "0") == 0 || strcmp(arg, " ") == 0)
    {
        flag = 0;
    }
    else if (atoi(arg) != 0)
    {
        flag = 0;
    }
    return flag;
}

char* GetVariReg(char *arg)
{
    struct tempCode *currTempCode = tempCodeHead->next;
    char *reg;
    while (currTempCode != tempCodeTail)
    {
        if (strcmp(currTempCode->result, arg) == 0)
        {
            if (currTempCode->isTempVari == 1)
            {
                reg = (char *)malloc(strlen(currTempCode->result) + 1);
                strcpy(reg, currTempCode->result);
                return reg;
            }
            if (currTempCode->isAllocateReg == 1)
            {

                reg = (char *)malloc(strlen(currTempCode->reg) + 1);
                strcpy(reg, currTempCode->reg);
                return reg;
            }
            break;
        }
        currTempCode = currTempCode->next;
    }
    return "null";
}

char* GenerateArithmeticAssemblyCode(struct tempCode *node)
{
    char* result;
    result = (char*)malloc(sizeof(char) * 20);
    strcpy(result, "");
    if (strcmp(node->op, "+") == 0)
    {
        strcat(result, "add ");
    }
    else if (strcmp(node->op, "-") == 0)
    {
        strcat(result, "sub ");
    }
    else if (strcmp(node->op, "*") == 0)
    {
        strcat(result, "mul ");
    }
    else if (strcmp(node->op, "/") == 0)
    {
        strcat(result, "div ");
    }
    strcat(result, node->result);
    strcat(result, " ");

    if (CheckIsVari(node->arg1) == 1)
    {
        strcat(result, GetVariReg(node->arg1));
        strcat(result, " ");
    }
    else
    {
        strcat(result, node->arg1);
        strcat(result, " ");
    }
    if (CheckIsVari(node->arg2) == 1)
    {
        strcat(result, GetVariReg(node->arg2));
        strcat(result, " ");
    }
    else
    {
        strcat(result, node->arg2);
        strcat(result, " ");
    }
    return result;
}