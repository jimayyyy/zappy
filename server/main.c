/*
** EPITECH PROJECT, 2022
** server
** File description:
** main
*/

#include "server.h"
#include "vector.h"
#include <signal.h>
#include "player.h"
#include "game.h"

void server_side(server_t *this, vector_t *clients, vector_t *player, args_t *args)
{
    vector_t *tmp = clients;

    signal(SIGTERM, sig_handler);
    signal(SIGINT, sig_handler);
    FD_ZERO(&this->current_socket);
    FD_ZERO(&this->except_fd);
    FD_ZERO(&this->write_fd);
    
    FD_SET(this->socket, &this->current_socket);
    FD_SET(STDOUT_FILENO, &this->write_fd);
    FD_SET(STDERR_FILENO, &this->except_fd);

    while (tmp) {
        if (tmp->data == NULL)
            break;
        if (((client_t *)(tmp->data))->clifd > 0)
            FD_SET(((client_t *)(tmp->data))->clifd, &this->current_socket);
        tmp = tmp->next;
    }
    select_cond(this, clients, player, args);
}

void server_initialization(server_t *this, args_t *args)
{
    vector_t *clients = init();
    vector_t *players = init();
    this->map = init_map(args);
    this->teams = args->teams;

    while (singleton_run(1) > 0) {
        game_side(this, clients, players);
        server_side(this, clients, players, args);
    }
    printf("Closing\n");
    close(this->socket);
}

args_t *initStruct(args_t *mystruct)
{
    mystruct = malloc(sizeof(args_t));
    if (mystruct == NULL) {
        perror("malloc init struct");
    }
    mystruct->clientnb = -1;
    mystruct->freq = 100;
    mystruct->height = 10;
    mystruct->port = 4242;
    mystruct->width = 10;
    mystruct->teams = NULL;
    return mystruct;
}

void setTeamSize(args_t *mystruct)
{

    vector_t *tmp = mystruct->teams;
    while (tmp) {
        ((teams_t *)(tmp->data))->size = mystruct->clientnb;
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
    args_t *mystruct = initStruct(mystruct);
    if (mystruct == NULL)
        return 84;
    if (check_args(ac, av, &mystruct) == false) {
        free(mystruct);
        return 84;
    }
    object *serv = new(server, mystruct->port);
    if (((server_t *)serv)->socket == -1) {
        delete(serv);
        return 84;
    }
    setTeamSize(mystruct);
    server_initialization(((server_t *)serv), mystruct);
}