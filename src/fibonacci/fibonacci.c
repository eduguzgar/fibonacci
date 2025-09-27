#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

void fibonacci(size_t n, long long *arr) {
    if (n == 0) {
        return;
    }

    if (n >= 1) {
        arr[0] = 0;
    }
    if (n >= 2) {
        arr[1] = 1;
    }

    for (size_t i = 2; i < n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

void print_fibonacci(size_t n, const long long *arr)
{
    if (n == 0) {
        return;
    }

    for (size_t i = 0; i < n - 1; ++i) {
        printf("%lld, ", arr[i]);
    }

    printf("%lld\n", arr[n - 1]);
}
