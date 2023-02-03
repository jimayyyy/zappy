/*
** EPITECH PROJECT, 2022
** args
** File description:
** header
*/

#ifndef ARGS_H_
#define ARGS_H_
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "vector.h"
    #define TABSIZE 6
    #define PTRFUNCTIONSIZE 5
    #define STRUCTSIZE 5
    #define HELP        "USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n\
\tport is the port number\n\
\twidth is the width of the world\n\
\theight is the height of the world\n\
\tnameX is the name of the team X\n\
\tclientsNb is the number of authorized clients per team\n\
\tfreq is the reciprocal of time unit for execution of actions"

typedef struct args_s {
    int port;
    int width;
    int height;
    int clientnb;
    int freq;
    vector_t *teams;
} args_t;

typedef struct av_s {
    char *name;
} av_t;

bool p(char **arguments, int *j, args_t **mystruct);
bool x(char **arguments, int *j, args_t **mystruct);
bool y(char **arguments, int *j, args_t **mystruct);
bool check_function(char **arguments, int *j, args_t **mystruct, int ac);
bool createTeam(char *name, int id, args_t **mystruct);
int size_tab(char **tab);
bool is_number(char *str);

#endif /* !ARGS_H_ */
