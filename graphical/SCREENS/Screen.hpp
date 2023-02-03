/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Screen.hpp
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "raylib.h"
#include "Buttons.hpp"
#include "raymath.h"
#include <memory>
#include "window.hpp"

class AScreen : public Window
{
public:
    AScreen();
    virtual void display(void) = 0;
    GameScreen getGameScreen(void);

protected:
    RayGraph::Musics music;
    GameScreen gameScreen;
    int size_;
};

#endif /*SCREEN_HPP_*/