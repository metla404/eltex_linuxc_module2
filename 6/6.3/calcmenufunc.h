#ifndef CALCMENUFUNC_H
#define CALCMENUFUNC_H
#include <sys/types.h>

struct operation 
{
    const char *name;
    double (*func)(double, double);
};

void calculator_menu(const char *path);
void print_op(const struct operation operations[], size_t operation_num);

#endif
