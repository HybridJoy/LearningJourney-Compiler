

%%
"int"                                {printf("type  ");}
"short"                              {printf("type  ");}
"long"                               {printf("type  ");}
"long long"                          {printf("type  ");}
"char"                               {printf("type  ");}
"float"                              {printf("type  ");}
"double"                             {printf("type  ");}
"long double"                        {printf("type  ");}
"unsigned short"                     {printf("type  ");}
"unsigned int"                       {printf("type  ");}
"unsigned long"                      {printf("type  ");}
"unsigned long long"                 {printf("type  ");}
"unsigned long double"               {printf("type  ");}
"int*"                               {printf("type  ");}
"char*"                              {printf("type  ");}
"float*"                             {printf("type  ");}
"short*"                             {printf("type  ");}
"long*"                              {printf("type  ");}
"long long*"                         {printf("type  ");}
"long double*"                       {printf("type  ");}

        
([1-9][0-9]*|0)                             {printf("constInt   ");}  //int
[0-9]"."[0-9]                               {printf("constFloatOrDouble     ");}  //float,double
"\""[a-zA-Z]*"\""                           {printf("string     ");}  //string
'\'[a-zA-Z]{1}\''                           {printf("char   ");}  //char
[0-9]+["E","e"]["+","-"]?[0-9]+             {printf("intExponential    ");}  //2e10
[0-9]+"."[0-9]+["E","e"]["+","-"]?[0-9]+    {printf("floatExponential    ");}  //2.0e10
0[0-7]+                                     {printf("Octal    ");}
"0x"[0-9]*[A-F]*                            {printf("hex    ");}





"+"                          {printf("add   ");}  //operator
"-"                          {printf("sub   ");}
"*"                          {printf("multiply  ");}     //can be get value from point operator and multiply
"/"                          {printf("devide    ");}
"%"                          {printf("mod   ");}

"=="                         {printf("ifEqual   ");}
"!="                         {printf("ifNotEqual    ");}
">"                          {printf("greaterThan   ");}
"<"                          {printf("lessThan  ");}
">="                         {printf("greaterEqualThan  ");}
"<="                         {printf("lessEqualThan     ");}

"&&"                         {printf("and   ");}
"||"                         {printf("or    ");}
"!"                          {printf("not   ");}

"&"                          {printf("andBitOperator    ");}     //can be get address operator and and operator
"|"                          {printf("orBitOperator     ");}
"^"                          {printf("exclusiveBitOperator  ");}
"~"                          {printf("notBitOperator    ");}
"<<"                         {printf("leftBitMove   ");}
">>"                         {printf("rightBitMove  ");}

"="                          {printf("equalTo   ");}
"+="                         {printf("addEqualTo    ");}
"-="                         {printf("subEqualTo    ");}
"*="                         {printf("multiplyEqualTo   ");}
"/="                         {printf("divideEqualTo     ");}
"%="                         {printf("modEqualTo    ");}
"<<="                        {printf("leftBitMoveEqualTo    ");}
">>="                        {printf("rightBitMoveEqualTo   ");}
"&="                         {printf("andBitOperatorEqualTo     ");}
"^="                         {printf("exclusiveBitOperatorEqualTo   ");}
"|="                         {printf("orBitOperatorEqualTo  ");}
        
"?:"                         {printf("ternaryOperator");}


","                          {printf("comma     ");}
"["                          {printf("leftSmallBracket  ");}
"]"                          {printf("rightSmallBracket     ");}
"{"                          {printf("leftMiddleBracket     ");}
"}"                          {printf("rightMiddleBracket    ");}
"("                          {printf("leftBigBracket    ");} 
")"                          {printf("rightBigBracket   ");}

";"                          {printf("semicolon");}


"if"                        {printf("ifIdentifier    ");}
"else"                      {printf("elseIdentifier");}
"switch"                    {printf("swithIdentifier");}
"case"                      {printf("caseIdentifier");}
"do"                        {printf("doIdentifier");}
"while"                     {printf("whileIdentifier");}
"for"                       {printf("forIdentifier");}
"break"                     {printf("breakIdentifier");}
"continue"                  {printf("continueIdentifier");}

[\t]                        {}
" "                         {} 

^[a-zA-Z,_][^" "]*          {printf("identifier      ");}
[0-9]+[xyz]+                {printf("wrong partterned   ");}
.+                          {printf("wrong partterned   ");}
%%

int yywrap() {
   // open next reference or source file and start scanning
   return 1;
}

void main(int argc,char **argv){
    yylex();
}
