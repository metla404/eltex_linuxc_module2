#include <stdio.h>
#include <string.h>
#include "telbookfunc.h"


int main()
{
    people people_list[10];
    int count = 0;
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
                print_people(people_list, &count);
                break;
            case 2:
                add(people_list, &count);
                break;
            case 3:
                rem(people_list, &count);
                break;
            case 4:
                edit(people_list, &count);
                break;
            case 5:
                return 0;
            default:
                break;
        }
    }
    return 0;
}