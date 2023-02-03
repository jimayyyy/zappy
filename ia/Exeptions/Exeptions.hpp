/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** Exeptions
*/

#ifndef EXEPTIONS_HPP_
#define EXEPTIONS_HPP_

#include <iostream>
#include <exception>

class IAExeptions : public std::exception {
    private:
        std::string _message;

    public:
        IAExeptions(std::string const &message);
        ~IAExeptions() = default;
        const char *what() const noexcept;
    
    protected:
};

#endif /* !EXEPTIONS_HPP_ */