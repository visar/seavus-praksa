#include <stdio.h>
#include <stdlib.h>

void toBinary(int);

int main(int argc, char * argv[])
{
    if (!atoi(argv[1]))
    {
        printf("0\n");
        return 0;
    }
    toBinary(atoi(argv[1]));
    putchar('\n');

    return 0;
}

void toBinary(int n)
{
    if (!n) return;
    toBinary(n >> 1);
    printf("%01d", n & 1);
}
