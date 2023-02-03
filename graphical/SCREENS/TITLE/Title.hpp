/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Title.hpp
*/

#ifndef TITLE_HPP_
#define TITLE_HPP_

#include "Screen.hpp"

class Title : public AScreen
{
public:
    Title();
    void display(void) override;
    void initScreen(GameScreen screen);

protected:
    Texture2D background_;
    Texture2D background2_;
    std::unique_ptr<RayGraph::Text> text_;
    float coord;
    float coord2;
    float sizeText;
    Vector2 screenValue;
    bool tmp = false;
    float frameCounter;
    int count = 0;
};

#endif /*TITLE_HPP_*/