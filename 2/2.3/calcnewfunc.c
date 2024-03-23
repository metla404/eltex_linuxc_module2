#include "calcnewfunc.h"
#include <stdio.h>

void print_op(const struct operation operations[], size_t operation_num)
{
    for(size_t i=0; i<operation_num; i++)
    {
        printf("%d. %s\n", i+1, operations[i].name);
    }
}

