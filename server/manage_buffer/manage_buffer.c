/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** manage_buffer
*/

#include "server.h"
#include <ctype.h>

static void clean_extra_spaces(char *buffer)
{
    int i = 0;
    int x = 0;

    if (!buffer)
        return;
    for (; buffer[i]; ++i)
        if (!isspace(buffer[i]) || (i > 0 && !isspace(buffer[i-1])))
            buffer[x++] = buffer[i];
    buffer[x] = '\0';
}

void clean_buffer(char *buffer)
{
    if (!buffer)
        return;
    for (int i = 0; i < 4096 && buffer[i]; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\r')
            buffer[i] = '\0';
        else if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    clean_extra_spaces(buffer);
}

int get_next_line(int fd, char *buffer)
{
    memset(buffer, 0, 4096);
    int r = read(fd, buffer, 4096);

    if (r == -1)
        perror("read get_next_line");
    return (r);
}


void send_cmd(char *str, client_t *client)
{
    if (client->msg) {
        asprintf(&client->send, "%s%s", client->msg, str);
        free(client->msg);
        client->msg = NULL;
    } else
       asprintf(&client->send, "%s", str);
    if (client->send != NULL) {
        if (client->bufread)
            free(client->bufread);
        client->bufread = NULL;
        printf("client says : %s\n", client->send);
        client->bufread = strdup(client->send);
        free(client->send);
        client->send = NULL;
    }
}

void manage_buffer(char const *buf, client_t *client)
{
    char *temp = strdup(buf);
    char **tab = my_str_to_word_array_delim(buf, "\n");
    char *prev_msg = NULL;
    int i = 0;

    for (; tab && tab[i] && tab[i + 1]; i++) {
        clean_buffer(tab[i]);
        send_cmd(tab[i], client);
    }
    clean_buffer(tab[i]);
    if (tab && tab[i] && strlen(tab[i]) > 0) {
        if (buf[strlen(buf) - 1] == '\n') {
            send_cmd(tab[i], client);
        } else {
            !client->msg ? asprintf(&client->msg, "%s", tab[i]) :
            asprintf(&client->msg, "%s%s", client->msg, tab[i]);
        }
    }
}