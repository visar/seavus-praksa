#include <stdio.h>
#include <stdlib.h>

void toBinary(int);

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);
    if (!n)
    {
        printf("0\n");
        return 0;
    }
    if (n < 0)
    {
        putchar('1');
        toBinary(n&~(1<<31));
        putchar('\n');
        return 0;
    }
    putchar('0');
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
