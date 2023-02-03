/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Screen.cpp
*/

#include "Screen.hpp"
#include <iostream>

AScreen::AScreen()
{
    this->gameScreen = TITLE;
}

GameScreen AScreen::getGameScreen(void)
{
    return this->gameScreen;
}