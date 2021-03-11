#include "function_example.h"

// функции примеры для int
void int_func_map1 (int *element)
{
    if(*((int *) element) > INT_MAX/2) Throw(OVERFLOW_EL);
    *((int *) element)*=2;
}
void int_func_map2 (int *element)
{
    if ((*((int *) element)) > INT_MAX / (*((int *) element))) Throw(OVERFLOW_EL);
    if (((*((int *) element)) < INT_MIN / (*((int *) element)))) Throw(OVERFLOW_EL);
    *((int *) element) *= (*((int *) element));
}

bool int_func_where1 (const int *element)
{
    return !(*element % 2);
}
bool int_func_where2 (const int *element)
{
    return (*element % 2);
}


// функции примеры для complex
void complex_func_map1 (complex double *element)
{
    *((complex double *) element) = *((double _Complex *) element)*2;
}
void complex_func_map2 (double _Complex *element)
{
    *((complex double *) element) = (*((double _Complex *) element))*(*((complex double *) element));
}

bool complex_func_where1 (const  double _Complex *element)
{
    return (creal(*element) >0);
}
bool complex_func_where2 (const  double _Complex *element)
{
    return (creal(*element) <= 0);
}
