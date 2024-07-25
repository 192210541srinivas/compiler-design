%{
#include <stdio.h>
%}
%%
\<[^>]*\> fprintf(yyout,"%s\n",yytext);
.|\n;         
%%
int yywrap(){}
int main() {
yyin=fopen("sample.html","r");
yyout=fopen("output.txt","w");
yylex();
return 0;
}
