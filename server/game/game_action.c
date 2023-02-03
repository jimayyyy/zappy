/*
** EPITECH PROJECT, 2022
** make
** File description:
** action
*/

#include "game.h"
#include <signal.h>
#include <time.h>

bool isFinished(player_t *player, int TQT)
{
    clock_t end = clock();
    float cd = (float)((float)TQT / (float)player->cd);
    long double millis = ((end - cmd->timer) * 1000) / (CLOCKS_PER_SEC * 100);

    if (millis > cd) {
        return true;
    }
    return false;
}

static void goForward(player_t **player)
{
    if ((*player)->angle == 1)
        (*player)->pos.y -= 1;
    if ((*player)->angle == 2)
        (*player)->pos.x += 1;
    if ((*player)->angle == 3)
        (*player)->pos.y += 1;
    if ((*player)->angle == 4)
        (*player)->pos.x -= 1;
    if ((*player)->pos.x >= (*player)->mapSize.x)
        (*player)->pos.x = 0;
    if ((*player)->pos.y >= (*player)->mapSize.y)
        (*player)->pos.y = 0;
    if ((*player)->pos.x < 0)
        (*player)->pos.x = (*player)->mapSize.x - 1;
    if ((*player)->pos.y < 0)
        (*player)->pos.y = (*player)->mapSize.y - 1;
}

static void turn(player_t **player, int angle)
{
    if (angle == RIGHT) {
        (*player)->angle -= 1;
        if ((*player)->angle < 1)
            (*player)->angle = 4;
    }
    if (angle == LEFT) {
        (*player)->angle += 1;
        if ((*player)->angle > 4)
            (*player)->angle = 1;
    }
}

