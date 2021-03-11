#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "struct.h"
#include "function_example.h"
#define MAX_IN_RANDOM  1000

void handler_error (CEXCEPTION_T EXPT);

int main (int argc, char **argv)
{



    CEXCEPTION_T EXCEPTION;

    int menu;
    DynArr* arr;
    DynArr* tmp;
    do {
        menu = dialog(MENU, MENU_SIZE);
        switch (menu) {
            case 1: {
                int menu_int;
                 arr = construct_int_array();
                do {
                    menu_int = dialog(GENERAL_MENU, GENERAL_MENU_SIZE);
                    switch (menu_int) {
                        case 1: {
                            Try {
                                        sort(arr);
                                        print_int_array(arr);
                                    } Catch(EXCEPTION) {
                                handler_error(EXCEPTION);
                            }
                        }
                            break;

                        case 2: {
                            int menu_map;
                            do {
                                menu_map = dialog(MENU_INT_MAP, MENU_INT_MAP_SIZE);
                                if (menu_map >= 1 && menu_map <= 2) {
                                    Try {

                                                if (menu_map == 1)
                                                    tmp = map(int_func_map1,arr);
                                                else if (menu_map == 2)
                                                    tmp = map(int_func_map2, arr);
                                                print_int_array(tmp);
                                                destruct_array(tmp);
                                            } Catch(EXCEPTION) {
                                        handler_error(EXCEPTION);
                                    }
                                }
                            } while (menu_map != 0);
                        }
                            break;

                        case 3: {
                            int menu_where;
                            do {
                                menu_where = dialog(MENU_INT_WHERE, MENU_INT_WHERE_SIZE);
                                if (menu_where >= 1 && menu_where <= 2) {
                                    Try {

                                                if (menu_where == 1)
                                                    tmp = where(int_func_where1, arr);
                                                if (menu_where == 2)
                                                    tmp = where(int_func_where2, arr);
                                                print_int_array(tmp);
                                                destruct_array(tmp);
                                            } Catch(EXCEPTION) {
                                        handler_error(EXCEPTION);
                                    }
                                }
                            } while (menu_where != 0);
                        }
                            break;

                        case 4: {
                            Try {
                                        tmp = construct_int_array();
                                        DynArr* cnt = concatenate(arr, tmp);
                                        print_int_array(cnt);
                                        destruct_array(tmp);
                                        destruct_array(cnt);
                                    } Catch(EXCEPTION) {
                                handler_error(EXCEPTION);
                            }
                        }
                            break;

                        default:

                            break;

                    }
                } while (menu_int != 0);
                destruct_array(arr);
            }
                break;

            case 2: {
                int menu_complex;
                arr = construct_complex_array();
                print_complex_array(arr);
                do {
                    menu_complex = dialog(GENERAL_MENU, GENERAL_MENU_SIZE);
                    switch (menu_complex) {
                        case 1: {
                            Try {

                                        sort(arr);
                                        print_complex_array(arr);
                                    } Catch(EXCEPTION) {
                                handler_error(EXCEPTION);
                            }
                        }
                            break;

                        case 2: {
                            int menu_map;
                            do {
                                menu_map = dialog(MENU_INT_MAP, MENU_INT_MAP_SIZE);
                                if (menu_map >= 1 && menu_map <= 2) {
                                    Try {
                                                if (menu_map == 1)
                                                    tmp = map(complex_func_map1, arr);
                                                else if (menu_map == 2)
                                                    tmp = map(complex_func_map2, arr);
                                                print_complex_array(tmp);
                                                destruct_array(tmp);
                                            } Catch(EXCEPTION) {
                                        handler_error(EXCEPTION);
                                    }
                                }
                            } while (menu_map != 0);
                        }
                            break;

                        case 3: {
                            int menu_where;
                            do {
                                menu_where = dialog(MENU_COMPLEX_WHERE, MENU_COMPLEX_WHERE_SIZE);
                                if (menu_where >= 1 && menu_where <= 2) {
                                    Try {
                                                if (menu_where == 1)
                                                    tmp = where(complex_func_where1, arr);
                                                if (menu_where == 2)
                                                    tmp = where(complex_func_where2, arr);
                                                print_complex_array(tmp);
                                                destruct_array(tmp);
                                            } Catch(EXCEPTION) {
                                        handler_error(EXCEPTION);
                                    }
                                }
                            } while (menu_where != 0);
                        }
                            break;

                        case 4: {
                            Try {
                                        tmp = construct_complex_array();
                                        DynArr* cnt = concatenate(arr, tmp);
                                        print_complex_array(cnt);
                                        destruct_array(cnt);
                                        destruct_array(tmp);
                                    } Catch(EXCEPTION) {
                                handler_error(EXCEPTION);
                            }
                        }
                            break;

                        default:
                            break;

                    }
                } while (menu_complex != 0);
                destruct_array(arr);
            }
                break;

            default:
                break;
        }
    } while (menu != 0);

    return 0;
}


void handler_error (CEXCEPTION_T EXPT){
   switch (EXPT) {
        case BUF_IS_EMPTY:
            printf("Array points to a null pointer!");
            break;

        case WRONG_ELEMENT_SIZE:
            printf("Element length less than or equal to 0!");
            break;

        case WRONG_DIMENSION:
            printf("Array length is less than or equal to 0!");
            break;

        case NO_COMPARATOR:
            printf("No comparison function!");
            break;

        case DIFFERENT_ELEMENT_SIZE:
            printf("Different element size!");
            break;

        case DIFFERENT_COMPARATOR:
            printf("Different comparison functions!");
            break;

        case OVERFLOW_EL:
            printf("Variable overflow has occurred!");
            break;

        default:
            printf("Unknown error %d", EXPT);
            break;
    }
    printf("\n");
}
