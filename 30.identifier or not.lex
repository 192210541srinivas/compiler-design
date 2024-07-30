%{
#include <stdio.h>
%}

IDENTIFIER  [a-zA-Z_][a-zA-Z_0-9]*

%%

{IDENTIFIER}  {
                printf("Valid identifier: %s\n", yytext);
            }

.           {
                printf("Invalid identifier: %s\n", yytext);
            }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
