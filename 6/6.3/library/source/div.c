#include "div.h"
#include <stdio.h>

double div(double a, double b)
{
    if (b == 0) 
    {
        printf("Ошибка: Деление на ноль\n");
        return 0;
    }
    return a / b;
}