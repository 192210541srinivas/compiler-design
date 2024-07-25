%{
#include <stdio.h>
%}

%%

[A-Z]+  { printf("Capital Word: %s\n", yytext); }

.       ;  // ignore any other characters

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
