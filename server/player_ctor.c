/*
** EPITECH PROJECT, 2022
** player
** File description:
** constructor
*/

#include "player.h"
#include "args.h"
#include <time.h>

int choseAngle()
{
    srand(time(NULL));
    int nbr = rand() % 4 + 1;

    return (nbr);
}

void constructor_p(player_t *this, va_list *args)
{
    args_t *arg = (va_arg(*args, args_t *));
    srand(time(NULL));

    this->id = (va_arg(*args, int));
    this->status = alive;
    this->angle = 0;
    this->inventory = (inventory_t){10, 0, 0, 0, 0, 0, 0};
    this->pos = (vector2i_t){(rand() % arg->width), (rand() % arg->height)};
    this->oldPos = (vector2i_t){0, 0};
    this->mapSize = (vector2i_t){arg->width, arg->height};
    this->team = (va_arg(*args, char *));
    this->cd = (va_arg(*args, int));
    this->commands = init();
    this->mode = (va_arg(*args, int));
    this->angle = choseAngle();
    this->level = 1;
    this->frk = (va_arg(*args, int));
    this->teamSize = (va_arg(*args, int));
    this->timer = clock();
    this->life = 1260;
}

void destructor_p(player_t *this)
{
    return;
}

const player_t _player_ctr = {
    {
        .__size__ = sizeof(player_t),
        .__ctor__ = (ctor_t)&(constructor_p),
        .__dtor__ = (dtor_t)&(destructor_p)
    },
    .id = 0,
    .inventory = {},
    .pos = {},
    .status = 0,
    .angle = 0,
    .team = NULL,
    .cd = 0,
    .commands = NULL,
    .mode = -1,
    .pos = {},
    .mapSize = {},
    .level = 0,
    .frk = 0,
    .life = 0,
};

const class_c *playerr = (const class_c *)&_player_ctr;