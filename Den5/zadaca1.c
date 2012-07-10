#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int chop(char *, char * []);

int main(int argc, char * argv[])
{
    int nbytes = 1;
    char *str = (char *) malloc (nbytes + 1);
    char ** operand = (char **)malloc(2 * sizeof(char *));
    int op;
    double rez;
    int flag = 0;

    while (getline(&str, (size_t *)&nbytes, stdin) > 0 )
    {
        op = chop(str, operand);
        switch (op)
        {
        case 1: rez = atof(operand[0]) + atof(operand[1]); break;
        case 2: rez = atof(operand[0]) - atof(operand[1]); break;
        case 3: rez = atof(operand[0]) * atof(operand[1]); break;
        case 4: rez = atof(operand[0]) / atof(operand[1]); break;
        case 5: rez = pow(atof(operand[0]), atof(operand[1])); break;
        default: flag = 1; break;
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

int chop(char * str, char * arr[])
{
    int count = 0;
    int inWord = 0;
    int op = 0;

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
            if (count >= 2) break;
            switch (*str)
            {
            case '+': op = 1; break;
            case '-': op = 2; break;
            case '*': op = 3; break;
            case '/': op = 4; break;
            case '^': op = 5; break;
            default: op = 0; break;
            }
            if (inWord)
            {
                *str = '\0';
                inWord = 0;
            }
        }
        str++;
    }
    return op;
}
