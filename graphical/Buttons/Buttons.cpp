/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Buttons.cpp
*/

#include "Buttons.hpp"
#include <string.h>
#include <iostream>
#include <string>

// Buttons::Buttons(Font font, std::string button, coord_t coord, int nbButton, Color color, int size, GameScreen screen) /* : font_(font),*/
// {
//     this->font_ = font;
//     this->button_ = button;
//     this->coordButton_ = coord;
//     this->posButton_ = nbButton;
//     this->color_ = color;
//     this->size_ = size;
//     this->Screen = screen;
//     this->stockColor = color;
// this->rectButton = {coordButton_.x - ((float)size_ / 2), coordButton_.y, ((float)size_) * strlen(button_.c_str()), (float)size};
//     this->mouse_ = {0, 0, 0, 0};
//     this->colorRect_ = GOLD;
//     saveColorRect_ = colorRect_;
// }

std::string Buttons::getButton_(void)
{
    return this->button_;
}

coord_t Buttons::getCoord_(void)
{
    return this->coordButton_;
}

int Buttons::getPosButton_(void)
{
    return this->posButton_;
}

int Buttons::getNbButton_(void)
{
    return this->nbButton;
}

Color Buttons::getColor_(void)
{
    DrawRectangleRounded(this->rectButton, 0.25, 20, this->colorRect_);
    return this->color_;
}

int Buttons::getSize_(void)
{
    return this->size_;
}

void Buttons::update(void)
{
    this->color_ = stockColor;
    this->colorRect_ = saveColorRect_;
    this->mouse_.x = GetMouseX();
    this->mouse_.y = GetMouseY();
    bool collision = CheckCollisionRecs(this->mouse_, this->rectButton);

    if (collision)
    {
        if (IsMouseButtonDown(0) == true)
        {
            this->color_ = RED;
            this->colorRect_ = GOLD;
        }
        else
        {
            this->colorRect_ = BLUE;
        }
    }
}

void Buttons::setColors(Color colorRect, Color colorButton)
{
    this->colorRect_ = colorRect;
    this->color_ = colorButton;
}

coord_t Buttons::getCoordMouse(void)
{
    return {this->mouse_.x, this->mouse_.y};
}

coord_t Buttons::getCoordRect(void)
{
    return {this->rectButton.x, this->rectButton.y};
}