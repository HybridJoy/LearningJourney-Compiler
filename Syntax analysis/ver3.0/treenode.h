#ifndef __TREENODE_H__
#define __TREENODE_H__

/*define grammer tree node*/
typedef struct treeNode
{
	int type;
	int line;
	char name[20];
	char content[32];
	struct treeNode* children[10];
}treeNode;

struct treeNode* root;

/* declare operart function */
void CreateTreeNode(treeNode** p,int t,int l,char* n,char* text);
void PrintTreeNode(treeNode* p,int blank);

#endif