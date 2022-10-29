#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "number.h"

#ifndef OPERATOR_H
#define OPERATOR_H

#define max(a,b) (((a) > (b)) ? (a) : (b))

int abs_compare(int *one, int *two, int size);

void alignNumber(number *n, number tx, number ty);
bool checkNumber(char *operand);
bool checkOperator(char *operand);
number setNumber(char *operand);

unsigned long power_ul(unsigned long x, unsigned long y);
void shift(int* number, int size);
number refresh(number x, number y);
int isZero(number x);
void print_num(number num);

number plus(number x, number y);
number minus(number x, number y);
number asterisk(number x, number y);
number slash(number x, number y);

#endif