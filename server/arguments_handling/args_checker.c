/*
** EPITECH PROJECT, 2022
** argument
** File description:
** checker
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "server.h"
#include "vector.h"
#include <string.h>

av_t args[] = {
    {"-p"},
    {"-x"},
    {"-y"},
    {"-n"},
    {"-c"},
    {"-f"},
};

av_t mystructure[] = {
    {"port"},
    {"width"},
    {"height"},
    {"nbClientMaxPerTeam"},
    {"freq"},
};

static bool condition(char *arg)
{
    for (int i = 0; i != TABSIZE; i++)
        if (strcmp(args[i].name, arg) == 0)
            return true;
    return false;
}

static int gotonext(int i, char **av, int ac)
{
    if (i == ac)
        return i;
    for (int j = 0; j != TABSIZE; j++)
        if (strcmp(args[j].name, av[i]) == 0)
            return i;
    return gotonext(i+1, av, ac);
}

static bool first_check(int ac, char **av)
{
    for (int i = 1; i != ac; i++) {
        i = (i == 1 ? gotonext(i, av, ac) : gotonext(i+1, av, ac));
        if (i == ac)
            return true;
        if (condition(av[i]) == false) {
            return false;;
        }
    }
    return true;
}

static bool isStructFilled(void **mystruct)
{
    void *cpystruct = (*mystruct);

    for (int i = 0; i != STRUCTSIZE; i++, cpystruct += sizeof(int)) {
        if ((*(int *)mystruct) == -1) {
            printf("Arguments is missing !\n");
            printf("%s\n", HELP);
            return false;
        }
    }
    return true;
}

bool check_args(int ac, char **av, args_t **mystruct)
{
    if (first_check(ac, av) == false)
        return false;
    for (int j = 1; j <= ac; j++) {
        if (j == ac)
            break;
        if (check_function(av, &j, mystruct, ac) == false) {
            return false;
        }
    }
    return isStructFilled((void **)mystruct);
}
