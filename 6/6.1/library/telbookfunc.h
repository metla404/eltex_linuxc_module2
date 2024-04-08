#ifndef TELBOOKFUNC_H
#define TELBOOKFUNC_H

struct people_s
{
    char first_name [40];
    char surname [40];
    char patronymic [40];
    char phone [5][11];
    char email [5][40];
    char socials [5][50];
    char workplace [100];
    char job [100];
};

typedef struct people_s people;

typedef struct Node
{
    people data;
    struct Node* next;
    struct Node* prev;
} Node;

void print_people(Node* head);
void add(Node** head, people p);
void rem(Node** head, int index);
void edit(Node** head, int index);

#endif
