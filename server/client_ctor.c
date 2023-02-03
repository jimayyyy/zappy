/*
** EPITECH PROJECT, 2022
** client
** File description:
** constructor
*/

#include "server.h"

void constructor_c(client_t *this, va_list *args)
{
    this->clifd = (va_arg(*args, int));
    this->client.sin_family = AF_INET;
    this->client.sin_addr.s_addr = inet_addr(va_arg(*args, char *));
    this->client.sin_port = (va_arg(*args, int));
    this->id = (va_arg(*args, int));
    this->msg = NULL;
    this->send = NULL;
}

void destructor_c(client_t *this)
{
    close(this->clifd);
}

const client_t _client_ctr = {
    {
        .__size__ = sizeof(client_t),
        .__ctor__ = (ctor_t)&(constructor_c),
        .__dtor__ = (dtor_t)&(destructor_c)
    },
    .clifd = 0,
    .id = 0,
    .client = {},
    .first = true,
    .bufread = NULL,
    .mode = -1,
};

const class_c *client = (const class_c *)&_client_ctr;