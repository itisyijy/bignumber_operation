#include <stdlib.h>
#include "operator.h"

number asterisk(number x, number y)
{
    number result;
    int i, j, k;
    
    // result initialization
    result.sign = 1;
    if (x.sign * y.sign == -1)
        result.sign = -1;
    result.total_size = x.total_size + y.total_size;
    result.decimal_point = x.decimal_point + y.decimal_point;
    result.total_digit = (int *)malloc(result.total_size * sizeof(int));
    for (int i = 0; i < result.total_size; i++)
        result.total_digit[i] = 0;
    
    // multiplication
    i = result.total_size - 1;
    k = y.total_size - 1;
    while (i >= 0)
    {
        j = x.total_size - 1;
        while (j >= 0)
        {
            
            j--;
        }
        i--;
    }
    return (result);
}