#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "operator.h"

#define RANGE 1000;

number slash(number x, number y)
{
    unsigned long i;
    unsigned long tmp;
    unsigned long digits;
    unsigned long count;
    number result;

    result.sign = x.sign * y.sign;
    result.total_size = RANGE;
    result.total_digit = (int *)calloc(result.total_size, sizeof(int));

    if (y.total_size == 1 && y.total_digit[0] == 0)
    {
        result.sign == 0;
        return (result);
    }
    /*
    뭘 해야하는가?
    1. y - x의 결과가 음수인지 판단.
        1-1. 양수일 때,
            음수일 때까지 조진다.
            조진 개수를 센다.
            음수가 되면 그만. -> 조진 개수 -> 정수부
        1-2. 음수일 때,
            소수부로 넘어가야함.
            y * 10 (왼쪽으로 넘기기), alignNumber x & y
    2. 종료 조건.
        2-1. 표현 가능 범위 내에서 나누어 떨어지는 순간.
        2-2. 표현 가능 범위 초과.
    */

    // 정수부
    while (minus(y, x).sign == 1)
    {
        if (count == ULONG_MAX)
        {
            result.total_digit = NULL;
            return (result);
        }
        count++;
        y = minus(y, x);
    }

    //정수부 배열 넣기
    digits = 0;
    tmp = count;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        digits++;
    }
    while (i < digits)
    {
        result.total_digit[i] = tmp / power_ul(10, digits - i);
        tmp = tmp % power_ul(10, digits - i);
        i++;
    }
    result.decimal_point = i;
    
    // 소수부
    while (i < RANGE)
    {
        // 자리 한 칸 땡겨오는거
        shift(y.total_digit, y.total_size);

        // 빼면서 count 세 (음수 나올 때 까지만!!!, 만약에 0 나오면 즉시 break)
        while ()
        {

        }
        
        // count를 total_digit[i]에 넣어

        i++;
    }
    return (result);
}