/*
** EPITECH PROJECT, 2022
** arguments
** File description:
** functions
*/

#include "args.h"
#include <stdbool.h>

bool p(char **arguments, int *j, args_t **mystruct)
{
    if (strcmp(arguments[*j], "-p") == 0) { 
        if (atoi(arguments[*j + 1]) == 0) {
            printf("Invalid port\n");
            return false;
        }
        (*mystruct)->port = atoi(arguments[*j + 1]);
        *j += 1;
        return true;
    }
    return false;
}

bool x(char **arguments, int *j, args_t **mystruct)
{
    if (strcmp(arguments[*j], "-x") == 0) {
        if (atoi(arguments[*j + 1]) < 10 || atoi(arguments[*j + 1]) > 30) {
            printf("-x option only accepts ");
            printf("integer values between 10 and 30\n");
            return false;
        }
        (*mystruct)->width = atoi(arguments[*j + 1]);
        *j += 1;
        return true;
    }
    return false;
}

bool y(char **arguments, int *j, args_t **mystruct)
{
    if (strcmp(arguments[*j], "-y") == 0) {
        if (atoi(arguments[*j + 1]) < 10 || atoi(arguments[*j + 1]) > 30) {
            printf("-y option only accepts ");
            printf("integer values between 10 and 30\n");
            return false;
        }
        (*mystruct)->height = atoi(arguments[*j + 1]);
        *j += 1;
        return true;
    }
    return false;
}