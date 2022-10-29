#include "operator.h"

number asterisk(number x, number y)
{
    number result;
    int i, j, k;
    
    // result initialization
    result.sign = x.sign * y.sign;
    result.total_size = x.total_size + y.total_size;
    result.decimal_point = x.decimal_point + y.decimal_point;
    result.total_digit = (int *)calloc(result.total_size, sizeof(int));
    
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
            j--;
        }
        k--;
        i--;
    }

    // rounding
    i = result.total_size - 1;
    while (i > 0)
    {
        result.total_digit[i - 1] += result.total_digit[i] / 10;
        result.total_digit[i] = result.total_digit[i] % 10;
        i--;
    }
    return (result);
}