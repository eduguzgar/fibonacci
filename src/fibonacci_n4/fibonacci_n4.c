#include "fibonacci_n4.h"
#include <stdio.h>
#include <stdlib.h>

void fibonacci(size_t n, long long *arr) {
    long long a = 0, b = 1;
    long long s1, s2, s3, s4;

    if (n == 0) {
        return;
    }

    arr[0] = a;
    if (n == 1) {
        return;
    }

    arr[1] = b;
    if (n == 2) {
        return;
    }

    size_t idx = 2;
    size_t max_blocks = (n - 2) / 4;
    for (size_t i = 0; i < max_blocks; ++i) {
        s1 = a + b;
        s2 = b + s1;
        s3 = s1 + s2;
        s4 = s2 + s3;

        arr[idx++] = s1;
        arr[idx++] = s2;
        arr[idx++] = s3;
        arr[idx++] = s4;

        a = s3;
        b = s4;
    }

    size_t remaining = (n - 2) % 4;
    for (size_t i = 0; i < remaining; ++i) {
        s1 = a + b;
        arr[idx++] = s1;
        a = b;
        b = s1;
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
