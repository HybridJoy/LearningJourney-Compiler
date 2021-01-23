#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "treenode.h"

void CreateTreeNode(treeNode **p, int type, int line, char *name, char *text, int childrenNum)
{
	*p = (treeNode *)malloc(sizeof(treeNode));
	(*p)->type = type;
	(*p)->line = line;
	strcpy((*p)->name, name);
	if (strcmp(name, "ID") == 0 || strcmp(name, "INTEGER") == 0 || strcmp(name, "FLOATING") == 0 ||
		strcmp(name, "CHAR") == 0 || strcmp(name, "STRING") == 0 || strcmp(name, "TYPE") == 0 ||
		strcmp(name, "COMPARE") == 0 || strcmp(name, "OCTNUM") == 0 || strcmp(name, "HEXNUM") == 0 ||
		strcmp(name, "ADD") == 0 || strcmp(name, "SUB") == 0 || strcmp(name, "MULT") == 0 || strcmp(name, "DIV") == 0 ||
		strcmp(name, "AND") == 0 || strcmp(name, "OR") == 0 || strcmp(name, "NOT") == 0 || strcmp(name, "LOGICAND") == 0 ||
		strcmp(name, "LOGICOR") == 0 || strcmp(name, "LOGICNOT") == 0)
	{
		strcpy((*p)->content, text);
	}

	(*p)->childrenNum = childrenNum;
	int i;
	for (i = 0; i < childrenNum; i++)
	{
		(*p)->children[i] = NULL;
	}
}

void PrintTreeNode(treeNode *p, int blank)
{
	if (p == NULL)
	{
		return;
	}

	printf(" |");

	if (p->type == 1)
	{
		int i;
		for (i = 0; i < blank; i++)
		{
			printf(" ");
		}
		printf("%s (%d)\n", p->name, p->line);
		// print all children
		for (i = 0; i < p->childrenNum; i++)
		{
			PrintTreeNode(p->children[i], blank + 3);
		}
	}
	else
	{
		int i;
		for (i = 0; i < blank; i++)
		{
			printf("-");
		}
		printf("%s", p->name);
		if (strcmp(p->name, "ID") == 0 || strcmp(p->name, "TYPE") == 0 ||
			strcmp(p->name, "CHAR") == 0 || strcmp(p->name, "STRING") == 0 ||
			strcmp(p->name, "COMPARE") == 0 || strcmp(p->name, "OCTNUM") == 0 || strcmp(p->name, "HEXNUM") == 0)
		{
			printf(": %s", p->content);
		}
		else if (strcmp(p->name, "INTEGER") == 0)
		{
			int integer = strtol(p->content, NULL, 0);
			printf(": %d", integer);
		}
		else if (strcmp(p->name, "FLOATING") == 0)
		{
			float floating = atof(p->content);
			printf(": %f", floating);
		}
		printf("\n");
	}
}

void FreeTreeNode(treeNode *p)
{
	if (p == NULL)
	{
		return;
	}
	int i;
	for (i = 0; i < p->childrenNum; i++)
	{
		FreeTreeNode(p->children[i]);
	}
	free(p);
}
