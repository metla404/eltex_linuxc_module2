#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "telbookfunc.h"

void print_people(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        people temp = current->data;
        printf("\n%d. \nФИО - %s %s %s\n", ++count, temp.first_name, temp.surname, temp.patronymic);
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
        current = current->next;
    }
}

void add(Node** head, people p)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && strcmp(current->data.surname, p.surname) < 0)
        current = current->next;

    if (current == *head && strcmp(current->data.surname, p.surname) > 0)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

void rem(Node** head, int index)
{
    Node* current = *head;
    int count = 1;

    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Неверный номер пользователя.\n");
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    printf("Человек успешно удален.\n");
}


void edit(Node** head, int index)
{
    Node* current = *head;
    int count = 1;

    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Неверный номер пользователя.\n");
        return;
    }

    people* p = &(current->data);

    int chck1;
    printf("Какой параметр хотите редактировать?\n");
    printf("   1. Имя\n   2. Фамилия\n   3. Отчество\n   4. Номера телефонов\n"
           "   5. Адреса эл. почты\n   6. Соц. сети\n   7. Место работы\n   8. Должность\n");
    scanf("%d",&chck1);

    switch(chck1)
    {
        case 1:
            printf("Введите новое имя:\n");
            scanf("%s", p->first_name);
            break;
        case 2:
            printf("Введите новую фамилию:\n");
            scanf("%s", p->surname);
            break;
        case 3:
            printf("Введите новое отчество:\n");
            scanf("%s", p->patronymic);
            break;
        case 4:
            for (int j = 0; j < 5; ++j) 
            {
                printf("Введите новый номер телефона %d:\n", j + 1);
                scanf("%s", p->phone[j]);
            }
            break;
        case 5:
            for (int j = 0; j < 5; ++j) 
            {
                printf("Введите новый адрес электронной почты %d:\n", j + 1);
                scanf("%s", p->email[j]);
            }
            break;
        case 6:
            for (int j = 0; j < 5; ++j) 
            {
                printf("Введите новую ссылку на соц. сеть %d:\n", j + 1);
                scanf("%s", p->socials[j]);
            }
            break;
        case 7:
            printf("Введите новое место работы:\n");
            scanf("%s", p->workplace);
            break;
        case 8:
            printf("Введите новую должность:\n");
            scanf("%s", p->job);
            break;
        default:
            break;
    }
}