bool forward(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    char *str = NULL;

    if (strcmp(cmd->commands, "Forward") == 0) {
        if (isFinished(player, 7) == true) {
            dprintf(clifd, "ok\n");
            goForward(&player);
            asprintf(&str, "ppo %d", player->id);
            action_c(player, players, str);
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

bool turnR(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    char *str = NULL;

    if (strcmp(cmd->commands, "Right") == 0) {
        if (isFinished(player, 7) == true) {
            dprintf(clifd, "ok\n");
            turn(&player, RIGHT);
            asprintf(&str, "ppo %d", player->id);
            action_c(player, players, str);
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

bool turnL(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    char *str = NULL;

    if (strcmp(cmd->commands, "Left") == 0) {
        if (isFinished(player, 7) == true) {
            dprintf(clifd, "ok\n");
            turn(&player, LEFT);
            asprintf(&str, "ppo %d", player->id);
            action_c(player, players, str);
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

bool myFork(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    if (strcmp(cmd->commands, "Fork") == 0) {
        if (isFinished(player, 42) == true) {
            dprintf(clifd, "ok\n");
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

static bool makeEject(player_t *player, vector_t *players)
{
    vector_t *tmp_p = players;
    int count = 0;
    char *str = NULL;

    while (tmp_p) {
        if (tmpp->pos.x == player->pos.x
        && tmpp->pos.y == player->pos.y
        && tmpp->id != player->id) {
            tmpp->oldPos = tmpp->pos;
            player_t *p = tmpp;
            goForward(&p);
            asprintf(&str, "ppo %d", tmpp->id);
            action_c(player, players, str);
            count++;
        }
        if (tmpp->id != player->id)
            dprintf(tmpp->frk, "eject: %i\n", player->angle);
        tmp_p = tmp_p->next;
    }
    return count == 0 ? false : true;
}

bool eject(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    if (strcmp(cmd->commands, "Eject") == 0) {
        if (isFinished(player, 7) == true) {
            if (makeEject(player, players) == false) {
                dprintf(clifd, "ko\n");
                changeStack(&player->commands);
            }
            else {
                dprintf(clifd, "ok\n");
                changeStack(&player->commands);
            }
        }
        return true;
    }
    return false;
}

static int checkteamNb(player_t *player, vector_t *players)
{
    vector_t *tmp_p = players;
    int count = 0;

    while (tmp_p) {
        if (strcmp(tmpp->team, player->team) == 0)
            count++;
        tmp_p = tmp_p->next;
    }
    return (player->teamSize - count);
}

bool connectNbr(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    if (strcmp(cmd->commands, "Connect_nbr") == 0) {
        dprintf(clifd, "%i\n", checkteamNb(player, players));
        changeStack(&player->commands);
        return true;
    }
    return false;
}

static bool checkItemExistance(server_t *server, player_t *player)
{
    if (strcmp(cmd->commands+5, "food") == 0)
        if (maaap[0] > 0)
            return true;
    if (strcmp(cmd->commands+5, "linemate") == 0)
        if (maaap[1] > 0)
            return true;
    if (strcmp(cmd->commands+5, "deraumere") == 0)
        if (maaap[2] > 0)
            return true;
    if (strcmp(cmd->commands+5, "sibur") == 0)
        if (maaap[3] > 0)
            return true;
    if (strcmp(cmd->commands+5, "mendiane") == 0)
        if (maaap[4] > 0)
            return true;
    if (strcmp(cmd->commands+5, "phiras") == 0)
        if (maaap[5] > 0)
            return true;
    if (strcmp(cmd->commands+5, "thystame") == 0)
        if (maaap[6] > 0)
            return true;
    return false;
}

static int wichRsc(server_t *server, player_t *player)
{
    if (strcmp(cmd->commands+5, "food") == 0)
        if (maaap[0] > 0) {
            place_food(server->map, 1);
            player->inventory.food++;
            return 0;
        }
    if (strcmp(cmd->commands+5, "linemate") == 0)
        if (maaap[1] > 0) {
            place_linemate(server->map, 1);
            player->inventory.linemate++;
            return 1;
        }
    if (strcmp(cmd->commands+5, "deraumere") == 0)
        if (maaap[2] > 0) {
            place_deraumere(server->map, 1);
            player->inventory.deraumere++;
            return 2;
        }
    if (strcmp(cmd->commands+5, "sibur") == 0)
        if (maaap[3] > 0) {
            place_sibur(server->map, 1);
            player->inventory.sibur++;
            return 3;
        }
    if (strcmp(cmd->commands+5, "mendiane") == 0)
        if (maaap[4] > 0) {
            place_mendiane(server->map, 1);
            player->inventory.mendiane++;
            return 4;
        }
    if (strcmp(cmd->commands+5, "phiras") == 0)
        if (maaap[5] > 0) {
            place_phiras(server->map, 1);
            player->inventory.phiras++;
            return 5;
        }
    if (strcmp(cmd->commands+5, "thystame") == 0)
        if (maaap[6] > 0) {
            place_thystame(server->map, 1);
            player->inventory.thystame++;
            return 6;
        }
}

bool takeObj(server_t *server, player_t *player, int clifd, vector_t *players)
{
    if (strncmp(cmd->commands, "Take", 4) == 0) {
        if (checkItemExistance(server, player) == true) {
            if (isFinished(player, 7) == true) {
                maaap[wichRsc(server, player)] -= 1;
                dprintf(clifd, "ok\n");
                changeStack(&player->commands);
            }
        } else {
            dprintf(clifd, "ko\n");
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

static int placeObj(server_t *server, player_t *player)
{
    if (strcmp(cmd->commands+4, "food") == 0) {
        player->inventory.food++;
        return 0;
    }
    if (strcmp(cmd->commands+4, "linemate") == 0) {
        player->inventory.linemate++;
        return 1;
    }
    if (strcmp(cmd->commands+4, "deraumere") == 0) {
        player->inventory.deraumere++;
        return 2;
    }
    if (strcmp(cmd->commands+4, "sibur") == 0) {
        player->inventory.sibur++;
        return 3;
    }
    if (strcmp(cmd->commands+4, "mendiane") == 0) {
        player->inventory.mendiane++;
        return 4;
    }
    if (strcmp(cmd->commands+4, "phiras") == 0) {
        player->inventory.phiras++;
        return 5;
    }
    if (strcmp(cmd->commands+4, "thystame") == 0) {
        player->inventory.thystame++;
        return 6;
    }
}

static bool checkInInv(player_t *player)
{
    if (strcmp(cmd->commands+4, "food") == 0) {
        if (player->inventory.food > 0)
            return true;
    }
    if (strcmp(cmd->commands+4, "linemate") == 0) {
        if (player->inventory.linemate > 0)
            return true;
    }
    if (strcmp(cmd->commands+4, "deraumere") == 0) {
        if (player->inventory.deraumere > 0)
            return true;
    }
    if (strcmp(cmd->commands+4, "sibur") == 0) {
        if (player->inventory.sibur > 0);
            return true;
    }
    if (strcmp(cmd->commands+4, "mendiane") == 0) {
        if (player->inventory.mendiane > 0);
            return true;
    }
    if (strcmp(cmd->commands+4, "phiras") == 0) {
        if (player->inventory.phiras > 0)
            return true;
    }
    if (strcmp(cmd->commands+4, "thystame") == 0) {
        if (player->inventory.thystame > 0)
            return true;
    }
    return false;
}

bool setObj(server_t *server, player_t *player, int clifd, vector_t *players)
{
    if (strncmp(cmd->commands, "Set ", 4) == 0) {
        if (checkInInv(player) == true) {
            if (isFinished(player, 7) == true) {
                maaap[placeObj(server, player)] += 1;
                dprintf(clifd, "ok\n");
                changeStack(&player->commands);
            }
        } else {
            dprintf(clifd, "ko\n");
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}

static bool makeIncantation(player_t *player)
{
    if (player->oldPos.x == player->pos.x
    && player->oldPos.y == player->pos.y) {
        return true;
    }
    return (false);
}

static void deleteInInv(player_t *player)
{
    if (player->level == 1) {
        player->inventory.linemate--;
        player->level += 1;
        return;
    }
    if (player->level == 2) {
        player->inventory.linemate--;
        player->inventory.deraumere--;
        player->inventory.sibur--;
        player->level +=1;
        return;
    }
}

bool incentation(server_t *server __attribute__((unused)),
player_t *player, int clifd, vector_t *players)
{
    if (strcmp(cmd->commands, "Incantation") == 0) {
        // if (makeIncantation(player) == false) {
            // dprintf(clifd, "ko\n");
            // changeStack(&player->commands);
        // }
        if (isFinished(player, 300) == true) {
            deleteInInv(player);
            dprintf(clifd, "Elevation underward\nCurrent level: %i\n", (player->level));
            changeStack(&player->commands);
        }
        return true;
    }
    return false;
}