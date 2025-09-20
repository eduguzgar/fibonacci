#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main() {
    int n;
    long long *arr;

    printf("How many numbers do you want (N)?\n");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: invalid input\n");
        return 1;
    }

    if (n < 0) {
        fprintf(stderr, "Error: negative numbers are invalid %d\n", n);
        return 1;
    }

    arr = (long long *)malloc(n * sizeof(long long));

    if (!arr) {
        fprintf(stderr, "Error: malloc array\n");
        return 1;
    }

    fibonacci(n, arr);
    print_fibonacci(n, arr);

    free(arr);

    return 0;
}
