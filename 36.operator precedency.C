#include <stdio.h>

int main() {
    printf("PEMDAS: Parentheses, Exponentiation, Multiplication, Division, Addition, Subtraction\n");
    printf("Example expression: 3 + 4 * 2 - 1\n");
    int result = 3 + 4 * 2 - 1;
    printf("Step 1: Multiply 4 and 2\n");
    printf("4 * 2 = %d\n", 4 * 2);
    printf("Expression becomes: 3 + 8 - 1\n");

    printf("Step 2: Add 3 and 8\n");
    printf("3 + 8 = %d\n", 3 + 8);
    printf("Expression becomes: 11 - 1\n");

    printf("Step 3: Subtract 1 from 11\n");
    printf("11 - 1 = %d\n", 11 - 1);

    printf("Final result: %d\n", result);

    return 0;
}
