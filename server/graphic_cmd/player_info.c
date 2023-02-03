/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** player_info
*/

#include "game.h"

static void print_pin(player_t *player, int clifd)
{
    dprintf(clifd, "%d %d %d %d %d %d %d %d %d %d\n",
    player->id, player->pos.x, player->pos.y, player->inventory.food,
    player->inventory.linemate, player->inventory.deraumere,
    player->inventory.sibur, player->inventory.mendiane,
    player->inventory.phiras, player->inventory.thystame);
}

static void print_ppo(player_t *player, int clifd)
{
    dprintf(clifd, "ppo %d %d %d %d\n", player->id, player->pos.x, player->pos.y,
    player->angle);
}

void ppo(server_t *server, player_t *player, int clifd, vector_t *players)
{
    char **tab = my_str_to_word_array_delim(
    ((commandstack_t *)(player->commands->data))->commands, " ");
    vector_t *tmp_p = players;

    if (size_tab(tab) != 2 || !is_number(tab[1]) || strcmp(tab[0], "ppo")) {
        dprintf(clifd, "sbp\n");
        changeStack(&player->commands);
        return;
    }
    while (tmp_p) {
        if (tmp_p->data == NULL)
            break;
        if (tmpp->id == atoi(tab[1]) && tmpp->mode == IA) {
            print_ppo(tmpp, clifd);
            changeStack(&player->commands);
            return;
        }
        tmp_p = tmp_p->next;
    }
    dprintf(clifd, "sbp\n");
    changeStack(&player->commands);
}

void plv(server_t *server, player_t *player, int clifd, vector_t *players)
{
    char **tab = my_str_to_word_array_delim(
    ((commandstack_t *)(player->commands->data))->commands, " ");
    vector_t *tmp_p = players;

    if (size_tab(tab) != 2 || !is_number(tab[1]) || strcmp(tab[0], "plv")) {
        dprintf(clifd, "sbp\n");
        changeStack(&player->commands);
        return;
    }
    while (tmp_p) {
        if (tmp_p->data == NULL)
            break;
        if (tmpp->id == atoi(tab[1]) && tmpp->mode == IA) {
            dprintf(clifd, "%d %d\n", tmpp->id, tmpp->level);
            changeStack(&player->commands);
            return;
        }
        tmp_p = tmp_p->next;
    }
    dprintf(clifd, "sbp\n");
    changeStack(&player->commands);
}

void pin(server_t *server, player_t *player, int clifd, vector_t *players)
{
    char **tab = my_str_to_word_array_delim(
    ((commandstack_t *)(player->commands->data))->commands, " ");
    vector_t *tmp_p = players;

    if (size_tab(tab) != 2 || !is_number(tab[1]) || strcmp(tab[0], "pin")) {
        dprintf(clifd, "sbp\n");
        changeStack(&player->commands);
        return;
    }
    while (tmp_p) {
        if (tmp_p->data == NULL)
            break;
        if (tmpp->id == atoi(tab[1]) && tmpp->mode == IA) {
            print_pin(tmpp, clifd);
            changeStack(&player->commands);
            return;
        }
        tmp_p = tmp_p->next;
    }
    dprintf(clifd, "sbp\n");
    changeStack(&player->commands);
}