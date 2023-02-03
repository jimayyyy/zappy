/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-matteo.dupre
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Screen.hpp"
#include "GetInfoConnection.hpp"

class Menu : public AScreen
{
public:
    Menu();
    ~Menu(){};
    void display(void) override;
    void createButtons(std::string string, coord_t coord, Color color, int size, GameScreen screen);
    void initScreen(GameScreen screen);
    void drawButton(void);
    int getPort(void);
    std::string getMachine(void);

protected:
    std::vector<ButtonsScreen> buttonsScreen_;
    int nbButton;
    int nbButtonEvent;
    std::unique_ptr<RayGraph::Text> text_;
    Texture2D bck;
    std::string port;
    std::string machine;
    GetInfoConnection getInfoCo;
};

#endif /*MENU_HPP_*/