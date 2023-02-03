/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team_info
*/

#include "game.h"

void tna(server_t *server, player_t *player, int clifd, vector_t *players)
{
    vector_t *tmp = server->teams;

    if (strcmp(((commandstack_t *)(player->commands->data))->commands, 
    "tna") != 0) {
        dprintf(clifd, "sbp\n");
        changeStack(&player->commands);
        return;
    }
    while (tmp) {
        dprintf(clifd, "tna %s\n", ((teams_t *)(tmp->data))->name);
        tmp = tmp->next;
    }
    changeStack(&player->commands);
}