#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "operator.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

bool checkNumber(char *operand)
{
    int i = 0;
    int pointCount = 0;

    if (operand[i] == '-')
        i++;
    while (operand[i] != '\0')
    {
        if (operand[i] < '0' || operand[i] > '9')
        {
            if (operand[i] == '.' && pointCount == 0)
                pointCount++;
            else
                return (false);
        }
        i++;
    }
    return (true);
}

bool checkOperator(char *operand)
{
    if (operand[0] == '+' || operand[0] == '-' || operand[0] == '*' || operand[0] == '/')
        if (operand[1] == '\0')
            return (true);
    return (false);
}

number setNumber(char *operand)
{
    int i = 0;
    int j = 0;
    int size = 0;
    number ini;

    ini.sign = 1;
    if (operand[0] == '-')
    {
        ini.sign = -1;
        operand++;
    }
    while (operand[i] != '\0')
    {
        if (operand[i] >= '0' && operand[i] <= '9')
            size++;
        i++;
    }
    i = 0;
    while (operand[i] != '\0' && operand[i] != '.')
        i++;
    ini.decimal_point = i;

    ini.total_size = size;
    int *digits = (int *)malloc(sizeof(int) * size);
    i = 0;
    while (operand[i] != '\0')
    {
        if (operand[i] >= '0' && operand[i] <= '9')
        {
            digits[j] = operand[i] - '0';
            j++;
        }
        i++;
    }
    ini.total_digit = digits;
    return (ini); 
}

void alignNumber(number *n, number tx, number ty)
{
    n->total_size  = max(tx.decimal_point, ty.decimal_point) + max(tx.total_size - tx.decimal_point, ty.total_size - ty.decimal_point);
    n->decimal_point = max(tx.decimal_point, ty.decimal_point);
    n->total_digit = (int *)malloc(sizeof(int) * n->total_size);
}

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        int i;
        int j;

        // input validity considertaion
        // string or something that are not a digit.
        if (checkNumber(argv[1]) == false || checkNumber(argv[3]) == false || checkOperator(argv[2]) == false)
        {
            //Error Message
            if (checkNumber(argv[1]) == false || checkNumber(argv[3]) == false)
                printf("Invalid Format of Operand Input.\n");
            if (checkOperator(argv[2]) == false)
                printf("Invalid Format of Operator Input.\n");
            printf("Please check your input.\n");
            return (0);
        }
        

        number tx = setNumber(argv[1]);
        number ty = setNumber(argv[3]);
        number x;
        number y;
        number result;

        alignNumber(&x, tx, ty);
        x.sign = tx.sign;
        for (int i = 0; i < x.total_size; i++)
            x.total_digit[i] = 0;
        i = x.decimal_point - tx.decimal_point;
        j = 0;
        while (j < tx.total_size)
        {
            x.total_digit[i] = tx.total_digit[j];
            i++;
            j++;
        }
        alignNumber(&y, tx, ty);
        y.sign = ty.sign;
        for (int i = 0; i < y.total_size; i++)
            y.total_digit[i] = 0;
        i = y.decimal_point - ty.decimal_point;
        j = 0;
        while (j < ty.total_size)
        {
            y.total_digit[i] = ty.total_digit[j];
            i++;
            j++;
        }

        if (argv[2][0] == '+' && argv[2][1] == '\0')
            result = plus(x, y);
        else if (argv[2][0] == '-' && argv[2][1] == '\0')
            result = minus(x, y);
        else if (argv[2][0] == '*' && argv[2][1] == '\0')
            result = asterisk(x, y);
        /*
        else if (argv[2][0] == '/' && argv[2][1] == '\0')
            result = slash(x, y);
        */
        
        for (int i = 0; i < x.total_size; i++)
        {
            printf("%d ", x.total_digit[i]);
        }
        printf("\ndecimal point = %d", x.decimal_point);
        printf("\nsign = %d\n", x.sign);

        for (int i = 0; i < y.total_size; i++)
        {
            printf("%d ", y.total_digit[i]);
        }
        printf("\ndecimal point = %d", y.decimal_point);
        printf("\nsign = %d\n", y.sign);

        for (int i = 0; i < result.total_size; i++)
        {
            printf("%d ", result.total_digit[i]);
        }
        printf("\ndecimal point = %d", result.decimal_point);
        printf("\nsign = %d\n", result.sign);
        
    }
    else
        printf("Few input argument.\n");
    return (0);
}