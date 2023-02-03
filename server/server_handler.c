/*
** EPITECH PROJECT, 2022
** server
** File description:
** handler
*/

#include <signal.h>
#include <stdio.h>

int singleton_run(int value)
{
    static int still_runing = 1;
    
    if (value == 0) {
        still_runing = 0;
    }
    return still_runing;
}

void sig_handler(int signo)
{
    if (signo == SIGINT) {
        printf("catch sigint\n");
        singleton_run(0);
    }
    if (signo == SIGTERM) {
        printf("catch sigterm\n");
        singleton_run(0);
    }
}