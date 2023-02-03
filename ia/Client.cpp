/*
** EPITECH PROJECT, 2022
** main
** File description:
** my_teams_client
*/

#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory>
#include "Client.hpp"
#include "Exeptions.hpp"

void Client::choseTeam(void)
{
    std::vector<std::string> response;
    std::string getResponse;

    tool.send_command(team.c_str(), sockfd);
    getResponse = tool.get_response(sockfd);
    if (getResponse.compare("ko") != 0)
    {
        response = tool.parseResponse(getResponse, '\n');
        client_num = atoi(response[0].c_str());
        map.x = atoi(tool.parseResponse(response[1], ' ')[0].c_str());
        map.y = atoi(tool.parseResponse(response[1], ' ')[1].c_str());
        printf("Client Num: %i\n", client_num);
        printf("X:%i && Y:%i\n", map.x, map.y);
        printf("team: %s\n", team.c_str());
        isTeamSet = true;
    }
}

int Client::handle_buffer(void)
{
    while (1)
    {
        FD_ZERO(&current_sockets);
        FD_SET(sockfd, &current_sockets);
        FD_SET(STDIN_FILENO, &current_sockets);
        // if (select(FD_SETSIZE, &current_sockets, NULL, NULL, NULL) == -1)
        //     return EXIT_FAILURE;
        if (isTeamSet == false)
        {
            printf("%s\n", tool.get_response(sockfd).c_str());
            choseTeam();
            VecTrant.emplace_back(rand() % map.x, rand() % map.y, team, sockfd);
        }
        if (isTeamSet == true)
        {
            for (int i = 0; i != VecTrant.size(); i += 1) {
               VecTrant[i].behavior();
                // if (VecTrant[i].getIsReproducing() == true)
                //     VecTrant.emplace_back(rand() % map.x, rand() % map.y, team, sockfd);
            }
        }
    }
    return 0;
}

int Client::setConnect(std::string machine, int port, std::string name)
{
    memset(&client, 0, sizeof(client));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        throw IAExeptions("bad socket");
    client.sin_family = AF_INET;
    inet_aton(machine.c_str(), &(client.sin_addr));
    client.sin_port = htons(port);
    team = name;
    if (connect(sockfd, (struct sockaddr *)&client, sizeof(client)) == -1)
        throw IAExeptions("error on connection");
    return 0;
}

void Client::checkArgs(int ac, char **)
{
    if (ac != 7)
        throw IAExeptions("Error, bad arguments");
}

int main(int ac, char **av)
{
    int port = 0;
    std::string machine;
    std::string name;
    std::unique_ptr<Client> connect = std::make_unique<Client>();
    try {
        connect->checkArgs(ac, av);
        connect->setConnect(av[6], atoi(av[2]), av[4]);
    } catch (IAExeptions const &error) {
        std::cout << error.what() << std::endl;
        return 84;
    }
    connect->handle_buffer();
    return 0;
}