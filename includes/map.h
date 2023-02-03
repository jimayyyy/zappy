/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

enum Ressource {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
};

typedef struct rsc_s {
    int available[7];
} rsc_t;


typedef struct map_s {
    char *map;
    rsc_t *ressource;
    int width;
    int height;
} map_t;

map_t *init_map(args_t *args);
bool place_food(map_t *map, int mode);
bool place_linemate(map_t *map, int mode);
bool place_deraumere(map_t *map, int mode);
bool place_sibur(map_t *map, int mode);
bool place_phiras(map_t *map, int mode);
bool place_thystame(map_t *map, int mode);
bool place_mendiane(map_t *map, int mode);
void replace(map_t *map, int i, vector_t *players);

#endif /* !MAP_H_ */
