#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
    int op[2];
} ops;

ops chop(char *, char * []);

int main(int argc, char * argv[])
{
    int nbytes = 1;
    char *str = (char *) malloc (nbytes + 1);
    char ** operand = (char **)malloc(3 * sizeof(char *));
    ops opr;
    double rez;
    int flag = 0;

    while (getline(&str, (size_t *)&nbytes, stdin) > 0 )
    {
        flag = 0;
        opr = chop(str, operand);
        if ((opr.op[1] == 5 && (opr.op[0] == 1 || opr.op[0] == 2 || opr.op[0] == 3 || opr.op[0] == 4)) || ((opr.op[1] == 3 || opr.op[1] == 4) && (opr.op[0] == 1 || opr.op[0] == 2)))
        {
            switch (opr.op[1])
            {
            case 3: rez = atof(operand[1]) * atof(operand[2]); break;
            case 4: rez = atof(operand[1]) / atof(operand[2]); break;
            case 5: rez = pow(atof(operand[1]), atof(operand[2])); break;
            default: flag = 1; break;
            }
            switch (opr.op[0])
            {
            case 1: rez += atof(operand[0]); break;
            case 2: rez =  atof(operand[0]) - rez; break;
            case 3: rez *= atof(operand[0]); break;
            case 4: rez = atof(operand[0]) / rez; break;
            case 5: rez = pow(atof(operand[0]), rez); break;
            default: flag = 1; break;
            }
        }
        else
        {
            switch (opr.op[0])
            {
            case 1: rez = atof(operand[0]) + atof(operand[1]); break;
            case 2: rez = atof(operand[0]) - atof(operand[1]); break;
            case 3: rez = atof(operand[0]) * atof(operand[1]); break;
            case 4: rez = atof(operand[0]) / atof(operand[1]); break;
            case 5: rez = pow(atof(operand[0]), atof(operand[1])); break;
            default: flag = 1; break;
            }
            switch (opr.op[1])
            {
            case 1: rez += atof(operand[1]); break;
            case 2: rez -= atof(operand[1]); break;
            case 3: rez *= atof(operand[1]); break;
            case 4: rez /= atof(operand[1]); break;
            case 5: rez = pow(rez, atof(operand[1])); break;
            default: flag = 1; break;
            }
        }
        if (flag)
        {
            printf("GRESKA!\n");
        }
        else
        {
            printf("%.2lf\n", rez);
        }
    }
    return 0;
}

ops chop(char * str, char * arr[])
{
    int count = 0;
    int inWord = 0;
    ops operators;

    while (*str)
    {
        while (isspace(*str))
            str++;
        if (!count && (*str) == '-')
        {
            arr[count++] = str;
            inWord = 1;
            str++;
        }
        if (isdigit(*str) || (*str) == '.')
        {
            if (!inWord)
            {
                arr[count++] = str;
                inWord = 1;
            }
        }
        else
        {
            if (count > 2) break;
            switch (*str)
            {
            case '+': operators.op[count-1] = 1; break;
            case '-': operators.op[count-1] = 2; break;
            case '*': operators.op[count-1] = 3; break;
            case '/': operators.op[count-1] = 4; break;
            case '^': operators.op[count-1] = 5; break;
            default: operators.op[count-1] = 0; break;
            }
            if (inWord)
            {
                *str = '\0';
                inWord = 0;
            }
        }
        str++;
    }
    return operators;
}
