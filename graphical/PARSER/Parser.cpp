/*
** EPITECH PROJECT, 2021
** GRAPHICAL
** File description:
** Parser.cpp
*/

#include <iostream>
#include <string>
#include "Parser.hpp"

void Parser::split(const std::string &str, char delimiteur, std::vector<std::string> &elements)
{
    std::stringstream is(str);
    std::string word;
    while (getline(is, word, delimiteur))
    {
        elements.push_back(word);
    }
}

std::vector<std::string> Parser::splitString(const std::string &str, char delimiteur)
{
    std::vector<std::string> elements;
    split(str, delimiteur, elements);
    return elements;
}

void Parser::getResponseFromServer(const std::string &str)
{
    response_ = this->splitString(str, ' ');
}

int Parser::getHeight(void)
{
    if (response_.size() == 3)
        height_ = std::stoi(response_[2]);
    return this->height_;
}

int Parser::getWidth(void)
{
    if (response_.size() == 3)
        width_ = std::stoi(response_[1]);
    return this->width_;
}

void Parser::clearResponse()
{
    response_.clear();
}