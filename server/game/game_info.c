/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** game_info
*/

#include "game.h"

char *tiles_info(server_t *server, player_t **player, vector_t *players);

bool look(server_t *server, player_t *player, int clifd, vector_t *players)
{
    char *str = NULL;

    if (strcmp(cmd->commands, "Look") == 0) {
        if (isFinished(player, 7) == true) {
            str = tiles_info(server, &player, players);
            dprintf(clifd, "%s\n", str);
//            printf("pos {%d, %d}\n", player->pos.x, player->pos.y);
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

void inventory_info(player_t **player, int clifd)
{
    dprintf(clifd, "[ food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, "
    "thystame %d ]\n", (*player)->inventory.food, (*player)->inventory.linemate,
    (*player)->inventory.deraumere, (*player)->inventory.sibur,
    (*player)->inventory.mendiane, (*player)->inventory.phiras,
    (*player)->inventory.thystame);
}

bool inventory(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players __attribute__((unused)))
{
    if (strcmp(cmd->commands, "Inventory") == 0) {
        if (isFinished(player, 1) == true) {
            inventory_info(&player, clifd);
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}