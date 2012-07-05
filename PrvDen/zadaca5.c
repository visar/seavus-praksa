#include <stdio.h>
#include <stdlib.h>

inline int DeliSo2(int);

int main(int argc, char * argv[])
{
int brojac, prag = atoi(argv[1]);

for (brojac = 0; brojac <= prag; brojac++)
    printf("%d / 2 = %d\n", brojac, DeliSo2(brojac));

return 0;
}

int DeliSo2(int arg)
{
    return arg >> 1;
}
