/*
** EPITECH PROJECT, 2021
** GRAPHICAL
** File description:
** GetInfoConnection.hpp
*/

#ifndef GET_INFO_CONNECTION_HPP
#define GET_INFO_CONNECTION_HPP_

#include <string>
#include "Raylib.hpp"

class GetInfoConnection
{
public:
    ~GetInfoConnection(){
        //  free(port);
        // free(machine);
    };
    GetInfoConnection(){};
    std::string getPort(void);
    std::string getMachine(void);

private:
    char port[9 + 1] = "\0";
    char machine[9 + 1] = "\0";
    int letterCount = 0;
    int letterCount2 = 0;
};

#endif