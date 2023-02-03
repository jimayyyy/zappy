/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** player_action
*/

#include "game.h"

void push_to_stack(char *action, player_t *player);

void info_map(int clifd, map_t *map);

void start_graphic(int fd, args_t *args, vector_t *players, server_t *server)
{
    vector_t *tmp = server->teams;
    vector_t *tmp_p = players;

    dprintf(fd, "msz %d %d\n", args->width, args->height);
    dprintf(fd, "sgt %d\n", args->freq);
    info_map(fd, server->map);
    while (tmp) {
        dprintf(fd, "tna %s\n", ((teams_t *)(tmp->data))->name);
        tmp = tmp->next;
    }
    while (tmp_p) {
        if (tmpp->mode == IA) {
            dprintf(fd, "pnw %d %d %d %d %d %s\n", tmpp->id, tmpp->pos.x,
            tmpp->pos.y, tmpp->angle, tmpp->level, tmpp->team);
        }
        tmp_p = tmp_p->next;
    }
}

void pnw(player_t *player, vector_t *clients)
{
    vector_t *tmp_c = clients;
    
    while (tmp_c) {
        if (tmpc->mode == GRAPHICAL) {
            dprintf(tmpc->clifd, "pnw %d %d %d %d %d %s\n", player->id, player->pos.x,
            player->pos.y, player->angle, player->level, player->team);
        }
        tmp_c = tmp_c->next;
    }
}

void action_c(player_t *player, vector_t *players, char *str)
{
    vector_t *tmp_p = players;

    while (tmp_p) {
        if (tmpp->mode == GRAPHICAL)
            push_to_stack(str, tmpp);
        tmp_p = tmp_p->next;
    }
}