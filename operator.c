#include <stdlib.h>
#include "operator.h"

int abs_compare(int *one, int *two, int size)
{
    int i = 0;
    while (one[i] == two[i] && i < size - 1)
        i++;
    return (one[i] - two[i]);
}

number plus(number x, number y)
{
    number result;
    int i;
    int j;
    int abs_size = abs_compare(x.total_digit, y.total_digit, x.total_size);
  
    result.total_size = x.total_size + 1;
    result.total_digit = (int *)malloc(sizeof(int) * (x.total_size + 1));
    result.decimal_point = x.decimal_point + 1;
    for (int k = 0; k < result.total_size; k++)
        result.total_digit[k] = 0;
    if (abs_size > 0) // x의 절댓값이 더 크다
    {
        if (x.sign > 0) // x가 양수다
        {
            if (y.sign > 0) // y가 양수다
            {
                // 그냥 절댓값 더해
                result.sign = 1;
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = x.total_digit[i];
                    j--;
                    i--;
                }
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] += y.total_digit[i];
                    if (result.total_digit[j] >= 10)
                    {
                        result.total_digit[j - 1]  += result.total_digit[j] / 10;
                        result.total_digit[j] = result.total_digit[j] % 10;
                    }
                    j--;
                    i--;
                }
            }
            else // y가 음수다
            {
                // (abs) x에서 y 빼기
                result.sign = 1;
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = x.total_digit[i];
                    j--;
                    i--;
                }
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    if (result.total_digit[j] < y.total_digit[i])
                    {
                        result.total_digit[j - 1]--;
                        result.total_digit[j] += 10;
                    }
                    result.total_digit[j] -= y.total_digit[i];
                    j--;
                    i--;
                }
            }
        }
        else // x가 음수다
        {
            if (y.sign > 0) // y가 양수다 
            {
                // x에서 y를 빼고 부호를 -로
                result.sign = -1;
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = x.total_digit[i];
                    j--;
                    i--;
                }
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    if (result.total_digit[j] < y.total_digit[i])
                    {
                        result.total_digit[j - 1]--;
                        result.total_digit[j] += 10;
                    }
                    result.total_digit[j] -= y.total_digit[i];
                    j--;
                    i--;
                }
            }
            else // y가 음수다 
            {
                // 그냥 더하고 부호를 -로
                result.sign = -1;
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = x.total_digit[i];
                    j--;
                    i--;
                }
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] += y.total_digit[i];
                    if (result.total_digit[j] >= 10)
                    {
                        result.total_digit[j - 1]  += result.total_digit[j] / 10;
                        result.total_digit[j] = result.total_digit[j] % 10;
                    }
                    j--;
                    i--;
                }
            }
        }
    }
    else if (abs_size < 0) // x의 절댓값이 더 작다
    {
        if (x.sign > 0) // x가 양수다
        {
            if (y.sign > 0) // y가 양수다
            {
                // 그냥 더해
                result.sign = 1;
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = x.total_digit[i];
                    j--;
                    i--;
                }
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] += y.total_digit[i];
                    if (result.total_digit[j] >= 10)
                    {
                        result.total_digit[j - 1]  += result.total_digit[j] / 10;
                        result.total_digit[j] = result.total_digit[j] % 10;
                    }
                    j--;
                    i--;
                }
            }
            else // y가 음수다
            {
                // y에서 x 빼고 부호를 -로
                result.sign = -1;
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = y.total_digit[i];
                    j--;
                    i--;
                }
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    if (result.total_digit[j] < x.total_digit[i])
                    {
                        result.total_digit[j - 1]--;
                        result.total_digit[j] += 10;
                    }
                    result.total_digit[j] -= x.total_digit[i];
                    j--;
                    i--;
                }
            }
        }
        else // x가 음수다
        {
            if (y.sign > 0) // y가 양수다 
            {
                // y에서 x를 빼기
                result.sign = 1;
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = y.total_digit[i];
                    j--;
                    i--;
                }
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    if (result.total_digit[j] < x.total_digit[i])
                    {
                        result.total_digit[j - 1]--;
                        result.total_digit[j] += 10;
                    }
                    result.total_digit[j] -= x.total_digit[i];
                    j--;
                    i--;
                }
            }
            else // y가 음수다 
            {
                // 그냥 더하고 부호를 -로
                result.sign = -1;
                i = x.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] = x.total_digit[i];
                    j--;
                    i--;
                }
                i = y.total_size - 1;
                j = result.total_size - 1;
                while (i >= 0)
                {
                    result.total_digit[j] += y.total_digit[i];
                    if (result.total_digit[j] >= 10)
                    {
                        result.total_digit[j - 1]  += result.total_digit[j] / 10;
                        result.total_digit[j] = result.total_digit[j] % 10;
                    }
                    j--;
                    i--;
                }
            }
        }
    }
    else // x와 y의 절댓값이 같다
    {
        if (x.sign > 0 && y.sign > 0)
        {
            // 그냥 더해
            result.sign = 1;
            i = x.total_size - 1;
            j = result.total_size - 1;
            while (i >= 0)
            {
                result.total_digit[j] = x.total_digit[i];
                j--;
                i--;
            }
            i = y.total_size - 1;
            j = result.total_size - 1;
            while (i >= 0)
            {
                result.total_digit[j] += y.total_digit[i];
                if (result.total_digit[j] >= 10)
                {
                    result.total_digit[j - 1]  += result.total_digit[j] / 10;
                    result.total_digit[j] = result.total_digit[j] % 10;
                }
                j--;
                i--;
            }
        }
        else if (x.sign < 0 && y.sign < 0)
        {
            // 그냥 더하고 부호를 -로
            result.sign = -1;
            i = x.total_size - 1;
            j = result.total_size - 1;
            while (i >= 0)
            {
                result.total_digit[j] = x.total_digit[i];
                j--;
                i--;
            }
            i = y.total_size - 1;
            j = result.total_size - 1;
            while (i >= 0)
            {
                result.total_digit[j] += y.total_digit[i];
                if (result.total_digit[j] >= 10)
                {
                    result.total_digit[j - 1]  += result.total_digit[j] / 10;
                    result.total_digit[j] = result.total_digit[j] % 10;
                }
                j--;
                i--;
            }
        }
        else
        {
            // 0
            result.sign = 1;
        }
    }
    return (result);
}

number minus(number x, number y)
{
    number result;
    
    if (y.sign < 0)
        y.sign = 1;
    else
        y.sign = -1;
    result = plus(x, y);
    return (result);
}

number asterisk(number x, number y)
{
    number result;

    result.sign = 1;
    if (x.sign * y.sign == -1)
        result.sign = -1;
    
}