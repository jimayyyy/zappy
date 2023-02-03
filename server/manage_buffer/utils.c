/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** utils
*/

#include <stdbool.h>

bool is_number(char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] < '0' && str[i] > '9')
            return (false);
    }
    return (true);
}

int size_tab(char **tab)
{
    int len = 0;

    for (; tab && tab[len]; len++);
    return (len);
}