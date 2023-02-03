/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** client hpp
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>
#include <sys/types.h> /* Voir NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <vector>
#include "Trantorian.hpp"
#include "Exeptions.hpp"

class Client
{
public:
    Client()
    {
    }
    ~Client()
    {
    }
    int handle_buffer(void);
    int setConnect(std::string machine, int port, std::string name);
    void choseTeam(void);
    void checkArgs(int ac, char **av);
private:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client;
    fd_set current_sockets;
    std::vector<Trantorian> VecTrant;
    bool isTeamSet = false;
    int client_num = -1;
    std::string team;
    position_t map;
    Tool tool;
};

#endif /* !CLIENT_HPP_ */
