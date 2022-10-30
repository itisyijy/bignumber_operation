#include "operator.h"

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        int i;
        int j;

        // input validity considertaion
        // string or something that are not a digit.
        if (checkNumber(argv[1]) == false || checkNumber(argv[3]) == false || checkOperator(argv[2]) == false)
        {
            //Error Message
            if (checkNumber(argv[1]) == false || checkNumber(argv[3]) == false)
                printf("Invalid Format of Operand Input.\n");
            if (checkOperator(argv[2]) == false)
                printf("Invalid Format of Operator Input.\n");
            printf("Please check your input.\n");
            return (0);
        }
        
        number tx = setNumber(argv[1]);
        number ty = setNumber(argv[3]);
        number x;
        number y;
        number result;

        alignNumber(&x, tx, ty);
        x.sign = tx.sign;
        i = x.decimal_point - tx.decimal_point;
        j = 0;
        while (j < tx.total_size)
        {
            x.total_digit[i] = tx.total_digit[j];
            i++;
            j++;
        }
        alignNumber(&y, tx, ty);
        y.sign = ty.sign;
        i = y.decimal_point - ty.decimal_point;
        j = 0;
        while (j < ty.total_size)
        {
            y.total_digit[i] = ty.total_digit[j];
            i++;
            j++;
        }

        print_num(x);
        printf(" %c ", argv[2][0]);
        print_num(y);
        printf(" = ");

        if (argv[2][0] == '+' && argv[2][1] == '\0')
            result = plus(x, y);
        else if (argv[2][0] == '-' && argv[2][1] == '\0')
            result = minus(x, y);
        else if (argv[2][0] == '*' && argv[2][1] == '\0')
            result = asterisk(x, y);
        else if (argv[2][0] == '/' && argv[2][1] == '\0')
            result = slash(x, y);
        
        if (result.sign == 0)
        {
            printf("Divide by ZERO!\n");
            return (0);
        }
        if (result.total_digit == NULL)
        {
            printf("Quotient Overflow Occurs.\n");
            return (0);
        }
        print_num(result);
        printf("\n");
    }
    else if (argc < 4)
    {
        printf("Few input argument.\n");
        printf("Please, check your inputs.\n");
    }
    else if (argc > 4)
    {
        printf("Too Much input argument.\n");
        printf("Please, check your inputs.\n");
    }
    return (0);
}