#include <stdio.h>
#include "func_rwx.h"

int main(int argc, char* argv[]) 
{
    struct stat st;
    char permissions[3][N];
    char binary[3][N];
    char perm_in[N];
    int oct_perms[] = {0, 0, 0};
    int choice;
    int stmode;

    printf("\nВыберите действие:\n"
        "1. Права доступа в битовом представлении\n"
        "2. Права доступа файла\n"
        "Чтобы выйти - нажмите любую другую цифру\n");
    
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1:
            if(argc != 2) 
            {
                printf("Нужен один параметр\n");
                return 1;
            }

            if(num_check(argv[1])) 
            {
                stmode = atoi(argv[1]);
                oct_to_binary(stmode, binary, permissions);
            }
            else 
            {
                if(strlen(argv[1]) != 9) 
                {
                    printf("Длина текстовых прав доступа не должна превышать 9 символов!\n");
                    return 1;
                }
                char_to_bin(argv[1], binary);
            }
            bin_to_perm(binary, oct_perms, permissions);
            printf("\nБинарное представление: ");

            for (int i = 0; i < 3; i++)
                printf("%s", binary[i]);

            break;

        case 2:
            if(argc != 2) 
            {
                printf("Нужен один параметр\n");
                return 1;
            }

            if (stat(argv[1], &st) == -1) 
            {
                perror("stat");
                return 1;
            }
            stmode = st.st_mode;
            stmode = dec_to_oct(stmode);

            oct_to_binary(stmode, binary, permissions);
            bin_to_perm(binary, oct_perms, permissions);
            print_perms(permissions, oct_perms, binary);

            break;

        default:
            return 0;
    }

    while(true) {
        printf("\n1. Модификация прав доступа\n"
            "2. Текущие права\n"
            "Выход - любая другая цифра\n");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:

                printf("\nВведите права доступа (цифрами или буквами):\n");
                scanf("%s", perm_in);

                if(num_check(perm_in)) 
                {
                    stmode = atoi(perm_in);
                    oct_to_binary(stmode, binary, permissions);
                    bin_to_perm(binary, oct_perms, permissions);
                    print_perms(permissions, oct_perms, binary);
                }
                else 
                {
                    for (int i = 0; i < 3; i++)
                        strcpy(permissions[i],"");

                    modify_by_char(perm_in, binary);
                    bin_to_perm(binary, oct_perms, permissions);
                    print_perms(permissions, oct_perms, binary);
                }
                break;

            case 2:
                print_perms(permissions, oct_perms, binary);
                break;

            default:
                exit(0);
        }
    }
    return 0;
}
