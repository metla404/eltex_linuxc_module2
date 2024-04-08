#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <dirent.h>
#include "calcmenufunc.h"

void calculator_menu(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct operation operations[4];

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    size_t num_operations = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_REG) {
            continue;
        }

        char lib_path[1024];
        snprintf(lib_path, sizeof(lib_path), "%s/%s", path, entry->d_name);

        void *handle = dlopen(lib_path, RTLD_LAZY);
        if (!handle) {
            fprintf(stderr, "dlsym: %s\n", dlerror());
            continue;
        }

        char *lib_name = strdup(entry->d_name);
        lib_name[strlen(lib_name) - 3] = '\0'; // удаляем расширение .so

        if (strcmp(lib_name, "libadd") == 0) {
            operations[num_operations].name = "+";
            operations[num_operations].func = dlsym(handle, "add");
        } else if (strcmp(lib_name, "libsub") == 0) {
            operations[num_operations].name = "-";
            operations[num_operations].func = dlsym(handle, "sub");
        } else if (strcmp(lib_name, "libmul") == 0) {
            operations[num_operations].name = "*";
            operations[num_operations].func = dlsym(handle, "mul");
        } else if (strcmp(lib_name, "libdiv") == 0) {
            operations[num_operations].name = "/";
            operations[num_operations].func = dlsym(handle, "div");
        } else {
            dlclose(handle);
            free(lib_name);
            continue;
        }

        num_operations++;
    }

    closedir(dir);

    while (1) {
        printf("\nВыберите действие:\n");
        print_op(operations, num_operations);
        printf("%zu. Выход\n", num_operations + 1);
        printf("Введите номер действия: ");

        size_t choice;
        scanf("%zu", &choice);

        if (choice <= num_operations) {
            double num1, num2;

            while (1) {
                printf("Введите первое число: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (getchar() != '\n') {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }

            while (1) {
                printf("Введите второе число: ");
                if (scanf("%lf", &num2) != 1) {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (getchar() != '\n') {
                    printf("Неверный ввод. Попробуйте снова.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }

            double result = operations[choice - 1].func(num1, num2);
            if (result != 0) {
                printf("%.2lf %s %.2lf = %.2lf\n", num1, operations[choice - 1].name, num2, result);
            }
        } else if (choice == num_operations + 1) {
            printf("Выход...\n");
            break;
        } else {
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}

void print_op(const struct operation operations[], size_t operation_num)
{
    for(size_t i=0; i<operation_num; i++)
    {
        printf("%d. %s\n", i+1, operations[i].name);
    }
}
