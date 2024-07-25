%{
#include <stdio.h>
#include <string.h>

#define MAX_KEYWORDS 32

char *keywords[MAX_KEYWORDS] = {
    "auto", "double", "int", "struct",
    "break", "else", "long", "switch",
    "case", "enum", "register", "typedef",
    "char", "extern", "return", "union",
    "const", "float", "short", "unsigned",
    "continue", "for", "signed", "void",
    "default", "goto", "sizeof", "volatile",
    "do", "if", "static", "while"
};

int is_keyword(char *word) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* { // Matches identifiers and keywords
    if (is_keyword(yytext)) {
        printf("Keyword: %s\n", yytext);
    } else {
        printf("Identifier: %s\n", yytext);
    }
}

[ \t\n]+ ; // Ignore whitespace

. ; // Ignore any other character

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
