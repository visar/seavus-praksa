#include <stdio.h>
#include <stdlib.h>
#include "zadaca2.h"

int main(int argc, char * argv[])
{
    int_type * broj = (int_type *) malloc(sizeof(int_type));

    broj->value = atoi(argv[1]);
    show(broj);

    changeEndianness(broj);
    show(broj);

    changeEndianness(broj);
    show(broj);

    printf("%ld\n",sizeof(double_type));

    return 0;
}

void show(int_type * n)
{
    printf("%08x\n",n->endianness.part4 << 24 | n->endianness.part3 << 16 | n->endianness.part2 << 8 | n->endianness.part1);
}

void showF(float_type * f)
{
    printf("%08x\n",f->endianness.part4 << 24 | f->endianness.part3 << 16 | f->endianness.part2 << 8 | f->endianness.part1);
}

void showD(double_type * d)
{
    printf("%016lx\n", (unsigned long)d->endianness.part8 << 56 | (unsigned long)d->endianness.part7 << 48 | (unsigned long)d->endianness.part6 << 40 | (unsigned long)d->endianness.part5 << 32 | d->endianness.part4 << 24 | d->endianness.part3 << 16 | d->endianness.part2 << 8 | d->endianness.part1);
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

void changeEndiannessF(float_type * f)
{
    f->endianness.part1 ^= f->endianness.part4;
    f->endianness.part4 ^= f->endianness.part1;
    f->endianness.part1 ^= f->endianness.part4;
    f->endianness.part2 ^= f->endianness.part3;
    f->endianness.part3 ^= f->endianness.part2;
    f->endianness.part2 ^= f->endianness.part3;
}

void changeEndiannessD(double_type * d)
{
    d->endianness.part1 ^= d->endianness.part8;
    d->endianness.part8 ^= d->endianness.part1;
    d->endianness.part1 ^= d->endianness.part8;
    d->endianness.part2 ^= d->endianness.part7;
    d->endianness.part7 ^= d->endianness.part2;
    d->endianness.part2 ^= d->endianness.part7;
    d->endianness.part3 ^= d->endianness.part6;
    d->endianness.part6 ^= d->endianness.part3;
    d->endianness.part3 ^= d->endianness.part6;
    d->endianness.part4 ^= d->endianness.part5;
    d->endianness.part5 ^= d->endianness.part4;
    d->endianness.part4 ^= d->endianness.part5;
}
