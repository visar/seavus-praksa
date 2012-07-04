#include <stdio.h>
#include <stdlib.h>

typedef union
{
    int value;

    struct
    {
        unsigned part1 : 8;
        unsigned part2 : 8;
        unsigned part3 : 8;
        unsigned part4 : 8;
    } endianness;
} int_type;

inline void changeEndianness(int_type *);
inline void show(int_type *);

int main(int argc, char * argv[])
{
    int_type * broj = (int_type *) malloc(sizeof(int_type));

    broj->value = atoi(argv[1]);
    show(broj);

    changeEndianness(broj);
    show(broj);

    changeEndianness(broj);
    show(broj);

    return 0;
}

void show(int_type * n)
{
    printf("%08x\n",n->endianness.part1 << 24 | n->endianness.part2 << 16 | n->endianness.part3 << 8 | n->endianness.part4);
}

void changeEndianness(int_type * n)
{

    n->endianness.part1 ^= n->endianness.part4;
    n->endianness.part4 ^= n->endianness.part1;
    n->endianness.part1 ^= n->endianness.part4;
    n->endianness.part2 ^= n->endianness.part3;
    n->endianness.part3 ^= n->endianness.part2;
    n->endianness.part2 ^= n->endianness.part3;

}
