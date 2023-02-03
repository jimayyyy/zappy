/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** HandlingScreen.cpp
*/

#include "HandlingScreen.hpp"

GameScreen handleScreens::getGameScreen(void)
{
    return this->currentScreen;
}

void handleScreens::initScreens(void)
{
    menu.initScreen(this->currentScreen);
    title.initScreen(this->currentScreen);
}

void handleScreens::display(void)
{
    // Texture2D tmp = LoadTexture("GRAPHICAL/resources/background.png");
    switch (this->currentScreen)
    {
    case (TITLE):
        title.display();
        this->currentScreen = title.getGameScreen();
        break;
    case (MENU):
        menu.display();
        this->currentScreen = menu.getGameScreen();
        break;
    case (EXITSCREEN):
        exit(0);
        break;
    case (GAMEPLAY):
        if (IsKeyPressed(KEY_P))
            this->currentScreen = PAUSE;
        break;
    default:
        break;
    }
}

void handleScreens::switchScreen(GameScreen screen)
{
    this->currentScreen = screen;
}

int handleScreens::getPort(void)
{
    return menu.getPort();
}

std::string handleScreens::getMachine(void)
{
    return menu.getMachine();
}