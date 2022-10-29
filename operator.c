#include <stdlib.h>
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
    
    n->total_size++;
    n->decimal_point++;
    
    n->total_digit = (int *)calloc(n->total_size, sizeof(int));
}

int abs_compare(int *one, int *two, int size)
{
    int i = 0;
    while (one[i] == two[i] && i < size - 1)
        i++;
    return (one[i] - two[i]);
}

unsigned long power_ul(unsigned long x, unsigned long y)
{
    unsigned long result = 1;
    while (y > 0)
    {
        result = result * x;
        y--;
    }
    return (result);
}