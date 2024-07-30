#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_SYMBOLS 100

typedef struct {
    char non_terminal;
    char production[MAX_SYMBOLS];
} Rule;

Rule grammar[MAX_RULES];
int num_rules = 0;

char first[MAX_SYMBOLS][MAX_SYMBOLS];
bool visited[MAX_SYMBOLS];

int indexOf(char symbol) {
    for (int i = 0; i < num_rules; i++) {
        if (grammar[i].non_terminal == symbol) {
            return i;
        }
    }
    return -1;
}

void addFirst(char symbol, char terminal) {
    int idx = indexOf(symbol);
    if (idx != -1 && !strchr(first[idx], terminal)) {
        strncat(first[idx], &terminal, 1);
    }
}

void computeFirst(char symbol) {
    if (visited[symbol]) return;
    visited[symbol] = true;

    int idx = indexOf(symbol);
    if (idx == -1) return;

    for (int i = 0; i < num_rules; i++) {
        if (grammar[i].non_terminal == symbol) {
            for (int j = 0; j < strlen(grammar[i].production); j++) {
                char prod_symbol = grammar[i].production[j];
                if (prod_symbol >= 'A' && prod_symbol <= 'Z') {  // Non-terminal
                    computeFirst(prod_symbol);
                    int prod_idx = indexOf(prod_symbol);
                    if (prod_idx != -1) {
                        for (int k = 0; k < strlen(first[prod_idx]); k++) {
                            addFirst(symbol, first[prod_idx][k]);
                        }
                    }
                } else {  // Terminal
                    addFirst(symbol, prod_symbol);
                    break;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of rules: ");
    scanf("%d", &num_rules);

    printf("Enter the grammar rules (e.g., S->AB):\n");
    for (int i = 0; i < num_rules; i++) {
        char buffer[MAX_SYMBOLS + 3];  // To accommodate 'A->' and '\0'
        scanf("%s", buffer);
        grammar[i].non_terminal = buffer[0];
        strcpy(grammar[i].production, buffer + 3);
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < num_rules; i++) {
        computeFirst(grammar[i].non_terminal);
    }

    printf("FIRST sets:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("FIRST(%c) = { ", grammar[i].non_terminal);
        int idx = indexOf(grammar[i].non_terminal);
        if (idx != -1) {
            for (int j = 0; j < strlen(first[idx]); j++) {
                printf("%c ", first[idx][j]);
            }
        }
        printf("}\n");
    }

    return 0;
}
