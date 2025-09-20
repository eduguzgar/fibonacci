#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n, long long *arr) {
    if (n == 0) {
        return;
    }

    if (n >= 1) {
        arr[0] = 0;
    }
    if (n >= 2) {
        arr[1] = 1;
    }

    int i;
    for (i = 2; i < n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
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

    puts("How many numbers do you want (N)?");
    scanf("%d", &n);

    if (n < 0) {
        fputs("Error: Negative numbers are invalid.", stderr);
        return 1;
    }

    arr = (long long*)malloc((size_t)n * sizeof(long long));

    if (!arr) {
        fputs("Error: malloc array.", stderr);
        return 1;
    }

    fibonacci(n, arr);
    print_fibonacci(n, arr);

    free(arr);

    return 0;
}
