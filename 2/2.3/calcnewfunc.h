#ifndef CALCNEWFUNC_H
#define CALCNEWFUNC_H
#include <stdio.h>

typedef double (*operation_func)(double,double);

struct operation
{
    char* name;
    operation_func func;
};

void print_op(const struct operation operations[], size_t operation_num);


#endif
