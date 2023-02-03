/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** tool
*/

class Tool
{
public:
    std::vector<std::string> parseResponse(std::string response, char delim);
    void send_command(std::string command, int sockfd);
    std::string get_response(int sockfd);


private:
};
