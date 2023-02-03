/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** place_rsc
*/

#include "server.h"
#include "game.h"

bool place_food(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.5;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[FOOD] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

bool place_linemate(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.3;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[LINEMATE] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

bool place_deraumere(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.15;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[DERAUMERE] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

bool place_sibur(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.1;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[SIBUR] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

bool place_mendiane(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.1;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[MENDIANE] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

bool place_phiras(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.08;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[PHIRAS] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

bool place_thystame(map_t *map, int mode)
{
    static int count = 0;
    float total_resource = map->width * map->height * 0.05;
    int idx = ((rand() % map->height) * map->width) + (rand() % map->width);

    if (mode == 0 && total_resource > count)
    {
        map->ressource[idx].available[THYSTAME] += 1;
        count++;
    }
    if (mode == 1)
        count--;
    return (count == total_resource);
}

void replace(map_t *map, int i, vector_t *players)
{
    srand(time(NULL));
    int x = (rand() % map->width);
    int y = (rand() % map->height);
    int idx = (y * map->width) + x;
    vector_t *tmp_p = players;

    map->ressource[idx].available[i] += 1;
    while (tmp_p) {
        if (tmpp->mode == GRAPHICAL) {
            dprintf(tmpp->frk, "bct %d %d %d %d %d %d %d %d %d\n",
            x, y, map->ressource[idx].available[0],
            map->ressource[idx].available[1],
            map->ressource[idx].available[2],
            map->ressource[idx].available[3],
            map->ressource[idx].available[4],
            map->ressource[idx].available[5],
            map->ressource[idx].available[6]);
        }
        tmp_p = tmp_p->next;
    }
}