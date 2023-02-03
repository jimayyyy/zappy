/*
** EPITECH PROJECT, 2022
** top
** File description:
** header
*/

#ifndef TOP_H_
#define TOP_H_
    #include <stdarg.h>
    #include <stdio.h>
    #include "vector.h"

typedef void object;
typedef void (*ctor_t)(object*, va_list *);
typedef void (*dtor_t)(object*);

typedef struct {
    const size_t __size__;
    ctor_t __ctor__;
    dtor_t __dtor__;
} class_c;

typedef struct vector2i_s {
    int x;
    int y;
} vector2i_t;


#endif /* !TOP_H_ */
