/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** tool
*/

#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include "Tool.hpp"

std::vector<std::string> Tool::parseResponse(std::string response, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(response);
    std::string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }
    return result;
}

void Tool::send_command(std::string command, int sockfd)
{
    dprintf(sockfd, "%s\n", command.c_str());
}

std::string Tool::get_response(int sockfd)
{
    int len = 0;
    char buf[4096];

    if ((len = read(sockfd, buf, sizeof(buf))) > 0)
    {
        buf[len - 1] = '\0';
    }
    else
        exit(0);
    return buf;
}
