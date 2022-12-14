#include "operator.h"
#define RANGE 1000

number slash(number x, number y)
{
    unsigned long i;
    unsigned long tmp;
    unsigned long digits;
    unsigned long count;
    number result;

    result.sign = x.sign * y.sign;
    x.sign = 1;
    y.sign = 1;
    result.total_size = RANGE;
    result.total_digit = (int *)calloc(result.total_size, sizeof(int));

    if (isZero(y) == true)
    {
        result.sign = 0;
        return (result);
    }
    
    // 정수부 구하기
    count = 0;
    while (minus(x, y).sign == 1)
    {
        number tx;
        number ty;
        if (count == ULONG_MAX)
        {
            result.total_digit = NULL;
            return (result);
        }
        count++;
        tx = minus(x, y);
        ty = refresh(y, tx);
        if (abs_compare(tx.total_digit, ty.total_digit, ty.total_size) < 0)
            break;
        x = tx;
        y = ty;
    }

    //정수부 배열 넣기
    i = 0;
    digits = 0;
    tmp = count;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        digits++;
    }
    while (i < digits)
    {
        result.total_digit[i] = (int) (count / power_ul(10, digits - i - 1));
        count = count % power_ul(10, digits - i - 1);
        i++;
    }
    result.decimal_point = i;

    // 소수부
    if (minus(x, y).sign == 1)
    {
        x = minus(x, y);
        y = refresh(y, x);
    }
    else if (abs_compare(x.total_digit, y.total_digit, x.total_size) < 0 && x.total_size == y.total_size && x.decimal_point == y.decimal_point)
    {
        int *tmp;
        tmp = (int *)calloc(x.total_size + 1, sizeof(int));
        for (int o = 1; o < x.total_size + 1; o++)
            tmp[o] = x.total_digit[o - 1];
        x.total_digit = tmp;
        x.total_size++;
        x.decimal_point++;
        tmp = (int *)calloc(y.total_size + 1, sizeof(int));
        for (int o = 1; o < y.total_size + 1; o++)
            tmp[o] = y.total_digit[o - 1];
        y.total_digit = tmp;
        y.total_size++;
        y.decimal_point++;
    }
    while (i < RANGE)
    {      
        count = 0;
        shift(x.total_digit, x.total_size);
        while (minus(x, y).sign == 1)
        {
            number tx;
            number ty;
            count++;
            tx = minus(x, y);
            ty = refresh(y, tx);
            if (abs_compare(tx.total_digit, ty.total_digit, ty.total_size) < 0)
                break;
            x = tx;
            y = ty;
        }
        // count를 total_digit[i]에 넣어
        result.total_digit[i] = count % 10;
        i++;
    }
    return (result);
}