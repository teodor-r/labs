#include "struct.h"

void    check_error(const DynArr* arr ){

    if (arr->buf == NULL)
        Throw(BUF_IS_EMPTY);
    if (arr->element_size <= 0)
        Throw(WRONG_ELEMENT_SIZE);
    if (arr->dimension <= 0)
        Throw(WRONG_DIMENSION);

}
void    copy_array(DynArr* dest, const DynArr* src){

    check_error(src);
    

    dest->dimension = src->dimension;
    dest->element_size = src->element_size;
    dest->comparator = src->comparator;
    dest->buf = malloc(dest->element_size* dest->dimension);
    memcpy(dest->buf,src->buf,src->element_size* src->dimension);

}


DynArr*     create_empty_array(){
    return  (DynArr*)malloc(sizeof(DynArr));
}	
DynArr*     create_array_from_buf(const void* buf,const size_t dimension, const size_t size, const bool (*comparator)(const void* , const void*)){

    DynArr* new_arr = create_empty_array();
    new_arr->dimension = dimension;
    new_arr->element_size = size;
    new_arr->buf = buf;
    new_arr->comparator = comparator;

    return new_arr;
}
void        destruct_array(DynArr* arr){
    free(arr->buf);
    free(arr);

}
DynArr*     construct_int_array(){
    printf("Enter the number of elements\n");
    int dist;
    scanf("%d", &dist);
    while (dist <= 0) {
        printf("Error, invalid length, try again!\n");
        scanf("%d", &dist);
    }
    printf("Enter array elements\n");
    int *buf = malloc(sizeof(int) * dist);
    for (int i = 0; i < dist; i++)
        scanf("%d", &buf[i]);
    DynArr* new_arr  = create_array_from_buf(buf,dist,sizeof(int),compare_int_elements);
    while (getchar() != '\n');
    return new_arr;
}
DynArr* construct_complex_array(){
    printf("Enter the number of elements\n");
    int dist;
    scanf("%d", &dist);
    while (dist <= 0) {
        printf("Error, invalid length, try again!\n");
        scanf("%d", &dist);
    }
    printf("Enter array elements\n");
    double _Complex *buf = malloc(sizeof(double _Complex) * dist);
    for (int i = 0; i < dist; i++){
        double  x1, x2;
        scanf("%lf", &x1);
        getchar();
        getchar();
        getchar();
        scanf("%lf", &x2);
        complex double num = x1 + x2 * I;
        buf[i] = num;
    }

    DynArr* new_arr  = create_array_from_buf(buf,dist,sizeof(double _Complex),compare_complex_elements);
    while (getchar() != '\n');
    return new_arr;
}


void*   get_element(DynArr* arr, size_t index){
    check_error(arr);

    if(index<arr->dimension)
        return (arr->buf + index*arr->element_size);
}
void    set_element(DynArr* arr, size_t index, void* value){
    check_error(arr);

    if(index<arr->dimension && sizeof(*value) == arr->element_size)
        memcpy(get_element(arr,index),value, sizeof(*value));

}


DynArr*     map(void (*f)(void*),const DynArr* arr){
    check_error(arr);

    DynArr *new_arr;
    new_arr = create_empty_array();
    copy_array(new_arr, arr);

    for( size_t i =0 ;i < arr->dimension; i++)
        f(get_element(new_arr,i));

    return new_arr;
}
DynArr*     where(bool (*h)(void*), const DynArr* arr){
    check_error(arr);

    DynArr *new_arr;
    new_arr = create_empty_array();
    copy_array(new_arr, arr);

    size_t counter = 0;
    for (size_t i = 0; i < arr->dimension; i++) {


        if (h(arr->buf + i * arr->element_size)) {
            memcpy(new_arr->buf + counter * new_arr->element_size,
                   new_arr->buf + i * new_arr->element_size,
                   new_arr->element_size);

            counter++;
        }

    }
    new_arr->dimension = counter;
    new_arr->buf = realloc(new_arr->buf, new_arr->dimension * new_arr->element_size);

    return new_arr;
}
DynArr*     concatenate(const DynArr* arr1,const DynArr* arr2){

    check_error(arr1);
    check_error(arr2);


    if (arr1->comparator == NULL)
        Throw(NO_COMPARATOR);
    if (arr1->element_size != arr2->element_size)
        Throw(DIFFERENT_ELEMENT_SIZE);
    if (arr1->comparator != arr2->comparator)
        Throw(DIFFERENT_COMPARATOR);


    DynArr *new_arr = create_empty_array();
    new_arr->element_size = arr1->element_size;
    new_arr->dimension = arr1->dimension + arr2->dimension;
    new_arr->buf = malloc(new_arr->element_size * new_arr->dimension);
    memcpy(new_arr->buf, arr1->buf, arr1->dimension* arr1->element_size);
    memcpy(new_arr->buf+ arr1->dimension * arr1->element_size, arr2->buf, arr2->dimension *arr2->element_size );

    return new_arr;

}
void        sort(DynArr* arr){


    check_error(arr);
    if (arr->comparator == NULL)
        Throw(NO_COMPARATOR);

        qsort(arr->buf,
          arr->dimension,
          arr->element_size,
          arr->comparator);
}
void    print_int_array (const DynArr *arr){
    for (size_t i = 0; i < arr->dimension; i++)
        printf("%d ", *((int*)get_element(arr,i)));
    printf("\n");
}
void    print_complex_array (const DynArr *arr){
    for (size_t i = 0; i < arr->dimension; i++){
        double _Complex compl = *((double _Complex*)get_element(arr,i));
        printf("%1.f + ", creal(compl));
        printf("%1.fi ", cimag(compl));
    }
    printf("\n");
}
int     compare_int_elements (const int *lf, const int *rt){
    return *lf - *rt;
}
int     compare_complex_elements (const double _Complex *lt, const double _Complex *rt){
        double x1 = creal(*lt), y1 = cimag(*lt), x2 = creal(*rt), y2 = cimag(*rt);
    if (x1 < x2) return -1;
    if (x1 > x2) return 1;
    if (x1 == x2 && y1 < y2) return -1;
    if (x1 == x2 && y1 > y2) return 1;
    return 0;
}


