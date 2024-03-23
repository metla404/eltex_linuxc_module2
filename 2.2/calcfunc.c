#include "calcfunc.h"
#include <stdio.h>

double add_numbers(double a, double b)
{
    return a + b;
}

double subtract_numbers(double a, double b)
{
    return a - b;
}

double multiply_numbers(double a, double b)
{
    return a * b;
}

double divide_numbers(double a, double b)
{
    if (b == 0) {
        printf("Ошибка: Деление на ноль\n");
        return 0;
    }
    return a / b;
}

void calculator_menu()
{
    int choice;
    double num1, num2;

    while (1) {
        printf("\nВыберите действие:\n");
        printf("1. Сложение\n");
        printf("2. Вычитание\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Выход\n");
        printf("Введите номер действия: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите первое число: ");
                scanf("%lf", &num1);
                printf("Введите второе число: ");
                scanf("%lf", &num2);
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, add_numbers(num1, num2));
                break;
            case 2:
                printf("Введите первое число: ");
                scanf("%lf", &num1);
                printf("Введите второе число: ");
                scanf("%lf", &num2);
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, subtract_numbers(num1, num2));
                break;
            case 3:
                printf("Введите первое число: ");
                scanf("%lf", &num1);
                printf("Введите второе число: ");
                scanf("%lf", &num2);
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, multiply_numbers(num1, num2));
                break;
            case 4:
                printf("Введите первое число: ");
                scanf("%lf", &num1);
                printf("Введите второе число: ");
                scanf("%lf", &num2);
                if (divide_numbers(num1, num2) != 0) {
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, divide_numbers(num1, num2));
                }
                break;
            case 5:
                printf("Выход...\n");
                return;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}