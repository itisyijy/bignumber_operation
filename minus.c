#include "operator.h"

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