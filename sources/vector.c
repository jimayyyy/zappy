/*
** EPITECH PROJECT, 2022
** vector
** File description:
** function
*/

#include "vector.h"

void push_back(vector_t *list, void *data)
{
    vector_t *newnode = malloc(sizeof(vector_t));

    if (newnode == NULL)
        perror("malloc pushback");
    if (list->data == NULL && list->next == NULL) {
        list->data = data;
    } else {
        while (list->next)
            list = list->next;
        newnode->data = data;
        newnode->next = NULL;
        list->next = newnode;
    }
}

void clear(vector_t *list)
{
    while (list) {
        free(list);
        list = list->next;
    }
    free(list);
}

size_t size(vector_t *list)
{
    vector_t *tmp = list;
    size_t i = 0;

    if (tmp == NULL)
        return 0;
    while (tmp) {
        tmp = tmp->next;
        i++;
    }
    return i;
}

vector_t *init(void)
{
    vector_t *list = malloc(sizeof(vector_t));
    if (list == NULL)
        perror("malloc init (vector)");
    list->data = NULL;
    list->next = NULL;
    return list;
}