/*
** EPITECH PROJECT, 2022
** n option
** File description:
** function
*/

#include "args.h"
#include "server.h"
#include <stdbool.h>
#include "vector.h"

static bool checkifexists(vector_t *teamsList, char *actual)
{
    while (teamsList) {
        if (strcmp(((teams_t *)(teamsList)->data)->name, actual) == 0)
            return true;
        teamsList = teamsList->next;
    }
    return false;
}

bool createTeam(char *name, int id, args_t **mystruct)
{
    teams_t *myteam;
    if (checkifexists((((args_t *)(*mystruct))->teams), name) == true
        && (*mystruct)->teams != NULL)
        return false;
    if ((*mystruct)->teams == NULL)
        (*mystruct)->teams = init();
    myteam = malloc(sizeof(teams_t));
    if (myteam == NULL)
        perror("malloc create team");
    myteam->id = id;
    myteam->name = strdup(name);
    push_back(((*mystruct)->teams), (void *)myteam);
    return true;
}