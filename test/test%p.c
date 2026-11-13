#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int x = 42;
    char c = 'A';
    int arr[3] = {10, 20, 30};
    void *ptr = NULL;

    printf("\n========== BASIC %%p ==========\n");
    fflush(stdout);

    printf("Original: |%p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)&x);

    printf("Original: |%p|\n", (void *)&c);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)&c);

    printf("Original: |%p|\n", (void *)arr);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)arr);

    printf("\n========== NULL POINTER ==========\n");
    fflush(stdout);

    printf("Original: |%p|\n", ptr);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", ptr);

    printf("Original: |%20p|\n", ptr);
    fflush(stdout);
    ft_printf("Mine:     |%20p|\n", ptr);

    printf("Original: |%-20p|\n", ptr);
    fflush(stdout);
    ft_printf("Mine:     |%-20p|\n", ptr);

    printf("\n========== WIDTH ==========\n");
    fflush(stdout);

    printf("Original: |%1p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%1p|\n", (void *)&x);

    printf("Original: |%5p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%5p|\n", (void *)&x);

    printf("Original: |%20p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%20p|\n", (void *)&x);

    printf("Original: |%30p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%30p|\n", (void *)&x);

    printf("\n========== MINUS FLAG ==========\n");
    fflush(stdout);

    printf("Original: |%-5p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%-5p|\n", (void *)&x);

    printf("Original: |%-20p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%-20p|\n", (void *)&x);

    printf("Original: |%-30p|\n", (void *)&x);
    fflush(stdout);
    ft_printf("Mine:     |%-30p|\n", (void *)&x);

    printf("\n========== EDGE CASES ==========\n");
    fflush(stdout);

    printf("Original: |%p|\n", (void *)0);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)0);

    printf("Original: |%p|\n", (void *)1);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)1);

    printf("Original: |%p|\n", (void *)0x123);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)0x123);

    printf("Original: |%p|\n", (void *)0xABCDEF);
    fflush(stdout);
    ft_printf("Mine:     |%p|\n", (void *)0xABCDEF);

    printf("Original: |%30p|\n", (void *)0x123);
    fflush(stdout);
    ft_printf("Mine:     |%30p|\n", (void *)0x123);

    printf("Original: |%-30p|\n", (void *)0x123);
    fflush(stdout);
    ft_printf("Mine:     |%-30p|\n", (void *)0x123);

    printf("\n========== RETURN VALUES ==========\n");
    fflush(stdout);

    int original = printf("%-30p", (void *)&x);
    fflush(stdout);
    printf("\nOriginal return: %d\n", original);
    fflush(stdout);

    int mine = ft_printf("%-30p", (void *)&x);
    fflush(stdout);
    printf("\nMine return:     %d\n", mine);

    return (0);
}