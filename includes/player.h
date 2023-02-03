/*
** EPITECH PROJECT, 2022
** player
** File description:
** header
*/

#ifndef PLAYER_H_
#define PLAYER_H_
    #include "top.h"
    #include "vector.h"
    #include <time.h>
    #define alive 1;
    #define dead 0;
    #define ACTIONLIST 12

typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct commandstack_s {
    clock_t timer;
    char *commands;
} commandstack_t;

typedef struct player_s {
    class_c base;
    int id;
    int status;
    int frk;
    int angle;
    int mode;
    char *team;
    inventory_t inventory;
    vector2i_t pos;
    vector2i_t oldPos;
    vector2i_t mapSize;
    vector_t *commands;
    clock_t timer;
    int cd;
    int level;
    int teamSize;
    int life;
} player_t;

typedef struct iacmd {
    char *action;
} iacmd_t;

extern const class_c *playerr;

void pnw(player_t *player, vector_t *graphic);

#endif /* !PLAYER_H_ */
