#ifndef __TREENODE_H__
#define __TREENODE_H__

/* define grammer tree node */
typedef struct treeNode
{
	int type;
	int line;
	char name[20];
	char content[32];
	float value; // interger or float
	int childrenNum;
	struct treeNode* children[10];
}treeNode;

struct treeNode* root;

/* declare operart function */
void CreateTreeNode(treeNode** p, int type, int line, char* name, char* text, int childNum);
void PrintTreeNode(treeNode* p, int blank);
void GenerateAbstractTree(treeNode* p);

#endif