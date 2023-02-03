/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** map_info
*/

#include "game.h"

void msz(server_t *server, player_t *player, int clifd, vector_t *players)
{
    if (!strcmp(((commandstack_t *)(player->commands->data))->commands, 
    "msz"))
        dprintf(clifd, "msz %d %d\n", server->map->width, server->map->height);
    else
        dprintf (clifd, "sbp\n");
    changeStack(&player->commands);
}

void bct(server_t *server, player_t *player, int clifd, vector_t *players)
{
    char **tab = my_str_to_word_array_delim(
    ((commandstack_t *)(player->commands->data))->commands, " ");
    int x = 0;
    int y = 0;

    if (size_tab(tab) != 3 || !is_number(tab[1]) || !is_number(tab[2])
    || strcmp(tab[0], "bct")) {
        dprintf(clifd, "sbp\n");
    } else {
        x = atoi(tab[1]);
        y = atoi(tab[2]);
        dprintf(clifd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        server->map->ressource[(y * server->map->width) + x].available[0],
        server->map->ressource[(y * server->map->width) + x].available[1],
        server->map->ressource[(y * server->map->width) + x].available[2],
        server->map->ressource[(y * server->map->width) + x].available[3],
        server->map->ressource[(y * server->map->width) + x].available[4],
        server->map->ressource[(y * server->map->width) + x].available[5],
        server->map->ressource[(y * server->map->width) + x].available[6]);
    }
    changeStack(&player->commands);
}

void info_map(int clifd, map_t *map)
{
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            dprintf(clifd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
            map->ressource[(y * map->width) + x].available[0],
            map->ressource[(y * map->width) + x].available[1],
            map->ressource[(y * map->width) + x].available[2],
            map->ressource[(y * map->width) + x].available[3],
            map->ressource[(y * map->width) + x].available[4],
            map->ressource[(y * map->width) + x].available[5],
            map->ressource[(y * map->width) + x].available[6]);
        }
    }
}

void mct(server_t *server, player_t *player, int clifd, vector_t *players)
{
    if (strcmp(((commandstack_t *)(player->commands->data))->commands, 
    "mct") != 0) {
        dprintf(clifd, "sbp\n");
        changeStack(&player->commands);
        return;
    }
    info_map(clifd, server->map);
    changeStack(&player->commands);
}

void sgt(server_t *server, player_t *player, int clifd, vector_t *players)
{
    if (strcmp(((commandstack_t *)(player->commands->data))->commands, 
    "sgt") != 0) {
        dprintf(clifd, "sbp\n");
        changeStack(&player->commands);
        return;
    }
    dprintf(clifd, "sgt %d\n", player->cd);
    changeStack(&player->commands);
}