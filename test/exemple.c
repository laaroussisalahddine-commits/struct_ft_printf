#include <stdio.h>

int main(void)
{
    printf("|%-5c|\n", 'A');
    printf("|%-8s|\n", "hello");
    printf("|%-6d|\n", 42);
    printf("|%-6i|\n", -42);
    printf("|%-7u|\n", 42u);
    printf("|%-8x|\n", 255);
    printf("|%-8X|\n", 255);
    printf("|%-10p|\n", (void *)0x123);
    return (0);
}
