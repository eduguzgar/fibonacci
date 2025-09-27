#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "../../src/fibonacci_n4/fibonacci_n4.h"

// Helpers
static void expect_array_eq_ll(const long long *got, const long long *exp, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        assert(got[i] == exp[i]);
    }
}

static char* capture_print(size_t n, const long long *arr) {
    FILE *tmp = tmpfile();
    assert(tmp != NULL);

    int rc = fflush(stdout);
    assert(rc == 0);
    FILE *saved_stdout = stdout;
    stdout = tmp;

    print_fibonacci(n, arr);

    fflush(stdout);
    stdout = saved_stdout;

    fseek(tmp, 0, SEEK_END);
    long len = ftell(tmp);
    assert(len >= 0);
    fseek(tmp, 0, SEEK_SET);

    char *buf = (char*)malloc((size_t)len + 1);
    assert(buf != NULL);
    size_t readn = fread(buf, 1, (size_t)len, tmp);
    assert(readn == (size_t)len);
    buf[len] = '\0';

    fclose(tmp);
    return buf;
}

// Tests
static void test_fib_n0_no_touch() {
    long long sentinel = 0x7fffffffffffffffLL;
    long long arr[1] = { sentinel };
    fibonacci(0, arr);
    assert(arr[0] == sentinel);
}

static void test_fib_n1() {
    long long arr[1] = { -1 };
    fibonacci(1, arr);
    long long exp[1] = {0};
    expect_array_eq_ll(arr, exp, 1);
}

static void test_fib_n2() {
    long long arr[2] = { -1, -1 };
    fibonacci(2, arr);
    long long exp[2] = {0, 1};
    expect_array_eq_ll(arr, exp, 2);
}

static void test_fib_n10() {
    long long arr[10];
    fibonacci(10, arr);
    long long exp[10] = {0,1,1,2,3,5,8,13,21,34};
    expect_array_eq_ll(arr, exp, 10);
}

static void test_print_n0_silent() {
    long long dummy = 42;
    char *out = capture_print(0, &dummy);
    assert(strcmp(out, "") == 0);
    free(out);
}

static void test_print_n1() {
    long long arr[1] = {0};
    char *out = capture_print(1, arr);
    assert(strcmp(out, "0\n") == 0);
    free(out);
}

static void test_print_n5() {
    long long arr[5] = {0,1,1,2,3};
    char *out = capture_print(5, arr);
    assert(strcmp(out, "0, 1, 1, 2, 3\n") == 0);
    free(out);
}


// Runner
int main(void) {
    test_fib_n0_no_touch();
    test_fib_n1();
    test_fib_n2();
    test_fib_n10();

    test_print_n0_silent();
    test_print_n1();
    test_print_n5();

    puts("All tests passed ✅");
    return 0;
}
