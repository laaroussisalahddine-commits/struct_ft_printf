#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_test
{
    const char *name;
    const char *format;
    unsigned int value;
} t_test;

static void show_bytes(const unsigned char *s, size_t len)
{
    size_t i = 0;
    putchar('"');
    while (i < len)
    {
        if (s[i] == '\n') fputs("\\n", stdout);
        else if (s[i] == '\t') fputs("\\t", stdout);
        else if (s[i] == '\0') fputs("\\0", stdout);
        else if (s[i] < 32 || s[i] > 126) printf("\\x%02X", s[i]);
        else putchar(s[i]);
        i++;
    }
    putchar('"');
}

static int run_test(int index, const t_test *test)
{
    char expected[4096];
    unsigned char actual[4096];
    FILE *tmp;
    int saved, libc_ret, ft_ret, pass;
    size_t n;

    libc_ret = snprintf(expected, sizeof(expected), test->format, test->value);
    fflush(stdout);
    tmp = tmpfile();
    if (!tmp) { perror("tmpfile"); exit(2); }
    saved = dup(STDOUT_FILENO);
    if (saved < 0 || dup2(fileno(tmp), STDOUT_FILENO) < 0)
    { perror("capture"); exit(2); }
    ft_ret = ft_printf(test->format, test->value);
    fflush(stdout);
    if (dup2(saved, STDOUT_FILENO) < 0)
    { perror("restore"); exit(2); }
    close(saved);
    rewind(tmp);
    n = fread(actual, 1, sizeof(actual), tmp);
    fclose(tmp);
    pass = (libc_ret >= 0 && libc_ret < (int)sizeof(expected)
        && ft_ret == libc_ret && n == (size_t)libc_ret
        && memcmp(expected, actual, n) == 0);
    printf("[%02d] %-36s : %s\n", index + 1, test->name, pass ? "PASS" : "FAIL");
    printf("     FORMAT: %s  VALUE: %u\n", test->format, test->value);
    printf("     EXPECTED (libc): ret=%d bytes=", libc_ret);
    show_bytes((const unsigned char *)expected,
        libc_ret >= 0 && libc_ret < (int)sizeof(expected) ? (size_t)libc_ret : 0);
    printf("\n     YOURS          : ret=%d bytes=", ft_ret);
    show_bytes(actual, n);
    putchar('\n');
    return pass;
}

int main(void)
{
    const t_test tests[] = {
        {"zero", "%u", 0U},
        {"one", "%u", 1U},
        {"single digit", "%u", 9U},
        {"two digits", "%u", 10U},
        {"three digits", "%u", 100U},
        {"arbitrary number", "%u", 12345U},
        {"INT_MAX", "%u", (unsigned int)INT_MAX},
        {"INT_MAX + 1", "%u", (unsigned int)INT_MAX + 1U},
        {"UINT_MAX", "%u", UINT_MAX},
        {"unsigned cast -1", "%u", (unsigned int)-1},
        {"large middle value", "%u", 3000000000U},
        {"literal prefix suffix", "before[%u]after", 42U},
        {"width below digits", "%2u", 1234U},
        {"width equal digits", "%4u", 1234U},
        {"width above digits", "%5u", 1234U},
        {"width 10 zero", "%10u", 0U},
        {"width 20 UINT_MAX", "%20u", UINT_MAX},
        {"width 50", "%50u", 17U},
        {"minus width below digits", "%-2u", 1234U},
        {"minus width equal digits", "%-4u", 1234U},
        {"minus width above digits", "%-5u", 1234U},
        {"minus width 10 zero", "%-10u", 0U},
        {"minus width 20 UINT_MAX", "%-20u", UINT_MAX},
        {"zero pad width 5", "%05u", 42U},
        {"zero pad width 1 zero", "%01u", 0U},
        {"zero pad width 10 zero", "%010u", 0U},
        {"zero pad width 15 UINT_MAX", "%015u", UINT_MAX},
        {"minus overrides zero", "%-08u", 42U},
        {"repeated minus", "%--8u", 42U},
        {"mixed literals and zero", "A[%08u]Z", 7U}
    };
    int passed = 0;
    int i;
    for (i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); ++i)
        passed += run_test(i, &tests[i]);
    printf("\nRESULT: %d/30 PASS | %d FAIL\n", passed, 30 - passed);
    return passed == 30 ? 0 : 1;
}
