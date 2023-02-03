/*
** EPITECH PROJECT, 2022
** arguments
** File description:
** function
*/

#include "args.h"
#include "server.h"
#include <stdbool.h>
#include "vector.h"

av_t args1[] = {
    {"-p"},
    {"-x"},
    {"-y"},
    {"-n"},
    {"-c"},
    {"-f"},
};

static bool n_args(char **arguments, int *j)
{
    for (int i = 0; i != TABSIZE; i++) {
        if (strcmp(args1[i].name, arguments[*j]) == 0) {
            *j -= 1;
            return true;
        }
    }
    return false;
}

static bool n(char **arguments, int *j, args_t **mystruct, int ac)
{
    static int id = 1;

    if (strcmp(arguments[*j], "-n") == 0) {
        *j += 1;
        for (*j; *j != ac; *j += 1) {
            if (n_args(arguments, j) == true)
                return true;
            if (createTeam(arguments[*j], id, mystruct) == false) {
                printf("-n option only accepts unique team names\n");
                return false;
            };
            id++;
        }
        return true;
    }
    return false;
}

static bool c(char **arguments, int *j, args_t **mystruct)
{
    if (strcmp(arguments[*j], "-c") == 0) {
        if (atoi(arguments[*j + 1]) == 0) {
            printf("Invalid client nb\n");
            return false;
        }
        (*mystruct)->clientnb = atoi(arguments[*j + 1]);
        *j += 1;
        return true;
    }
    return false;
}

static bool f(char **arguments, int *j, args_t **mystruct)
{
    if (strcmp(arguments[*j], "-f") == 0) {
        if (atoi(arguments[*j + 1]) < 2 || atoi(arguments[*j + 1]) > 10000) {
            printf("-f option only accepts ");
            printf("integer values between 2 and 10000\n");
            return false;
        }
        (*mystruct)->freq = atoi(arguments[*j + 1]);
        *j += 1;
        return true;
    }
    return false;
}

bool check_function(char **arguments, int *j, args_t **mystruct, int ac)
{
    bool (*function[PTRFUNCTIONSIZE])(char **, int *, args_t **) =
        {&p, &x, &y, &c, &f};
    for (int i = 0; i != PTRFUNCTIONSIZE; i++)
        if ((*function[i])(arguments, j, mystruct) == true)
            return true;
    return n(arguments, j, mystruct, ac);
}