#ifndef __TREENODE_H__
#define __TREENODE_H__

/* define grammer tree node */
typedef struct treeNode
{
	int type;
	int line;
	char name[20];
	char content[32];
	float value;   // 算术运算表达式的值 interger or float
	char place[5]; // 添加place字段，标识该节点的规约变量(临时变量)
	int childrenNum;
	struct treeNode *children[10];
} treeNode;

struct treeNode *root;

/* declare operart function */
void CreateTreeNode(treeNode **p, int type, int line, char *name, char *text, int childNum); // 创建语法树结点
void PrintTreeNode(treeNode *p, int blank);													 // 打印语法树
void FreeTreeNode(treeNode *p);																 // 释放语法树

#endif