%{
#include <stdio.h>
int count_positive = 0;
int count_negative = 0;
%}

%%

[-+]?[0-9]+(\.[0-9]+)? {  // Matches integers and floating-point numbers
    double num = atof(yytext);
    if (num > 0) {
        count_positive++;
    } else if (num < 0) {
        count_negative++;
    }
}

%%

int main() {
    yylex();
    printf("Count of positive numbers: %d\n", count_positive);
    printf("Count of negative numbers: %d\n", count_negative);
    return 0;
}

int yywrap() {
    return 1;
}
