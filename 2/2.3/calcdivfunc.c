#include "calcdivfunc.h"
#include <stdio.h>

double divide_numbers(double a, double b)
{
    if (b == 0) 
    {
        printf("Ошибка: Деление на ноль\n");
        return 0;
    }
    return a / b;
}