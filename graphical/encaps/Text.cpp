/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Raylib
*/

#include <iostream>
#include "Raylib.hpp"

RayGraph::Text::Text()
{
}

void RayGraph::Text::drawText(const std::string text, unsigned int x, unsigned int y, unsigned int size, Color color)
{
    DrawText(text.c_str(), x, y, size, color);
}

RayGraph::Text::~Text()
{
}
