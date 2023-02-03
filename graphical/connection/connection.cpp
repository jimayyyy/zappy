/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** connection.cpp
*/

#include <sys/time.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "connection.hpp"

Connection::Connection()
{
}

void Connection::sendToServer(void)
{
    int len = 0;
    char buf[256];

    if ((len = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
        if (write(sockfd, &buf, len) == -1)
            perror("write sendToServ c++");
}

int Connection::getFromServer(void)
{
    int len = 0;
    char buf[256];
    buffer.resize(256);
    std::string test;

    len = read(sockfd, &buffer[0], sizeof(buffer[0]));
    if (len < 0)
        return 1;
    buffer.resize(len);
    tmpBuffer.append(buffer);
    std::cout << buffer;
    return 0;
}

int Connection::handleCommunication(void)
{
    fd_set current_sockets;
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    if (isConnect == true)
    {

        FD_ZERO(&current_sockets);
        FD_SET(sockfd, &current_sockets);
        FD_SET(STDIN_FILENO, &current_sockets);
        if (select(FD_SETSIZE, &current_sockets, NULL, NULL, &tv) < 0)
            return EXIT_FAILURE;
        if (FD_ISSET(STDIN_FILENO, &current_sockets))
        {
            sendToServer();
            tmpBuffer.clear();
        }
        if (FD_ISSET(sockfd, &current_sockets))
        {
            getFromServer();
        }
    }
}

int Connection::setConnection(int port, std::string machine)
{
    if (isConnect == false)
    {
        memset(&client, 0, sizeof(client));
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            perror("sockfd");
        client.sin_family = AF_INET;
        inet_aton(machine.c_str(), &(client.sin_addr));
        client.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&client, sizeof(client)) < 0)
        {
            perror("connect");
            return 1;
        }
        if (write(sockfd, "GRAPHIC\n", strlen("GRAPHIC\n")) == -1)
            perror("write setConnection c++");
        isConnect = true;
    }
    return 0;
}

std::string Connection::getBuffer(void) const
{
    return tmpBuffer;
}