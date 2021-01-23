
extern int yylineno;
void yyerror(char* s,...);

// 符号表
struct symbol
{
	char* name;
	double value;
	struct ast *func;
	struct symlist *syms;
};

#define NHASH 9997
struct symbol symtab[NHASH];

struct symbol *lookup(char*);

struct symlist
{
	struct symbol *sym;
	struct symlist *next;
}

