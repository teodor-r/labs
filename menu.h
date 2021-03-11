#ifndef  MENU_H
#define  MENU_H

const char *MENU[] = {"0. Exit", "1. Work with integer numbers", "2. Work with complex numbers"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *GENERAL_MENU[] = {"0. Back", "1. Sort", "2. Map", "3. Where", "4. Concatenation"};
const int GENERAL_MENU_SIZE = sizeof(GENERAL_MENU) / sizeof(GENERAL_MENU[0]);

const char *MENU_INT_MAP[] = {"0. Back", "1. Multuply for 2  each element", "2. Square each element"};
const int MENU_INT_MAP_SIZE = sizeof(MENU_INT_MAP) / sizeof(MENU_INT_MAP[0]);

const char *MENU_INT_WHERE[] = {"0. Back", "1. Even", "2. Odd"};
const int MENU_INT_WHERE_SIZE = sizeof(MENU_INT_WHERE) / sizeof(MENU_INT_WHERE[0]);

const char *MENU_COMPLEX_WHERE[] = {"0. Back", "1. Positive real part", "2. Negative real part"};
const int MENU_COMPLEX_WHERE_SIZE = sizeof(MENU_COMPLEX_WHERE) / sizeof(MENU_COMPLEX_WHERE[0]);


int dialog(const char *msgs[], int n);

#endif
