
%option pointer
%option noyywrap
%x COMMENT
%{
	#include <stdio.h>
	#include <string.h>
	#define MAXLEN 100
	#define MAXTYPE 10
	#define MAXSTR 15

	char *a[MAXTYPE] = {"type","for","integer","decimal","identify","bracket","QUOTE","OPT","float"};
	struct {
		int line;	//store line numbers
		int id;		// store tag
		char text[MAXSTR];	//store yytext
	}tag[MAXLEN];	//store tags
	int flag = 0;	//error flag
	int cnt = 0;	//array notation counter
    int line=1;		//line counter
%}
DIGIT [0-9]
OINTEGER [1-9]{DIGIT}*
INTEGER ("+"|"-")?{OINTEGER}
DECIMAL {INTEGER}(.{OINTEGER})?
LETTER [a-zA-Z]
ID ({LETTER}|_)({LETTER}|_|{DIGIT})*
OPT ("+="|"-="|"*="|"/="|"+"|"-"|"*"|"/"|"<="|">="|"=="|"=")
INDEX {DIGIT}+(\.{DIGIT}+)?e([+-])?{DIGIT}+
ERROR {DIGIT}+(\.{DIGIT}+)?e

%%
"//".* {}
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN INITIAL;}
<COMMENT>. {}

\n {++line;}
(int|float|double|short) {
	tag[cnt].line = line;
	tag[cnt].id = 0;
	strcpy(tag[cnt].text,yytext); //has bugs--use strcpy is ok,no pointer 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
for {
	tag[cnt].line = line;
	tag[cnt].id = 1;
	strcpy(tag[cnt].text,""); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
{INTEGER} {
	tag[cnt].line = line;
	tag[cnt].id = 2;
	strcpy(tag[cnt].text,yytext); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
{DECIMAL} {
	tag[cnt].line = line;
	tag[cnt].id = 3;
	strcpy(tag[cnt].text,yytext); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
{ID} {
	tag[cnt].line = line;
	tag[cnt].id = 4;
	strcpy(tag[cnt].text,yytext); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
("("|")"|"{"|"}"|"["|"]") {
	tag[cnt].line = line;
	tag[cnt].id = 5;
	strcpy(tag[cnt].text,yytext); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
"\"" {
	tag[cnt].line = line;
	tag[cnt].id = 6;
	strcpy(tag[cnt].text,""); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
{OPT} {
	tag[cnt].line = line;
	tag[cnt].id = 7;
	strcpy(tag[cnt].text,yytext); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
{INDEX} {
	tag[cnt].line = line;
	tag[cnt].id = 8;
	strcpy(tag[cnt].text,yytext); 
	//printf("%s : %d--%d\n",tag[cnt].text,yyleng,cnt);
	cnt++;
}
{ERROR} {
	flag = 1;
	tag[cnt].line = line;
	tag[cnt].id = -1;	//soso
	strcpy(tag[cnt].text,yytext); 
	cnt++;
}
. {}

%%

int main()
{
	/*
	 *begin lexical analysis
	 *present all the tags
	 *but ...
	 */
	yylex();

	if(flag) {//print ERRORS
		int i;
		for(i=0;i<cnt;i++){
			if(tag[i].id == -1){
				printf("Error type A at Line %d: Illegal floating point number \"%s\".\n",tag[i].line,tag[i].text);
				break;
			}
		}
		
	} else {
		int i;
		for(i=0;i<cnt;i++){
			if(tag[i].id == 5){//print "QUOTE"
				printf("line%d:(%s, \"%s\")\n",tag[i].line,a[tag[i].id],tag[i].text);
			} else {
				printf("line%d:(%s, %s)\n",tag[i].line,a[tag[i].id],tag[i].text);
			}
		}
	}
	
	return 0;
}

// int yywrap()
// {
// 	return 1;
// }



