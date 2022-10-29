#include <stdlib.h>
#include <stdio.h>
#include "operator.h"

number asterisk(number x, number y)
{
    number result;
    int i, j, k;
    
    // result initialization
    result.sign = 1;
    if (x.sign * y.sign == -1)
        result.sign = -1;
    result.total_size = x.total_size + y.total_size - 1;
    result.decimal_point = x.decimal_point + y.decimal_point;
    result.total_digit = (int *)malloc(result.total_size * sizeof(int));
    for (int i = 0; i < result.total_size; i++)
        result.total_digit[i] = 0;
    
    // multiplication
    i = result.total_size - 1;
    k = y.total_size - 1;
    while (k >= 0)
    {
        int tmp = 0;
        j = x.total_size - 1;
        while (j >= 0)
        {
            result.total_digit[i - (x.total_size - 1) + j] += (x.total_digit[j] * y.total_digit[k] + tmp) % 10;
            tmp = (x.total_digit[j] * y.total_digit[k] + tmp) / 10;
            for (int i = 0; i < result.total_size; i++)
            {
                printf("%d ", result.total_digit[i]);
            }
            printf("\n");
            j--;
        }
        k--;
        i--;
    }
    return (result);
}