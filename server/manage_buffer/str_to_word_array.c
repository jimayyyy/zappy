/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int delimiter(char c, char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (delim[i] == c)
            return (1);
    return (0);
}

int count_words(char const *str, char *delim)
{
    int countdelim = 0;

    for (int i = 0; str[i]; i++) {
        if (delimiter(str[i], delim) == 1)
            countdelim++;
    }
    return (countdelim);
}

char **my_str_to_word_array_delim(char const *str, char *delim)
{
    int j = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (count_words(str, delim) + 2));
    if (tab == NULL)
        perror("malloc str2wordArray");
    int len = strlen(str);

    for (int i = 0; i < len; i += j+1, k++) {
        for (j = 0; str[i + j] && delimiter(str[i + j], delim) == 0; j++);
        tab[k] = malloc(sizeof(char) * (j + 1));
        if (tab[k] == NULL)
            perror("malloc str2wordArray");
        tab[k][j] = 0;
        strncpy(tab[k], &str[i], j);
    }
    tab[k] = NULL;
    return (tab);
}

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    tab = NULL;
}

char *my_strcat(char *dest, char const *src)
{
    char *tmp = malloc(sizeof(char *) * (strlen(dest)));
    if (tmp == NULL)
        perror("malloc strcat");
    tmp = strcpy(tmp, dest);
    int destlen = strlen(tmp) + strlen(src);

    dest = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));
    if (dest == NULL)
        perror("malloc strcat");
    for (int i = 0, j = 0; i != destlen; ) {
        for (; tmp[j] != '\0'; j++, i++) {
            dest[i] = tmp[j];
        }
        for (j = 0; src[j] != '\0'; j++, i++) {
            dest[i] = src[j];
        }
    }
    free(tmp);
    dest[destlen] = '\0';
    return dest;
}