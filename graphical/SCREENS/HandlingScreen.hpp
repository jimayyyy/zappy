/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** HandlingScreen.hpp
*/

#ifndef HDLSCREENS_HPP_
#define HDLSCREENS_HPP_

#include "Menu.hpp"
#include "Screen.hpp"
#include "Title.hpp"

class handleScreens
{
public:
    handleScreens()
    {
        this->currentScreen = TITLE;
    };
    void initScreens(void);
    GameScreen getGameScreen(void);
    void display(void);
    void switchScreen(GameScreen screen);
    int getPort();
    std::string getMachine();

private:
    // std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    Menu menu;
    Title title;
    GameScreen currentScreen;
};

#endif /*HDLSCREENS_HPP_*/