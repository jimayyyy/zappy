/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-iuliia.maiorova
** File description:
** Exeptions
*/

#include "Exeptions.hpp"

IAExeptions::IAExeptions(std::string const &message) : _message(message)
{
}

const char* IAExeptions::what() const noexcept
{
    return this->_message.data();
}