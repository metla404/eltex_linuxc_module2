#include <stdio.h>
#include <string.h>
#include "telbookfunc.h"


void print_people(people people_array[], int *c)
{
    printf("Количество людей: %d\n", *c);
    for(int i=0; i<*c; i++)
    {
        people temp = people_array[i];
        printf("\n%d. \nФИО - %s %s %s\n", i+1, temp.first_name, temp.surname, temp.patronymic);
        printf("Место работы -  %-5s\n", temp.workplace);
        printf("Должность -     %-5s\n", temp.job);
        printf("Номера телефонов:\n");
        for(int j=0; j<5; j++){
            printf("     %-5s\n", temp.phone[j]);
        }
        printf("Cоц. сети:\n");
        for(int j=0; j<5; j++){
            printf("     %-5s\n", temp.socials[j]);
        }
        printf("Электронная почта:\n");
        for(int j=0; j<5; j++){
        printf("     %-5s\n", temp.email[j]);
        }
    }
}

void add(people people_list[], int *c)
{
    //people p = {"none","none","none",
    //            "none","none","none","none","none",
    //            "none","none","none","none","none",
    //            "none","none","none","none","none",
    //            "none", "none"
    //            };
    people p = {0};
    printf("Введите имя:\n");
    scanf("%s",&p.first_name);
    printf("Введите фамилию:\n");
    scanf("%s",&p.surname);
    printf("Введите отчество:\n");
    scanf("%s",&p.patronymic);
    printf("Введите телефоны:\n");
    for(int j=0; j<6; j++)
    {
        scanf("%s", &p.phone[j]);
    }
    printf("Введите электронные адреса:\n");
    for(int j=0; j<6; j++)
    {
        scanf("%s", &p.email[j]);
    }
    printf("Введите соц.сети:\n");
    for(int j=0; j<6; j++)
    {
        scanf("%s", &p.socials[j]);
    }
    printf("Введите место работы:\n");
    scanf("%s",&p.workplace);
    printf("Введите должность:\n");
    scanf("%s",&p.job);

    people_list[*c]=p;
    *c+=1;
}

void rem(people people_list[], int *c)
{
    int index;
    printf("Введите номер удаляемого пользователя:\n");
    scanf("%d", &index);

    if (index >= 1 && index <= *c) {
        for (int i = index - 1; i < *c - 1; i++) {
            people_list[i] = people_list[i + 1];
        }
        *c -= 1;
        printf("Человек успешно удален.\n");
    } else {
        printf("Неверный номер пользователя.\n");
    }
}

void edit(people people_list[], int* c)
{
    int chck = 0;
    int user_index;

    while(chck == 0)
    {
        printf("Введите номер редактируемого пользователя (от 1 до %d):\n", *c);
        scanf("%d", &user_index);

        if (user_index >= 1 && user_index <= *c) {
            --user_index;

            int chck1;
            printf("Какой параметр хотите редактировать?\n");
            printf("   1. Имя\n   2. Фамилия\n   3. Отчество\n   4. Номера телефонов\n"
                   "   5. Адреса эл. почты\n   6. Соц. сети\n   7. Место работы\n   8. Должность\n");
            scanf("%d",&chck1);

            switch(chck1)
            {
                case 1:
                    printf("Введите новое имя:\n");
                    scanf("%s", people_list[user_index].first_name);
                    break;
                case 2:
                    printf("Введите новую фамилию:\n");
                    scanf("%s", people_list[user_index].surname);
                    break;
                case 3:
                    printf("Введите новое отчество:\n");
                    scanf("%s", people_list[user_index].patronymic);
                    break;
                case 4:
                    for (int j = 0; j < 5; ++j) 
                    {
                        printf("Введите новый номер телефона %d:\n", j + 1);
                        scanf("%s", people_list[user_index].phone[j]);
                    }
                    break;
                case 5:
                    for (int j = 0; j < 5; ++j) 
                    {
                        printf("Введите новый адрес электронной почты %d:\n", j + 1);
                        scanf("%s", people_list[user_index].email[j]);
                    }
                    break;
                case 6:
                    for (int j = 0; j < 5; ++j) 
                    {
                        printf("Введите новую ссылку на соц. сеть %d:\n", j + 1);
                        scanf("%s", people_list[user_index].socials[j]);
                    }
                    break;
                case 7:
                    printf("Введите новое место работы:\n");
                    scanf("%s", people_list[user_index].workplace);
                    break;
                case 8:
                    printf("Введите новую должность:\n");
                    scanf("%s", people_list[user_index].job);
                    break;
                default:
                    break;
            }

            printf("Выйти - 9, остаться - 0\n");
            scanf("%d", &chck);
        } else {
            printf("Неверный номер пользователя.\n");
        }
    }
}
