#include <stdio.h>
#include <string.h>
#include "telbookfunc.h"

int main()
{
    Node* head = NULL;
    int chck;

    while(1)
    {
        printf("1. Вывести людей\n"
        "2. Добавить человека\n" 
        "3. Удалить человека\n"
        "4. Редактировать человека\n" 
        "5. Выйти\n");
        scanf("%d", &chck);
        switch(chck)
        {
            case 1:
                print_people(head);
                break;
            case 2:
            {
                people p;
                printf("Введите имя:\n");
                scanf("%s", p.first_name);
                printf("Введите фамилию:\n");
                scanf("%s", p.surname);
                printf("Введите отчество:\n");
                scanf("%s", p.patronymic);
                printf("Введите телефоны:\n");
                for(int j=0; j<5; j++)
                {
                    scanf("%s", p.phone[j]);
                }
                printf("Введите электронные адреса:\n");
                for(int j=0; j<5; j++)
                {
                    scanf("%s", p.email[j]);
                }
                printf("Введите соц.сети:\n");
                for(int j=0; j<5; j++)
                {
                    scanf("%s", p.socials[j]);
                }
                printf("Введите место работы:\n");
                scanf("%s", p.workplace);
                printf("Введите должность:\n");
                scanf("%s", p.job);

                add(&head, p);
                break;
            }
            case 3:
            {
                int index;
                printf("Введите номер удаляемого пользователя:\n");
                scanf("%d", &index);
                rem(&head, index);
                break;
            }
            case 4:
            {
                int index;
                printf("Введите номер редактируемого пользователя:\n");
                scanf("%d", &index);
                edit(&head, index);
                break;
            }
            case 5:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
