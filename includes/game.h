/*
** EPITECH PROJECT, 2022
** game
** File description:
** header
*/

#ifndef GAME_H_
#define GAME_H_
    #include "player.h"
    #include "server.h"
    #define tmpc ((client_t *)(tmp_c)->data)
    #define tmpp ((player_t *)(tmp_p)->data)
    #define cmd ((commandstack_t *)(player->commands->data))
    #define LEFT 1
    #define RIGHT 2
    #define maaap server->map->ressource[player->pos.y * server->map->width + player->pos.x].available
void game_side(server_t *server, vector_t *clients, vector_t *players);
void changeStack(vector_t **stack);
bool isFinished(player_t *player, int time);

/* Game Action */
bool forward(server_t *server, player_t *player, int clifd, vector_t *players);
bool turnR(server_t *server, player_t *player, int clifd, vector_t *players);
bool turnL(server_t *server, player_t *player, int clifd, vector_t *players);
bool turnL(server_t *server, player_t *player, int clifd, vector_t *players);
bool look(server_t *server, player_t *player, int clifd, vector_t *players);
void make_graphic_action(server_t *server, player_t *player, int clifd, vector_t *players);
bool myFork(server_t *server, player_t *player, int clifd, vector_t *players);
bool eject(server_t *server, player_t *player, int clifd, vector_t *players);
bool takeObj(server_t *server, player_t *player, int clifd, vector_t *players);
bool setObj(server_t *server, player_t *player, int clifd, vector_t *players);
bool incentation(server_t *server, player_t *player, int clifd, vector_t *players);
bool inventory(server_t *server, player_t *player, int clifd, vector_t *players);
bool connectNbr(server_t *server, player_t *player, int clifd, vector_t *players);
void msz(server_t *server, player_t *player, int clifd, vector_t *players);
void bct(server_t *server, player_t *player, int clifd, vector_t *players);
void mct(server_t *server, player_t *player, int clifd, vector_t *players);
void ppo(server_t *server, player_t *player, int clifd, vector_t *players);
void plv(server_t *server, player_t *player, int clifd, vector_t *players);
void ppo(server_t *server, player_t *player, int clifd, vector_t *players);
void pin(server_t *server, player_t *player, int clifd, vector_t *players);
void tna(server_t *server, player_t *player, int clifd, vector_t *players);
void sgt(server_t *server, player_t *player, int clifd, vector_t *players);
void action_c(player_t *player, vector_t *players, char *str);
#endif /* !GAME_H_ */
