/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** main.cpp
*/

#include "IDisplayModule.hpp"
#include "HandlingScreen.hpp"

int main(void)
{
    std::unique_ptr<DisplayModule> display = std::make_unique<DisplayModule>(1920, 1080);
    std::unique_ptr<handleScreens> hdlScreen = std::make_unique<handleScreens>();
    //  display->loadMap();
    // if (display->connectWithServer(atoi(av[1]), av[2]))
    //     return 84;
    InitWindow(1920, 1080, "ZAPPY");
    hdlScreen->initScreens();
    display->manageCamera();

    while (display->getIsRunning())
    {
        ClearBackground(WHITE);
        BeginDrawing();
        hdlScreen->display();
        switch (hdlScreen->getGameScreen())
        {
        case (GAMEPLAY):
            if (display->connectWithServer(hdlScreen->getPort(), hdlScreen->getMachine()) == 1)
                hdlScreen->switchScreen(MENU);
            display->getDimension();
            display->handleBuffer();
            // display->getFood(4, 0);
            display->displayMap();
            // display->getFood(0, 0);
            break;
        default:
            break;
        }
        EndDrawing();
    }
    return 0;
}