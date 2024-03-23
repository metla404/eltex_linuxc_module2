#include <stdio.h>
#include "calcmenufunc.h"
#include "calcnewfunc.h"
#include "calcaddfunc.h"
#include "calcdivfunc.h"
#include "calcmultfunc.h"
#include "calcsubfunc.h"


int main()
{
    const struct operation operations[] = 
    {
        {"+", add_numbers},
        {"-", subtract_numbers},
        {"*", multiply_numbers},
        {"/", divide_numbers}
    };
    const size_t num_operations = sizeof(operations) / sizeof(operations[0]);

    calculator_menu(operations, num_operations);
    return 0;
}