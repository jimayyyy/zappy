/*
** EPITECH PROJECT, 2022
** SERVER
** File description:
** HEADER
*/

#ifndef SERVER_H_
#define SERVER_H_
    #include "top.h"
    #include <stdlib.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>
    #include <string.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/select.h>
    #include <stdbool.h>
    #include "vector.h"
    #include "args.h"
    #include "map.h"
    #define IA 1
    #define GRAPHICAL 2

typedef struct teams_s {
    char *name;
    int size;
    size_t id;
} teams_t;

typedef struct server_s {
    class_c base;
    int socket;
    fd_set current_socket;
    fd_set except_fd;
    fd_set write_fd;
    struct sockaddr_in server;
    map_t *map;
    vector_t *teams;
    clock_t timer;
} server_t;

typedef struct client_s {
    class_c base;
    bool first;
    int clifd;
    int serverfd;
    int id;
    int id_player;
    int id_graphic;
    char *msg;
    char *send;
    char *bufread;
    int mode;
    struct sockaddr_in client;
} client_t;

extern const class_c *server;
extern const class_c *client;

object *new(const class_c *class, ...);
void delete(object *ptr);

void handle_multiple_client(server_t *serv, vector_t *clients, vector_t *player, args_t *args);
int select_cond(server_t *serv, vector_t *clients, vector_t *player, args_t *args);
bool check_args(int ac, char **av, args_t **mystruct);
int singleton_run(int value);
void sig_handler(int signo);
void manage_buffer(char const *buf, client_t *client);
int get_next_line(int fd, char *buffer);
void clean_buffer(char *buffer);
char **my_str_to_word_array_delim(char const *str, char *delim);


#endif /* !SERVER_H_ */
