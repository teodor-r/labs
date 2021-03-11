#ifndef FUCNTION_EXAMPLES_H
#define FUCNTION_EXAMPLES_H

#include "struct.h"               //вся работа с массивом хранится тут

#include <limits.h>                        // для проверки на переполнение


// примеры функции для работы с map, reduce, where

//примеры для int

//map
void         int_func_map1        (int *element);                                         // к каждому элементу прибавляем 2
void         int_func_map2        (int *element);                                         // возводим в квадрат


bool         int_func_where1      (const int *element);                                   // берём четные
bool         int_func_where2      (const int *element);                                   // берём нечетные


//примеры для complex

//map
void          complex_func_map1          (double _Complex *element);
void          complex_func_map2          (double _Complex *element);


//where
bool          complex_func_where1        (const double _Complex *element);
bool          complex_func_where2        (const double _Complex *element);

#endif //FUCNTION_EXAMPLES_H
