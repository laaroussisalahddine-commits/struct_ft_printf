#include <stdio.h>

int main(void)
{
    printf("|%%5s| :|%100s|\n", "hello world");
    printf("|%%-8s| :|%-8s|\n", "A");
    // printf("|%-6d|\n", 42);
    // printf("|%-6i|\n", -42);
    // printf("|%-7u|\n", 42u);
    // printf("|%-8x|\n", 255);
    // printf("|%-8X|\n", 255);
    // printf("|%-10p|\n", (void *)0x123);
    return (0);
}
