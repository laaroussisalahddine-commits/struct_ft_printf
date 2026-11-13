
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST_U(format, value) do { \
    const char *original_fmt = "Original: |" format "|\n"; \
    const char *mine_fmt = "Mine:     |" format "|\n"; \
    int res = printf(original_fmt, (unsigned int)(value)); \
    fflush(stdout); \
    int res1 = ft_printf(mine_fmt, (unsigned int)(value)); \
    printf("Original return: %d\n", res); \
    printf("Mine return:     %d\n", res1); \
    printf("RETURN: %s\n\n", res == res1 ? "PASS" : "FAIL"); \
} while (0)

int main(void)
{
    unsigned int n = 42;

    printf("\n========== BASIC %%u ==========\n");

    TEST_U("%u", 42U);
    TEST_U("%u", 0U);
    TEST_U("%u", UINT_MAX);
    TEST_U("%u", 1U);
    TEST_U("%u", 100U);
    TEST_U("%u", 999999U);

    printf("\n========== WIDTH ==========\n");

    TEST_U("%1u", n);
    TEST_U("%2u", n);
    TEST_U("%5u", n);
    TEST_U("%10u", n);
    TEST_U("%15u", UINT_MAX);
    TEST_U("%20u", n);
    TEST_U("%30u", n);

    printf("\n========== MINUS FLAG ==========\n");

    TEST_U("%-1u", n);
    TEST_U("%-5u", n);
    TEST_U("%-10u", n);
    TEST_U("%-3u", n);
    TEST_U("%-20u", UINT_MAX);

    printf("\n========== ZERO FLAG ==========\n");

    TEST_U("%05u", n);
    TEST_U("%010u", n);
    TEST_U("%05u", 0U);
    TEST_U("%020u", UINT_MAX);
    TEST_U("%030u", n);

    printf("\n========== MINUS + ZERO ==========\n");

    TEST_U("%-05u", n);
    TEST_U("%0-10u", n);
    TEST_U("%-010u", 0U);
    TEST_U("%0-20u", UINT_MAX);

    printf("\n========== PRECISION ==========\n");

    TEST_U("%.0u", 0U);
    TEST_U("%.0u", n);
    TEST_U("%.1u", n);
    TEST_U("%.5u", n);
    TEST_U("%.10u", 1U);
    TEST_U("%.15u", UINT_MAX);

    printf("\n========== WIDTH + PRECISION ==========\n");

    TEST_U("%10.5u", n);
    TEST_U("%-10.5u", n);
    TEST_U("%010.5u", n);
    TEST_U("%8.0u", 0U);
    TEST_U("%20.15u", UINT_MAX);
    TEST_U("%-20.15u", UINT_MAX);

    printf("\n========== EDGE CASES ==========\n");

    TEST_U("%u", (unsigned int)-1);
    TEST_U("%u", (unsigned int)-42);
    TEST_U("%020u", UINT_MAX);
    TEST_U("%-20u", UINT_MAX);
    TEST_U("%20.15u", UINT_MAX);
    TEST_U("%030.20u", UINT_MAX);

    return (0);
}
