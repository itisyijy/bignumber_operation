#include <stdlib.h>
#include "operator.h"

#define RANGE 1000;

number slash(number x, number y)
{
    number result;
    result.sign = x.sign * y.sign;
    result.total_size = RANGE;
    result.total_digit = (int *)calloc(result.total_size, sizeof(int));

    /*
    뭘 해야하는가?
    0. 자릿수 여유 공간을 확보한다.
        x랑 y 둘 다 한칸씩을 왼쪽에 확보를 해준다. 
    1. y - x의 결과가 음수인지 판단.
        1-1. 양수일 때,
            음수일 때까지 조진다.
            조진 개수를 센다.
            음수가 되면 그만. -> 조진 개수 -> 정수부
        1-2. 음수일 때,
            소수부로 넘어가야함.
            y * 10 (왼쪽으로 넘기기) realloc, alignNumber x & y
    2. 종료 조건.
        2-1. 표현 가능 범위 내에서 나누어 떨어지는 순간.
        2-2. 표현 가능 범위 초과.
    */
    

    
}