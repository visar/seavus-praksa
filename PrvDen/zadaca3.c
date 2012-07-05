#include <stdio.h>

void upper(char *);

int main(int argc, char * argv[])
{
    upper(argv[1]);
    printf("%s\n", argv[1]);

    return 0;
}

void upper(char *s)
{
    while(*s)
    {
        if ('a' <= *s && *s <= 'z')
            *s = *s + 'A' - 'a';
        s++;
    }
}
