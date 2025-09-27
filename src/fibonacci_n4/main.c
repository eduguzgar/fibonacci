#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <stdint.h>
#include "fibonacci_n4.h"

int main(void) {
    long tmp;
    size_t n = 0;
    long long *arr = NULL;

    printf("How many numbers do you want (N)?\n");
    fflush(stdout);

    if (scanf("%ld", &tmp) != 1) {
        fprintf(stderr, "Error: invalid input\n");
        return EXIT_FAILURE;
    }
    if (tmp < 0) {
        fprintf(stderr, "Error: negative numbers are not allowed\n");
        return EXIT_FAILURE;
    }

    n = (size_t) tmp;

    if (n > 0 && n > SIZE_MAX / sizeof *arr) {
        fprintf(stderr, "Error: requested size is too large\n");
        return EXIT_FAILURE;
    }

    if (n > 0) {
        arr = malloc(n * sizeof *arr);
        if (!arr) {
            fprintf(stderr, "Error: malloc failed\n");
            return EXIT_FAILURE;
        }
    }

    fibonacci(n, arr);
    print_fibonacci(n, arr);

    free(arr);
    return EXIT_SUCCESS;
}
