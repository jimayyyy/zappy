/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** window.hpp
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "Raylib.hpp"

class Window
{
public:
    Window();
    void initScreen(int width, int height, int fps);
    int getWidth(void);
    int getHeight(void);

private:
    int screenHeight_;
    int screenWidth_;
};

#endif