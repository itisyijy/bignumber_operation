#include <stdio.h>
#include <stdlib.h>
#include "number.h"
#include "operator.h"

int main()
{
    number num = setNumber("123412341234123412341234.12341234");

    printf("num sign\t\t= %d\n", num.sign);
    printf("num total_size\t\t= %d\n", num.total_size);
    printf("num total_digit\t\t= ");
    for (int i = 0; i < num.total_size; i++)
        printf("%d", num.total_digit[i]);
    printf("\n");
    printf("num decimal point\t= %d\n", num.decimal_point);

    printf("num\t\t\t= ");
    int i = 0;
    while (num.total_digit[i] == 0 && num.decimal_point - i - 1 >= 0)
        i++;
    while (i < num.total_size)
    {
        printf("%d", num.total_digit[i]);
        if (i == num.decimal_point - 1)
            printf(".");
        i++;
    }
    printf("\n");
}