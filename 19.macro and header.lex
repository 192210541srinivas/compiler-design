%{
int macro_count = 0;
int header_count = 0;
%}
%%
^#define    { macro_count++; }
^#include   { header_count++; }

.|\n        

%%
int yywrap(){}
int main() {
     yylex();
    printf("Number of Macros defined: %d\n", macro_count);
    printf("Number of Header files included: %d\n", header_count);
}
