#include <stdbool.h>
#include "number.h"

#ifndef OPERATOR_H
#define OPERATOR_H

int abs_compare(int *one, int *two, int size);

void alignNumber(number *n, number tx, number ty);
bool checkNumber(char *operand);
bool checkOperator(char *operand);
number setNumber(char *operand);

number plus(number x, number y);
number minus(number x, number y);
number asterisk(number x, number y);
number slash(number x, number y);

#endif