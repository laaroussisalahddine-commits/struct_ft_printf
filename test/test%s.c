#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    printf("\n========== BASIC %%s ==========\n");
    fflush(stdout);

    printf("Original: |%s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%s|\n", "Hello");

    printf("Original: |%s|\n", "");
    fflush(stdout);
    ft_printf("Mine:     |%s|\n", "");

    printf("Original: |%s|\n", "A");
    fflush(stdout);
    ft_printf("Mine:     |%s|\n", "A");

    printf("\n========== WIDTH ==========\n");
    fflush(stdout);

    printf("Original: |%10s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%10s|\n", "Hello");

    printf("Original: |%3s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%3s|\n", "Hello");

    printf("Original: |%20s|\n", "");
    fflush(stdout);
    ft_printf("Mine:     |%20s|\n", "");

    printf("\n========== MINUS FLAG ==========\n");
    fflush(stdout);

    printf("Original: |%-10s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%-10s|\n", "Hello");

    printf("Original: |%-3s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%-3s|\n", "Hello");

    printf("Original: |%-20s|\n", "");
    fflush(stdout);
    ft_printf("Mine:     |%-20s|\n", "");

    printf("\n========== PRECISION ==========\n");
    fflush(stdout);

    printf("Original: |%.3s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%.3s|\n", "Hello");

    printf("Original: |%.0s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%.0s|\n", "Hello");

    printf("Original: |%.10s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%.10s|\n", "Hello");

    printf("\n========== WIDTH + PRECISION ==========\n");
    fflush(stdout);

    printf("Original: |%10.3s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%10.3s|\n", "Hello");

    printf("Original: |%-10.3s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%-10.3s|\n", "Hello");

    printf("Original: |%8.0s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%8.0s|\n", "Hello");

    printf("Original: |%-8.0s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%-8.0s|\n", "Hello");

    printf("\n========== EDGE CASES ==========\n");
    fflush(stdout);

    printf("Original: |%.s|\n", "Hello");
    fflush(stdout);
    ft_printf("Mine:     |%.s|\n", "Hello");

    printf("Original: |%5.2s|\n", "A");
    fflush(stdout);
    ft_printf("Mine:     |%5.2s|\n", "A");

    printf("Original: |%-5.2s|\n", "A");
    fflush(stdout);
    ft_printf("Mine:     |%-5.2s|\n", "A");

    printf("Original: |%10.3s|\n", "");
    fflush(stdout);
    ft_printf("Mine:     |%10.3s|\n", "");

    printf("\n========== RETURN VALUES ==========\n");
    fflush(stdout);

    int original = printf("%-10.3s", "Hello");
    fflush(stdout);
    printf("\nOriginal return: %d\n", original);
    fflush(stdout);

    int mine = ft_printf("%-10.3s", "Hello");
    fflush(stdout);
    printf("\nMine return:     %d\n", mine);

    return (0);
}