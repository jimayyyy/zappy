/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** window.cpp
*/

#include "window.hpp"

Window::Window()
{
    this->screenWidth_ = 1920;
    this->screenHeight_ = 1080;
}

void Window::initScreen(int width, int height, int fps)
{
    this->screenWidth_ = width;
    this->screenHeight_ = height;
    InitWindow(this->screenWidth_, this->screenHeight_, "ZAPPYLAND");
    SetTargetFPS(fps);
}

int Window::getHeight(void)
{
    return this->screenHeight_;
}

int Window::getWidth(void)
{
    return this->screenWidth_;
}