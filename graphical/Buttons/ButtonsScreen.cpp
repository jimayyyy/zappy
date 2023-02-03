/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** buttons.cpp
*/

#include "Buttons.hpp"
#include <string.h>
#include <iostream>
#include <string>

ButtonsScreen::ButtonsScreen(std::string button, coord_t coord, int nbButton, Color color, int size, GameScreen screen) /* : font_(font),*/
{
    this->button_ = button;
    this->coordButton_ = coord;
    this->posButton_ = nbButton;
    this->color_ = color;
    this->size_ = size;
    this->Screen = screen;
    this->stockColor = color;
    this->rectButton = {coordButton_.x - ((float)size_ / 2), coordButton_.y, ((float)size_) * (button_.length() / 1.1), (float)size};
    this->mouse_ = {0, 0, 0, 0};
    this->colorRect_ = RED;
    saveColorRect_ = colorRect_;
}

GameScreen ButtonsScreen::getScreen_(void)
{
    return this->Screen;
}

// justeavantdisplay() {
//     if Collision()
//         ChangeColor()
//         ProcessColission()
// }

bool ButtonsScreen::changeScreen(void)
{
    bool collision = CheckCollisionRecs(this->mouse_, this->rectButton);
    if (collision)
    {
        if (IsMouseButtonReleased(0) == true)
        {
            this->color_ = this->stockColor;
            this->colorRect_ = this->saveColorRect_;
            return true;
        }
    }
    return false;
}