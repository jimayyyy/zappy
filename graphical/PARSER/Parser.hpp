/*
** EPITECH PROJECT, 2021
** GRAPHICAL
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

class Parser
{
public:
    void split(const std::string &chaine, char delimiteur, std::vector<std::string> &elements);
    std::vector<std::string> splitString(const std::string &chaine, char delimiteur);
    void getResponseFromServer(const std::string &str);
    void clearResponse(void);
    int getWidth(void);
    int getHeight(void);

private:
    int width_ = 0;
    int height_ = 0;
    std::vector<std::string> response_;
};

#endif