#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[50];
    int type; 
    int value;
    float fvalue;
} Symbol;
typedef enum {
    PUSH,
    POP,
    ADD,
    SUB,
    MUL,
    DIV,
    STORE,
    LOAD
} Instruction;
void generateCode(Symbol* symbols, int symbolCount) {
    printf("Generated Code:\n");
    for (int i = 0; i < symbolCount; i++) {
        Symbol symbol = symbols[i];
        if (symbol.type == 0) { 
            printf("PUSH %d\n", symbol.value);
        } else { // float
            printf("PUSH %f\n", symbol.fvalue);
        }
    }
    printf("ADD\n");
    printf("STORE\n");
    printf("LOAD\n");
}

int main() {
    Symbol symbols[10];
    int symbolCount = 0;
    strcpy(symbols[symbolCount].name, "x");
    symbols[symbolCount].type = 0; // int
    symbols[symbolCount].value = 10;
    symbolCount++;
    strcpy(symbols[symbolCount].name, "y");
    symbols[symbolCount].type = 1; // float
    symbols[symbolCount].fvalue = 20.5;
    symbolCount++;
    generateCode(symbols, symbolCount);

    return 0;
}
