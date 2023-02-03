/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-jimy.xu
** File description:
** teams.c
*/


#include "server.h"
#include "vector.h"
#include "player.h"
#include <string.h>

void start_graphic(int fd, args_t *args, vector_t *players, server_t *server);

int fill_id_player(vector_t *players, args_t *args)
{
    int id = args->clientnb * 2;
    vector_t *tmp_p = players;
    for (int i = 0; i  < size(players); i++, tmp_p = players) {
        while (tmp_p) {
            if (tmp_p->data == NULL)
                break;
            if (((player_t *)(tmp_p)->data)->id == id &&
            ((player_t *)(tmp_p)->data)->frk != -1) {
                id--;
            }
            tmp_p = tmp_p->next;
        }
    }
    return (id);
}

bool create_player(client_t *client, vector_t *player,
args_t *args, vector_t *clients, server_t *server)
{
    char buf[4096];
    int len = 0;
    vector_t *tmp = args->teams;
    object *p;
    static int id_graphic = 1;
    int id_player = 0;

    if ((len = get_next_line(client->clifd, buf)) > 0) {
        manage_buffer(buf, client);
        if (!client->bufread)
            return true;
        if (strcmp(client->bufread, "GRAPHIC") == 0) {
            client->mode = GRAPHICAL;
            client->id_graphic = id_graphic;
            p = (void *)new(playerr, args, client->id_graphic,
                ((teams_t *)(tmp->data))->name, args->freq, GRAPHICAL, client->clifd, args->clientnb);
            push_back(player, (void *)p);
            id_graphic++;
            client->id_player = -1;
            start_graphic(client->clifd, args, player, server);
            free(client->bufread);
            client->bufread = NULL;
            return false;
        }
        while (tmp) {
            if (strcmp(client->bufread, ((teams_t *)(tmp->data))->name) == 0
                && ((teams_t *)(tmp->data))->size > 0) {
                ((teams_t *)(tmp->data))->size--;
                id_player = fill_id_player(player, args);
                p = (void *)new(playerr, args, id_player,
                ((teams_t *)(tmp->data))->name, args->freq, IA, client->clifd, args->clientnb);
                client->id_player = id_player;
                client->id_graphic = -1;
                push_back(player, (void *)p);
                dprintf(client->clifd, "%d\n%d %d\n",
                (((teams_t *)(tmp->data))->size),
                args->width, args->height);
                pnw((player_t *)p, clients);
                free(client->bufread);
                client->bufread = NULL;
                return false;
            }
            tmp = tmp->next;
        }
        free(client->bufread);
        client->bufread = NULL;
        dprintf(client->clifd, "ko\n");
        if (strlen(buf) <= 0)
            return true;
    }
    return true;
}

int handle_read(client_t *client, vector_t *player, args_t *args, vector_t *clients,
server_t *serv)
{
    char buf[4096];
    int len = 0;

    if (client->first == true) {
        client->first = create_player(client, player, args, clients,
        serv);
    } else if ((len = get_next_line(client->clifd, buf)) > 0) {
        manage_buffer(buf, client);
        if (strlen(buf) <= 0)
            return EXIT_FAILURE;
    }
    if (len  == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void handle_multiple_client(server_t *serv, vector_t *clients, vector_t *player, args_t *args)
{
    vector_t *tmp = clients;
    vector_t *tmp2 = player;
    while (tmp != NULL) {
        if (tmp->data == NULL)
            return;
        if (FD_ISSET(((client_t *)(tmp->data))->clifd, &serv->current_socket)) {
            handle_read(((client_t *)(tmp->data)), tmp2, args, clients, serv);
        }
        tmp = tmp->next;
    }
}

int select_cond(server_t *serv, vector_t *clients, vector_t *player, args_t *args)
{
    int clifd;
    int len = sizeof(struct sockaddr_in);
    struct sockaddr_in client_sock;
    object *cli;
    static int id = 1;
    struct timeval tv = (struct timeval){1, 0};

    if (select(FD_SETSIZE, &serv->current_socket, &serv->write_fd, &serv->except_fd, &tv) == -1)
        return EXIT_FAILURE;
    if (FD_ISSET(serv->socket, &serv->current_socket)) {
        clifd = accept(serv->socket,
            (struct sockaddr *)&client_sock, (socklen_t *)&len);
        if (clifd == -1)
            return EXIT_FAILURE;
        cli = new(client, clifd, "127.0.0.1", ntohs(serv->server.sin_port), id);
        printf("new connection from %s:%i\n", "127.0.0.1", client_sock.sin_port);
        id++;
        dprintf(((client_t *)(cli))->clifd, "WELCOME\n");
        push_back(clients, (void *)cli);
    }
    handle_multiple_client(serv, clients, player, args);
}