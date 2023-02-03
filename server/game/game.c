/*
** EPITECH PROJECT, 2022
** game
** File description:
** function
*/

#include "game.h"
#include <string.h>

static iacmd_t act[] = {
    {"Forward"},
    {"Left"},
    {"Right"},
    {"Look"},
    {"Inventory"},
    {"Connect_nbr"},
    {"Fork"},
    {"Eject"},
    {"Incantation"},
};

static iacmd_t actp[] = {
    {"Take"},
    {"Set"},
};

void changeStack(vector_t **commands)
{
    if (size((*commands)) == 1) {
        (*commands)->data = NULL;
        (*commands)->next = NULL;
    } else {
        (*commands) = (*commands)->next;
        ((commandstack_t *)(*commands)->data)->timer = clock();
    }
}

static void make_action(server_t *server, player_t *player, int clifd, vector_t *players)
{
    bool (*function[11])(server_t *, player_t *, int, vector_t *) = {&forward, &turnL, &turnR,
    &look, &myFork, &eject, &incentation, &connectNbr, &inventory, &takeObj, &setObj};

    for (int i = 0; i != ACTIONLIST-3; i++) {
        if (strcmp(((commandstack_t *)(player->commands->data))->commands, act[i].action) == 0) {
            for (int j = 0; j != 11; j++) {
                if ((*function[j])(server, player, clifd, players) == true) {
                    return;
                }
            }
        }
    }
    for (int i = 0; i != 2; i++) {
        if (strncmp(((commandstack_t *)(player->commands->data))->commands, actp[i].action, 4) == 0
        && strlen(((commandstack_t *)(player->commands->data))->commands) >= 4) {
            for (int j = 8; j != 11; j++) {
                if ((*function[j])(server, player, clifd, players) == true) {
                    return;
                }
            }
        }
    }
    changeStack(&player->commands);
    dprintf(clifd, "ko\n");
    return;
}

static player_t *find_player(int id, vector_t *players)
{
    vector_t *tmp_p = players;

    while (tmp_p) {
        if (tmp_p->data == NULL)
            break;
        if (tmpp->id == id) {
            return (tmpp);
        }
        tmp_p = tmp_p->next;
    }
}

static void mode_ia(server_t *server, player_t *player, int clifd, vector_t *players)
{
    make_action(server, player, clifd, players);
}

static void mode_graphic(server_t *server, player_t *player, int clifd, vector_t *players)
{
    make_graphic_action(server, player, clifd, players);
}

void push_to_stack(char *action, player_t *player)
{
    if (size(player->commands) < 10) {
        commandstack_t *mycmd = malloc(sizeof(commandstack_t));
        if (mycmd == NULL)
            perror("malloc push to stack");
        mycmd->commands = strdup(action);
        if (size(player->commands) == 1)
            mycmd->timer = clock();
        push_back(player->commands, (void *)mycmd);
    }
}

static bool checkStack(player_t *player)
{
    vector_t *tmp_cmd = player->commands;

   // printf("stack size : %i\n", size(player->commands));
    if (size(player->commands) >= 1) {
        if (((commandstack_t *)(player->commands)->data) == NULL)
            return false;
        if (((commandstack_t *)(player->commands)->data)->commands != NULL)
            return true;
    }
    return false;
}

static int find_clifd(player_t *player, vector_t *clients)
{
    vector_t *tmp_c = clients;

    while (tmp_c) {
        if (tmp_c->data == NULL)
            break;
        if (tmpc->id_graphic == player->id || tmpc->id_player == player->id) {
            return tmpc->clifd;
        }
        tmp_c = tmp_c->next;
    }
    return 0;
}

static void checkDeath(server_t **server, player_t *player, int life)
{
    vector_t *tmp_s = (*server)->teams;
    clock_t end = clock();
    float cd = (float)(life / (float)player->cd);
    long double millis = ((end - (player->timer)) * 1000) / (CLOCKS_PER_SEC * 1000);

    if (millis > cd && player->mode != GRAPHICAL) {
        player->life = 0;
        if (player->life == 0) {
            if (player->inventory.food >= 1) {
                player->inventory.food--;
                player->life = 128;
                return;
            }
        }
        player->status = dead;
        while (tmp_s) {
            if (strcmp(player->team, ((teams_t *)(tmp_s->data))->name) == 0) {
                ((teams_t *)(tmp_s->data))->size++;
            }
            tmp_s = tmp_s->next;
        }
        dprintf(player->frk, "dead\n");
        close(player->frk);
        player->frk = -1;
    }
}

static void checkResetMap(server_t *server, vector_t *players, int cd)
{
    clock_t end = clock();
    float cds = (float)(20 / (float)cd);
    long double millis = ((end - (server->timer)) * 1000) / (CLOCKS_PER_SEC * 1000);

    if (millis > cds) {
        // tappelle la fonction ici;
        if (!place_food(server->map, 2))
            replace(server->map, 0, players);
        if (!place_linemate(server->map, 2))
            replace(server->map, 1, players);
        if (!place_deraumere(server->map, 2))
            replace(server->map, 2, players);
        if (!place_sibur(server->map, 2))
            replace(server->map, 3, players);
        if (!place_mendiane(server->map, 2))
            replace(server->map, 4, players);
        if (!place_phiras(server->map, 2))
            replace(server->map, 5, players);
        if (!place_thystame(server->map, 2))
            replace(server->map, 6, players);
        server->timer = clock();
    }
}

void game_side(server_t *server, vector_t *clients, vector_t *players)
{
    // tmpc => define dans mon game.h.
    vector_t *tmp_c = clients;
    vector_t *tmp_p = players;

    while (tmp_c) {
        if (tmp_c->data == NULL)
            break;
        if (tmpc->bufread != NULL) {
            if (tmpc->id_player != -1)
                push_to_stack(tmpc->bufread, find_player(tmpc->id_player, players));
            else if (tmpc->id_graphic != -1)
                push_to_stack(tmpc->bufread, find_player(tmpc->id_graphic, players));
            free(tmpc->bufread);
            tmpc->bufread = NULL;
        }
        tmp_c = tmp_c->next;
    }
    while (tmp_p) {
        if (tmp_p->data == NULL)
            break;
        checkResetMap(server, players, tmpp->cd);
        checkDeath(&server, tmpp, tmpp->life);
        if (checkStack(tmpp) == true && tmpp->status == 1) {
            if (size(tmpp->commands) >= 1 && (tmpp->commands->data) != NULL) {
                tmpp->mode == IA ? mode_ia(server, tmpp, find_clifd(tmpp, clients), players) :
                mode_graphic(server, tmpp, find_clifd(tmpp, clients), players);
            }
        }
        tmp_p = tmp_p->next;
    }
}
