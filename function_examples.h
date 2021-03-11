#ifndef FUCNTION_EXAMPLES_H
#define FUCNTION_EXAMPLES_H

#include "struct.h"               //��� ������ � �������� �������� ���

#include <limits.h>                        // ��� �������� �� ������������


// ������� ������� ��� ������ � map, reduce, where

//������� ��� int

//map
void         int_func_map1        (int *element);                                         // � ������� �������� ���������� 2
void         int_func_map2        (int *element);                                         // �������� � �������


bool         int_func_where1      (const int *element);                                   // ���� ������
bool         int_func_where2      (const int *element);                                   // ���� ��������


//������� ��� complex

//map
void          complex_func_map1          (double _Complex *element);
void          complex_func_map2          (double _Complex *element);


//where
bool          complex_func_where1        (const double _Complex *element);
bool          complex_func_where2        (const double _Complex *element);

#endif //FUCNTION_EXAMPLES_H
