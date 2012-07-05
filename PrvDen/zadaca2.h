#pragma once
#ifndef ZADACA2_H_
#define ZADACA2_H_
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

typedef union
{
    float value;

    struct
    {
        unsigned part1 : 8;
        unsigned part2 : 8;
        unsigned part3 : 8;
        unsigned part4 : 8;
    } endianness;
} float_type;

typedef union
{
    double value;

    struct
    {
        unsigned part1 : 8;
        unsigned part2 : 8;
        unsigned part3 : 8;
        unsigned part4 : 8;
        unsigned part5 : 8;
        unsigned part6 : 8;
        unsigned part7 : 8;
        unsigned part8 : 8;
    } endianness;
} double_type;

inline void changeEndianness(int_type *);
inline void changeEndiannessF(float_type *);
inline void changeEndiannessD(double_type *);
inline void show(int_type *);
inline void showF(float_type *);
inline void showD(double_type *);
#endif
