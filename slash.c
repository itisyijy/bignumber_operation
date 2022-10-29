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
    while (i < RANGE && isZero(minus(x, y)) == false)
    {
        // 자리 한 칸 땡겨오는거
        shift(x.total_digit, x.total_size);

        // 빼면서 count 세기 (음수 나오기 전까지만!!!, 만약에 0 나오면 즉시 break)
        count = 0;
        while (minus(x, y).sign == 1 && isZero(minus(x, y)) == false);
        {
            count++;
            if (minus(x, y).sign == -1)
                break;
            x = minus(x, y);
            y = refresh(y, x);
            int j = 0;
            while (x.total_digit[j] == 0)
                j++;
            if (j == x.total_size) // y가 0이면
                break;
        }

        // count를 total_digit[i]에 넣어
        result.total_digit[i] = count;
        i++;
    }
    return (result);
}