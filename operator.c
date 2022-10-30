#include "operator.h"

bool checkNumber(char *operand)
{
    int i = 0;
    int pointCount = 0;

    if (operand[i] == '-')
        i++;
    while (operand[i] != '\0')
    {
        if (operand[i] < '0' || operand[i] > '9')
        {
            if (operand[i] == '.' && pointCount == 0)
                pointCount++;
            else
                return (false);
        }
        i++;
    }
    return (true);
}

bool checkOperator(char *operand)
{
    if (operand[0] == '+' || operand[0] == '-' || operand[0] == '*' || operand[0] == '/')
        if (operand[1] == '\0')
            return (true);
    return (false);
}

number setNumber(char *operand)
{
    int i = 0;
    int j = 0;
    int size = 0;
    number ini;

    ini.sign = 1;
    if (operand[0] == '-')
    {
        ini.sign = -1;
        operand++;
    }
    while (operand[i] != '\0')
    {
        if (operand[i] >= '0' && operand[i] <= '9')
            size++;
        i++;
    }
    i = 0;
    while (operand[i] != '\0' && operand[i] != '.')
        i++;
    ini.decimal_point = i;

    ini.total_size = size;
    int *digits = (int *)malloc(sizeof(int) * size);
    i = 0;
    while (operand[i] != '\0')
    {
        if (operand[i] >= '0' && operand[i] <= '9')
        {
            digits[j] = operand[i] - '0';
            j++;
        }
        i++;
    }
    ini.total_digit = digits;
    return (ini); 
}

void alignNumber(number *n, number tx, number ty)
{
    n->total_size  = max(tx.decimal_point, ty.decimal_point) + max(tx.total_size - tx.decimal_point, ty.total_size - ty.decimal_point);
    n->decimal_point = max(tx.decimal_point, ty.decimal_point);
    
    //n->total_size++;
    //n->decimal_point++;
    
    n->total_digit = (int *)calloc(n->total_size, sizeof(int));
}

int abs_compare(int *one, int *two, int size)
{
    int i = 0;
    while (one[i] == two[i] && i < size - 1)
        i++;
    return (one[i] - two[i]);
}

unsigned long power_ul(unsigned long x, unsigned long y)
{
    unsigned long result = 1;
    while (y > 0)
    {
        result = result * x;
        y--;
    }
    return (result);
}

void shift(int* number, int size)
{
	int i = 1;

	while (i < size)
	{
		number[i - 1] = number[i];
		number[i] = 0;
		i++;
	}
}

number refresh(number y, number x)
{
    number result;
    alignNumber(&result, x, y);
    result.sign = y.sign;
    int dp = result.decimal_point - y.decimal_point;
    int idx = 0;
    while (idx < y.total_size)
    {
        result.total_digit[dp] = y.total_digit[idx];
        dp++;
        idx++;
    }
    return (result);
}

int isZero(number x)
{
    int i = 0;
    while (i < x.total_size)
    {
        if (x.total_digit[i] != 0)
            break;
        i++;
    }
    if (i == x.total_size)
        return (1);
    return (0);
}

void print_num(number num)
{
    int i = 0;
    int end;

    if (num.sign == -1)
        printf("-");
    if (num.decimal_point == 0)
        printf("0");
    while (num.total_digit[i] == 0 && i < num.decimal_point - 1)
        i++;
    end = num.total_size - 1;
    while (num.total_digit[end] == 0 && end > num.decimal_point)
        end--;
    while (i <= end)
    {
        if (i == num.decimal_point)
            printf(".");
        printf("%d", num.total_digit[i]);
        i++;
    }
}