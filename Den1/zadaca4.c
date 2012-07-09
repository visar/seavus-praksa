#include <stdio.h>
#include <stdlib.h>

int FuncName(void);

int main(int argc, char * argv[])
{
    int i, prag = atoi(argv[1]);
    for (i = 1; i < prag; i++)
        printf("%d\t%d\n",i,FuncName());
    return 0;
}

int FuncName(void)
{
    static unsigned povici = 0;
    povici++;
    if (povici % 25 == 0)
        return povici;
    return 0;
}
