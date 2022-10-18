#include <stdlib.h>
#include "operator.h"

number asterisk(number x, number y)
{
    number result;

    result.sign = 1;
    if (x.sign * y.sign == -1)
        result.sign = -1;
    result.total_size = x.total_size + y.total_size;
    
}