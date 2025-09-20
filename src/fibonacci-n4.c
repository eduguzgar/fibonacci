#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n, long long *arr) {
    long long a = 0, b = 1;
    long long s1, s2, s3, s4;

    if (n == 0) {
        return;
    }

    if (n >= 1) {
        arr[0] = a;
    }
    if (n >= 2) {
        arr[1] = b;
    }

    int idx = 2;
    int max_blocks = (n - 2) / 4;
    int i;
    for (i = 0; i < max_blocks; ++i) {
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

    int remaining = (n - 2) % 4;
    for (i = 0; i < remaining; ++i) {
        s1 = a + b;

        arr[idx++] = s1;

        a = b;
        b = s1;
    }
}

void print_fibonacci(int n, long long *arr)
{
    int i;
    for(i = 0; i < n - 1; ++i)
    {
        printf("%lld, ", arr[i]);
    }

    printf("%lld\n", arr[i]);
}

int main() {
    int n;
    long long *arr;

    printf("How many numbers do you want (N)?\n");
    scanf("%d", &n);

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
