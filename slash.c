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
    result.total_size = RANGE;
    result.total_digit = (int *)calloc(result.total_size, sizeof(int));

    if (isZero(y) == true)
    {
        result.sign = 0;
        return (result);
    }
    i = 0;
    // 정수부 구하기

    while (minus(x, y).sign == 1)
    {
        printf("1!\n");
        print_num(x);
        printf("\n");
        if (count == ULONG_MAX)
        {
            result.total_digit = NULL;
            return (result);
        }
        count++;
        if (abs_compare(x.total_digit, y.total_digit, x.total_size) < 0)
            break;
        x = minus(x, y);
        y = refresh(y, x);
    }

    //정수부 배열 넣기
    digits = 0;
    tmp = count;
    while (tmp != 0)
    {
        printf("2!\n");
        tmp = tmp / 10;
        digits++;
    }
    while (i < digits)
    {
        printf("3!\n");
        result.total_digit[i] = tmp / power_ul(10, digits - i);
        tmp = tmp % power_ul(10, digits - i);
        i++;
    }
    result.decimal_point = i;
    
    // 소수부
    while (i < RANGE)
    {
        printf("4!\n");
        // 자리 한 칸 땡겨오는거
        shift(x.total_digit, x.total_size);

        // 빼면서 count 세기 (음수 나오기 전까지만!!!, 만약에 0 나오면 즉시 break)
        count = 0;
        while (minus(x, y).sign == 1);
        {
            printf("5!\n");
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