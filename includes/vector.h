/*
** EPITECH PROJECT, 2022
** vector
** File description:
** header
*/

#ifndef VECTOR_H_
    #define VECTOR_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include "top.h"

typedef struct vector_s {
    void *data;
    struct vector_s *next;
} vector_t;

void push_back(vector_t *list, void *data);
void clear(vector_t *list);
size_t size(vector_t *list);
vector_t *init(void);

#endif /* !VECTOR_H_ */