#include "calcmenufunc.h"
#include "calcnewfunc.h"
#include <stdio.h>

void calculator_menu(const struct operation operations[], size_t operation_num)
{
    while (1) 
    {
        printf("\nВыберите действие:\n");
        print_op(operations, operation_num);
        printf("%zu. Выход\n", operation_num + 1);
        printf("Введите номер действия: ");

        size_t choice;
        scanf("%zu", &choice);

        if (choice <= operation_num) 
        {
            double num1, num2;
            
            while (1) 
            {
                printf("Введите первое число: ");
                if (scanf("%lf", &num1) != 1) 
                {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (getchar() != '\n') 
                {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }

            while (1) 
            {
                printf("Введите второе число: ");
                if (scanf("%lf", &num2) != 1) 
                {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                if (getchar() != '\n') 
                {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }

            double result = operations[choice - 1].func(num1, num2);
            if (result != 0) 
            {
                printf("%.2lf %s %.2lf = %.2lf\n", num1, operations[choice - 1].name, num2, result);
            }
        } 
        else if (choice == operation_num + 1) 
        {
            printf("Выход...\n");
            break;
        } 
        else 
        {
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}