bison -d minic_syntax.y
flex minic_lexical.l
gcc treenode.c symboltable.c minic_syntax.tab.c lex.yy.c generatecode.c -o minic
@echo off
:start
cls
echo create run.bat..
echo minic.exe^<testinput.c>run.bat
echo @echo off>>run.bat
echo :start>>run.bat
echo pause>>run.bat
echo :end>>run.bat
echo compile finish
pause
:end