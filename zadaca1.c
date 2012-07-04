#include <stdio.h>
#include <string.h>

void print(void *, size_t);

int main(int argc, char * argv[])
{
    char * name = "Test";
    print(name, strlen(name));
    int ints[] = {1,2,3,4,5,6,7};
    print(ints, sizeof(ints));
    long longs[] = {1,2,3,40};
    print(longs,sizeof(longs));
    float pi[] = {3.14};
    print(pi, sizeof(float));
    return 0;
}

void print(void * buffer, size_t size)
{
    unsigned char * tmp = (unsigned char *) buffer;
    while (size)
    {
        printf("%02x ", *tmp);
        tmp++;
        size--;
    }
    putchar('\n');
}
