#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    printf("\n========== BASIC %%c ==========\n");

    printf("Original: |%c|\n", 'A');
    fflush(stdout);
    ft_printf("Mine:     |%c|\n", 'A');

    printf("Original: |%c|\n", '0');
    fflush(stdout);
    ft_printf("Mine:     |%c|\n", '0');

    printf("Original: |%c|\n", ' ');
    fflush(stdout);
    ft_printf("Mine:     |%c|\n", ' ');

    printf("Original: |%c|\n", '\0');
    fflush(stdout);
    ft_printf("Mine:     |%c|\n", '\0');

    printf("Original: |%c|\n", '\n');
    fflush(stdout);
    ft_printf("Mine:     |%c|\n", '\n');

    printf("\n========== WIDTH ==========\n");
    fflush(stdout);

    printf("Original: |%1c|\n", 'A');
    fflush(stdout);
    ft_printf("Mine:     |%1c|\n", 'A');

    printf("Original: |%5c|\n", 'A');
    fflush(stdout);
    ft_printf("Mine:     |%5c|\n", 'A');

    printf("Original: |%10c|\n", 'Z');
    fflush(stdout);
    ft_printf("Mine:     |%10c|\n", 'Z');

    printf("Original: |%20c|\n", 'B');
    fflush(stdout);
    ft_printf("Mine:     |%20c|\n", 'B');

    printf("Original: |%5c|\n", '\0');
    fflush(stdout);
    ft_printf("Mine:     |%5c|\n", '\0');

    printf("\n========== MINUS FLAG ==========\n");
    fflush(stdout);

    printf("Original: |%-1c|\n", 'A');
    fflush(stdout);
    ft_printf("Mine:     |%-1c|\n", 'A');

    printf("Original: |%-5c|\n", 'A');
    fflush(stdout);
    ft_printf("Mine:     |%-5c|\n", 'A');

    printf("Original: |%-10c|\n", 'Z');
    fflush(stdout);
    ft_printf("Mine:     |%-10c|\n", 'Z');

    printf("Original: |%-20c|\n", 'B');
    fflush(stdout);
    ft_printf("Mine:     |%-20c|\n", 'B');

    printf("Original: |%-5c|\n", '\0');
    fflush(stdout);
    ft_printf("Mine:     |%-5c|\n", '\0');

    printf("Original: |%-10c|\n", ' ');
    fflush(stdout);
    ft_printf("Mine:     |%-10c|\n", ' ');

    printf("\n========== EDGE CASES ==========\n");
    fflush(stdout);

    printf("Original: |%-100c|\n", 'Z');
    fflush(stdout);
    ft_printf("Mine:     |%-100c|\n", 'Z');

    printf("Original: |%100c|\n", 'Z');
    fflush(stdout);
    ft_printf("Mine:     |%100c|\n", 'Z');

    printf("\n========== RETURN VALUES ==========\n");
    fflush(stdout);

    int original = printf("%-5c", 'A');
    fflush(stdout);
    printf("\nOriginal return: %d\n", original);
    fflush(stdout);

    int mine = ft_printf("%-5c", 'A');
    printf("\nMine return:     %d\n", mine);
    fflush(stdout);

    return (0);
}