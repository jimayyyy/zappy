/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Buttons.hpp
*/

#ifndef BUTTONS_HPP_
#define BUTTONS_HPP_

#include <string>
#include <vector>
#include "Raylib.hpp"

typedef enum GameScreen
{
    TITLE,
    MENU,
    SETTINGS,
    PAUSE,
    GAMEPLAY,
    EXITSCREEN,
} GameScreen;

typedef struct coord
{
    float x;
    float y;
} coord_t;

class Buttons
{
public:
    std::string getButton_(void);
    coord_t getCoord_(void);
    int getPosButton_(void);
    int getNbButton_(void);
    Color getColor_(void);
    int getSize_(void);
    int getNbButton(void);
    void setColors(Color colorRect, Color colorButton);
    void update(void);
    coord_t getCoordMouse(void);
    coord_t getCoordRect(void);
    int getButtonState_(void);

protected:
    std::string button_;
    coord_t coordButton_;
    Color color_;
    Color stockColor;
    int posButton_;
    int nbButton;
    int size_;
    Rectangle rectButton;
    Rectangle btnBounds_;
    Color colorRect_;
    Color saveColorRect_;
    Rectangle mouse_;
};

class ButtonsScreen : public Buttons
{
public:
    ButtonsScreen(std::string button, coord_t coord, int nbButton, Color Color, int size, GameScreen screen);
    GameScreen getScreen_(void);
    bool changeScreen(void);

protected:
    GameScreen Screen;
    int count = 0;
    RayGraph::Musics effect;
};

class ButtonsEvent : public Buttons
{
public:
    ButtonsEvent(std::string pathTexture, coord_t coord, int nbButton, int size);
    bool changeResolution(void);
    Texture2D getTexture_(void);

protected:
    Texture2D textures_;
    Rectangle srcRec_;
    int btnState_;
    float frameHeight_;
};

#endif /*BUTTONS_HPP_*/