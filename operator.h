#include "number.h"
#ifndef OPERATOR_H
#define OPERATOR_H

int abs_compare(int *one, int *two, int size);

void alignNumber(number *n, number tx, number ty);

number plus(number x, number y);
number minus(number x, number y);
number asterisk(number x, number y);
number slash(number x, number y);

#endif