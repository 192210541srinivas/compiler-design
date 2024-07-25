%{
#include <stdio.h>
%}

%%

[0-9]+  { printf("Input is a digit: %s\n", yytext); }
[^0-9]+ { printf("Input is not a digit: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
