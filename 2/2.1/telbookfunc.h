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

void print_people(people people_array[], int *c);
void add(people people_list[], int *c);
void rem(people people_list[], int *c);
void edit(people people_list[], int* c);

#endif