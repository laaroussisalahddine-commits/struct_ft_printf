
#include <stdio.h>
#include "ft_printf.h"

#define TEST(fmt, c) do {                                      \
    int expected;                                              \
    int actual;                                                \
    printf("\nTEST: " fmt " | char=%d\n", (int)(c));            \
    printf("Expected: |");                                     \
    fflush(stdout);                                            \
    expected = printf(fmt, c);                                 \
    printf("|\n");                                             \
    printf("Actual:   |");                                     \
    fflush(stdout);                                            \
    actual = ft_printf(fmt, c);                                \
    printf("|\n");                                             \
    printf("Return: expected=%d, actual=%d -> %s\n",            \
        expected, actual,                                      \
        expected == actual ? "PASS (length)" : "FAIL");          \
} while (0)

int main(void)
{
    // Basic
    TEST("%c", 'A');
    TEST("%c", '0');
    TEST("%c", ' ');
    TEST("%c", '\0');

    // Width
    TEST("%5c", 'A');
    TEST("%10c", 'Z');
    TEST("%1c", 'B');
    TEST("%0c", 'C');

    // Minus flag
    TEST("%-5c", 'A');
    TEST("%-10c", 'Z');
    TEST("%-1c", 'B');
    TEST("%-0c", 'C');

    // Dynamic width
    TEST("%*c", 'A'); // Remove: requires two arguments

    return (0);
}
