/*
** EPITECH PROJECT, 2022
** allocation
** File description:
** functions
*/

#include "server.h"

object *new(const class_c *class, ...)
{
    va_list args;
    class_c *obj = NULL;
    va_start(args, class);

    if (class->__ctor__ == NULL)
        return (NULL);
    obj = malloc(class->__size__);
    if (obj == NULL)
        perror("malloc new");
    memcpy(obj, class, class->__size__);
    class->__ctor__(obj, &args);
    return obj;
}

void delete(object *ptr)
{
    if (ptr == NULL)
        return;
    if (((class_c *)ptr)->__dtor__ == NULL)
        return;
    ((class_c *)ptr)->__dtor__((class_c *)ptr);
    free(ptr);
}