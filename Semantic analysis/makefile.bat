bison -d minic_syntax.y
flex minic_lexical.l
gcc treenode.c symboltable.c minic_syntax.tab.c lex.yy.c -o minic