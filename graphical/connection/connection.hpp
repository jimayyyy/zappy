/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** connection.hpp
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <stdexcept>
#include <vector>

class Connection
{
public:
    Connection();
    void sendToServer(void);
    int getFromServer(void);
    int handleCommunication(void);
    int setConnection(int port, std::string machine);
    std::string getBuffer(void) const;

private:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client;
    std::string buffer;
    std::string tmpBuffer;
    std::vector<std::string> map;
    bool isConnect = false;
};

#endif