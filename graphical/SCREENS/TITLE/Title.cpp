/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Title.cpp
*/

#include <string>
#include <iostream>
#include <string.h>
#include "Title.hpp"

Title::Title()
{
    coord = 0;
    coord2 = 3840;
    sizeText = 100;
    tmp = true;
    frameCounter = 0;
}

void Title::initScreen(GameScreen screen)
{
    this->background_ = LoadTexture("GRAPHICAL/background.png");
    this->text_ = std::make_unique<RayGraph::Text>();
    //  this->gameScreen = TITLE;
}

void Title::display(void)
{
    const std::string message = "Press Enter to Start";
    // screenValue = (Vector2){GetWidth(), GetHeight()};
    DrawTexture(this->background_, coord, 0, WHITE);
    DrawTexture(this->background_, coord2, 0, WHITE);
    text_->drawText("ZAPPY", (float)(this->getWidth() / 3 - (sizeText * 0.1)), (float)this->getHeight() / 4, sizeText, GOLD);
    // DrawTextEx(GetFontDefault(), "BOMBERMAN", (Vector2){(float)(this->getWidth() / 3 - (sizeText * 0.9)), (float)this->getHeight() / 4}, sizeText, 1.0, GOLD);
    text_->drawText(TextSubtext(message.c_str(), 0, frameCounter / 10), (float)this->getWidth() / 3, (float)this->getHeight() / 2, 50, GOLD);
    coord -= 0.3;
    coord2 -= 0.3;
    frameCounter += 0.1;
    if (sizeText <= 100)
        tmp = true;
    if (sizeText >= 200)
        tmp = false;
    if (tmp == false)
        sizeText -= 0.1;
    else
        sizeText += 0.1;
    if (coord <= -3840)
        coord = 3840;
    if (coord2 <= -3840)
        coord2 = 3840;
    if (IsKeyPressed(KEY_ENTER) == true)
    {
        this->gameScreen = MENU;
    }
}