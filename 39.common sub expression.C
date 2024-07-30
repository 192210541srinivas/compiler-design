#include <stdio.h>
int original_function(int a, int b) {
    int temp1 = a + b;
    int result1 = temp1 * 2;
    int temp2 = a + b;
    int result2 = temp2 * 3;
    return result1 + result2;
}
int optimized_function(int a, int b) {
    int temp = a + b;
    return temp * 2 + temp * 3;
}

int main() {
    int a = 80, b = 10;
    printf("Original function result: %d\n", original_function(a, b));
    printf("Optimized function result: %d\n", optimized_function(a, b));
    return 0;
}
