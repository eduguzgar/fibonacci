#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "fibonacci.h"

int main() {
    size_t n;
    long long *arr;

    printf("How many numbers do you want (N)?\n");
    if (scanf("%zu", &n) != 1) {
        fprintf(stderr, "Error: invalid input\n");
        return 1;
    }

    arr = malloc(n * sizeof *arr);

    if (!arr) {
        fprintf(stderr, "Error: malloc array\n");
        return 1;
    }

    fibonacci(n, arr);
    print_fibonacci(n, arr);

    free(arr);

    return 0;
}
