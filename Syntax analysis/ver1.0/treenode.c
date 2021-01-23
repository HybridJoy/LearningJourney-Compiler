#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "treenode.h"

void CreateTreeNode(treeNode** p, int t, int l, char* n, char* text)
{
	*p = (treeNode*)malloc(sizeof(treeNode));
	(*p)->type = t;
	(*p)->line = l;
	strcpy((*p)->name, n);
	if(strcmp(n, "ID") == 0 || strcmp(n, "INTEGER") == 0 || strcmp(n, "FLOATING") == 0 || strcmp(n, "TYPE") == 0)
	{
		strcpy((*p)->content, text);
	}    
    int i;
    for(i = 0;i < 10;i++)
    {
    	(*p)->children[i] = NULL;
    }

}

void PrintTreeNode(treeNode* p,int blank)
{
	if(p == NULL)
	{
		return;
	}
	if(p->type == 1)
	{
		int i;
		for(i = 0;i < blank;i++)
		{
			printf(" ");
		}
		printf("%s (%d)\n",p->name, p->line);
		// print all children
		for(i = 0;i < 10;i++)
		{
			PrintTreeNode(p->children[i], blank + 2);
		}
	}
	else
	{
		int i;
		for(i = 0;i < blank;i++)
		{
			printf(" ");
		}
		printf("%s", p->name);
		if(strcmp(p->name, "ID") == 0 || strcmp(p->name, "TYPE") == 0)
		{
			printf(": %s\n", p->content);
		}
		else if(strcmp(p->name, "INT") == 0)
		{
			int integer = strtol(p->content, NULL, 0);
			printf(": %d\n", integer);
		}
		else if(strcmp(p->name, "FLOAT") == 0)
		{
			float floating = atof(p->content);
			printf(": %f\n", floating);
		}
		printf("\n");
	}
}
