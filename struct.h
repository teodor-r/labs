#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <complex.h>                          // ���� ��� ������ � ������������ �������
#include <math.h>
#include "CException_lib/CException.h" // lib ��� ��������� ���������� ������� Try Catch


typedef struct DynamicArray{
    size_t element_size;
    size_t dimension;
    void *buf;

    bool (*comparator)(const void* lf, const void* rt);
}DynArr;

//��������
DynArr*   map(void (*f)(void*), const DynArr* arr);
DynArr*   where(bool (*h)(void*), const DynArr* arr);
DynArr*   concatenate(const DynArr* arr1, const DynArr* arr2);
void      sort(DynArr* arr);
//������� ������������
void*  get_element(DynArr* arr, size_t index);
void   set_element(DynArr* arr, size_t index, void *value);

// 
DynArr*  create_array_from_buf(const void* buf, const size_t dimension,const size_t size, const bool (*comparator)(const void* , const void*));
DynArr*  create_empty_array();
void     destruct_array(DynArr* arr);
DynArr*  construct_int_array();
DynArr*  construct_complex_array();

// ������� ���������
int     compare_int_elements       (const int *left, const int *right);
int     compare_complex_elements   (const  double _Complex *left, const  double _Complex *right);

//������� ������
void    print_int_array            (const DynArr *arr);
void    print_complex_array        (const DynArr *arr);

//��� ������
void check_error(const DynArr*);
// �����
void copy_array(DynArr* dest, const DynArr* src);

enum ERRORCODE_T
{
    BUF_IS_EMPTY,               //������ ��������� �� ������ ���������
    WRONG_ELEMENT_SIZE,         //����� �������� ������ ��� ����� 0
    WRONG_DIMENSION,            //����� ������� ������ ��� ����� 0
    NO_COMPARATOR,              //����������� ������� ���������
    DIFFERENT_ELEMENT_SIZE,     //������ ����� ��������
    DIFFERENT_COMPARATOR,       //������ ������� ���������
    OVERFLOW_EL                 //������������
};

#endif // DYN_ARR



