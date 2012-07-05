#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void print(void *, size_t);

int main()
{
    /* void * buffer1 = calloc(64,sizeof(void)); */
    /* void * tmp = buffer1; */
    char buffer2[64];
    int buffer3[64];
    long buffer4[64];
    long long buffer5[64];
    unsigned brojac;
    srand(time(NULL));

    /* for(brojac = 64; brojac; brojac--) */
    /* { */
    /*     *buffer1 = rand() * CHAR_MAX + 1; */
    /*     buffer1++; */
    /*     /\* buffer1[brojac] = rand() * CHAR_MAX + 1; *\/ */
    /* } */

    /* buffer1 = tmp; */

    for(brojac = 64; brojac; brojac--)
    {
        buffer2[brojac] = (char)(rand() * CHAR_MAX + 1);
    }

    for(brojac = 64; brojac; brojac--)
    {
        buffer3[brojac] = (int)(rand() * INT_MAX + 1);
    }

    for(brojac = 64; brojac; brojac--)
    {
        buffer4[brojac] = (long)(rand() * LONG_MAX + 1);
    }

    for(brojac = 64; brojac; brojac--)
    {
        buffer5[brojac] = (long long)(rand() * LLONG_MAX + 1);
    }


    print((void *)buffer2, sizeof(buffer2));
    print(buffer2, sizeof(buffer2));
    print(buffer3, sizeof(buffer3));
    print(buffer4, sizeof(buffer4));
    print(buffer5, sizeof(buffer5));
    /* free(buffer1); */

    return 0;
}

void print(void * buffer, size_t size)
{
    unsigned char * tmp = (unsigned char *) buffer;
    size_t len = size;

    while (len)
    {
        printf("0x%02x; ", *tmp);
        tmp++;
        len--;
    }

    putchar('\n');

    unsigned short * tmp2 = (unsigned short *) buffer;

    len = size;
    while (len)
    {
        printf("0x%04x; ", *tmp2);
        tmp2++;
        len--;
    }

    putchar('\n');

    unsigned int * tmp3 = (unsigned int *) buffer;

    len = size;
    while (len)
    {
        printf("0x%08x; ", *tmp3);
        tmp3++;
        len--;
    }

    putchar('\n');
}
