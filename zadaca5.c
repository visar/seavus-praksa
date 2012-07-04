#include <stdio.h>
#include <stdlib.h>

inline int deliSo2(int);

int main(int argc, char * argv[])
{
int brojac, prag = atoi(argv[1]);

for (brojac = 0; brojac <= prag; brojac++)
    printf("%d / 2 = %d\n", brojac, deliso2(brojac));

return 0;
}

int deliSo2(int arg)
{
    return arg >> 1;
}
