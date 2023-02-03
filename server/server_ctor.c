/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** CONSTRUCTOR
*/

#include "server.h"
#include <time.h>

void constructor_s(server_t *this, va_list *args)
{
    int value = 1;
    this->socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(this->socket,SOL_SOCKET,SO_REUSEADDR, &value, sizeof(int));
    this->server.sin_family = AF_INET;
    this->server.sin_addr.s_addr = INADDR_ANY;
    this->server.sin_port = htons((va_arg(*args, int)));
    this->timer = clock();
    if (bind(this->socket, (struct sockaddr *)&this->server,
        sizeof(this->server)) == -1) {
        this->socket = -1;
        perror("bind server");
        return;
    }
    if (listen(this->socket, SOMAXCONN) == -1) {
        perror("listen server");
        return;
    }

}

void destructor_s(server_t *this)
{
    close(this->socket);
}

const server_t _server_ctr = {
    {
        .__size__ = sizeof(server_t),
        .__ctor__ = (ctor_t)&(constructor_s),
        .__dtor__ = (dtor_t)&(destructor_s)
    },
    .socket = 0,
    .server = {},
};

const class_c *server = (const class_c *)&_server_ctr;