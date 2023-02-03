/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** vision_look
*/

#include "game.h"
#include "stdio.h"

static char *tab[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    NULL
};

static char *get_ressource(server_t *server, vector_t *players, char *str, vector2i_t pos)
{
   int x = pos.x < 0 ? server->map->width + pos.x : pos.x % server->map->width;
   int y = pos.y < 0 ? server->map->height + pos.y : pos.y % server->map->height;

    vector_t *tmp_p = players;

    printf("tile {%d, %d}\n", x, y);
    while (tmp_p) {
        if (tmp_p->data == NULL)
            break;
        if (tmpp->pos.x == x && tmpp->pos.y == y) {
           asprintf(&str, "%s player", str);
        }
        tmp_p = tmp_p->next;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = server->map->ressource[y * server->map->width + x]
        .available[i]; j > 0; j--)
            asprintf(&str, "%s %s", str, tab[i]);
    }
    return str;
}

char *vision_down(server_t *server, player_t **player, vector_t *players)
{
    char *str = NULL;

    asprintf(&str, "[");
    str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x,
    (*player)->pos.y});
    for (int y = 1; y <= (*player)->level; y++) {
        for (int x = -y; x <= (*player)->level; x++) {
            asprintf(&str, "%s,", str);
            str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x + x,
            (*player)->pos.y + y});
        }
    }
    asprintf(&str, "%s ]", str);
    return (str);
}

char *vision_up(server_t *server, player_t **player, vector_t *players)
{
    char *str = NULL;

    asprintf(&str, "[");
    str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x,
    (*player)->pos.y});
    for (int y = 1; y <= (*player)->level; y++) {
        for (int x = -y; x <= (*player)->level; x++) {
            asprintf(&str, "%s,", str);
            str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x + x,
            (*player)->pos.y - y});
        }
    }
    asprintf(&str, "%s ]", str);
    return (str);
}

char *vision_left(server_t *server, player_t **player, vector_t *players)
{
    char *str = NULL;

    asprintf(&str, "[");
    str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x,
    (*player)->pos.y});
    for (int x = 1; x <= (*player)->level; x++) {
        for (int y = -x; y <= (*player)->level; y++) {
            asprintf(&str, "%s,", str);
            str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x - x,
            (*player)->pos.y + y});
        }
    }
    asprintf(&str, "%s ]", str);
    return (str);
}

char *vision_right(server_t *server, player_t **player, vector_t *players)
{
    char *str = NULL;

    asprintf(&str, "[");
    str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x,
    (*player)->pos.y});
    for (int x = 1; x <= (*player)->level; x++) {
        for (int y = -x; y <= (*player)->level; y++) {
            asprintf(&str, "%s,", str);
            str = get_ressource(server, players, str, (vector2i_t) {(*player)->pos.x + x,
            (*player)->pos.y + y});
        }
    }
    asprintf(&str, "%s ]", str);
    return (str);
}

char *tiles_info(server_t *server, player_t **player, vector_t *players)
{
    if ((*player)->angle == 1)
        return (vision_up(server, player, players));
    else if ((*player)->angle == 4)
        return (vision_left(server, player, players));
    else if ((*player)->angle == 3)
        return (vision_down(server, player, players));
    return (vision_right(server, player, players));
}