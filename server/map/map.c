/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** map
*/

#include "server.h"
#include <time.h>

void init_ressource(map_t *map)
{
    map->ressource = malloc(sizeof(rsc_t) * (map->width * map->height) + 1);
    if (map->ressource == NULL)
        perror("malloc init_resource");
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            for (int i = 0; i < 7; i++)
                map->ressource[(y * map->width) + x].available[i] = 0;
        }
    }
}

void place_ressource(map_t *map)
{
    int tot = map->width * map->height;

    srand(time(NULL));
    for (int i = 0; i < tot; i++) {
            place_food(map, 0);
            place_linemate(map, 0);
            place_deraumere(map, 0);
            place_sibur(map, 0);
            place_mendiane(map, 0);
            place_phiras(map, 0);
            place_thystame(map, 0);
    }
}

map_t *init_map(args_t *args)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL)
        perror("malloc init map");
    map->width = args->width;
    map->height = args->height;
    map->map = malloc(sizeof(char) * (args->width * args->height) + 1);
    if (map->map == NULL)
        perror("malloc init map");
    init_ressource(map);
    place_ressource(map);
    return (map);
}