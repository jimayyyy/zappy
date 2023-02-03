/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** menu->cpp
*/

#include <string>
#include <iostream>
#include <string.h>
#include "Menu.hpp"

Menu::Menu()
{
}

void Menu::display(void)
{
    DrawTexture(this->bck, 0, 0, WHITE);
    drawButton();
    port = this->getInfoCo.getPort();
    machine = this->getInfoCo.getMachine();
}

void Menu::initScreen(GameScreen Screen)
{
    this->bck = LoadTexture("GRAPHICAL/resources/background2.png");
    createButtons("EXIT", {(float)this->getWidth() / 15.0f, this->getHeight() / 1.5f}, GOLD, 100, EXITSCREEN);
    createButtons("PLAY", {(float)this->getWidth() / 2.0f, this->getHeight() / 1.5f}, GOLD, 100, GAMEPLAY);
    this->text_ = std::make_unique<RayGraph::Text>();
    this->bck = LoadTexture("GRAPHICAL/menu.png");
}

void Menu::createButtons(std::string string, coord_t coord, Color color, int size, GameScreen screen)
{
    ButtonsScreen buttons(string, coord, this->nbButton, color, size, screen);
    this->buttonsScreen_.push_back(buttons);
    this->nbButton++;
}
void Menu::drawButton(void)
{
    coord_t tmpCoord;
    this->gameScreen = MENU;

    for (int i = 0; i != this->nbButton; i++)
    {
        buttonsScreen_[i].update();
        tmpCoord = {(float)buttonsScreen_[i].getCoord_().x, (float)buttonsScreen_[i].getCoord_().y};
        if (this->nbButton > 0 && buttonsScreen_[i].changeScreen() == true)
        {
            this->gameScreen = (GameScreen)buttonsScreen_[i].getScreen_();
            return;
        }
        text_->drawText(buttonsScreen_[i].getButton_(), tmpCoord.x, tmpCoord.y, buttonsScreen_[i].getSize_(), buttonsScreen_[i].getColor_());
    }
}

int Menu::getPort(void)
{
    return std::stoi(port);
}

std::string Menu::getMachine(void)
{
    return machine;
}