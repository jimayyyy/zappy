/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** graphic
*/

#include "game.h"

static iacmd_t cmds[] = {
    {"msz"},
    {"bct"},
    {"mct"},
    {"tna"},
    {"ppo"},
    {"plv"},
    {"pin"},
    {"sgt"},
    {"sst"},
};

void make_graphic_action(server_t *server, player_t *player, int clifd, vector_t *players)
{
    void (*function[9])(server_t *, player_t *, int, vector_t *) = {&msz, &bct, &mct, &tna,
    &ppo, &plv, &pin, &sgt};

    for (int i = 0; i != 8; i++) {
        if (strncmp(((commandstack_t *)(player->commands->data))->commands, cmds[i].action,
        strlen(cmds[i].action)) == 0) {
            (*function[i])(server, player, clifd, players);
            return;
        }
    }
    changeStack(&player->commands);
    dprintf(clifd, "suc\n");
}