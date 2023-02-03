/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** DisplayModule.cpp
*/

#include <dlfcn.h>
#include <string.h>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "IDisplayModule.hpp"

DisplayModule::DisplayModule(int width, int height)
{
    // this->shape = std::make_unique<RayGraph::Shape>();
    connection = std::make_unique<Connection>();
    parser = std::make_unique<Parser>();
    this->caseMap = std::make_unique<RayGraph::Map>(this->parser->getWidth(), this->parser->getHeight(), connection->getBuffer());
}

void DisplayModule::loadMap(std::string path)
{
    std::ifstream file(path);
    std::string line;
    if (!file.is_open())
        return;
    while (getline(file, line))
    {
        map.push_back(line);
    }
    file.close();
}

void DisplayModule::displayMap(void)
{
    UpdateCamera(&camera);
    BeginMode3D(camera);
    this->modelLib->DrawModelC("bg", (Vector3){10, -70, -100}, 500);

    // if (readyToDraw == true)
    for (int y = 0; y != this->height; y++)
    {
        for (int x = 0; x != this->width; x++)
        {
            this->modelLib->DrawModelC("floor", (Vector3){(float)y - 5, 0, (float)x - 5}, 0.009);
            this->getFood(x, y);
        }
        // this->caseMap->getMap()[y].drawCase(x, y);
    }
    EndMode3D();
}

bool DisplayModule::getIsRunning()
{
    if (!WindowShouldClose())
        isRunning = true;
    else
        isRunning = false;
    return isRunning;
}

void DisplayModule::getFood(int x, int y)
{
    std::vector<std::string> tmp = parser->splitString(connection->getBuffer(), '\n');

    for (int i = 1; i != tmp.size() + 1; i++)
    {
        if (strcmp("bct", parser->splitString(tmp[i - 1], ' ')[0].c_str()) == 0 && parser->splitString(tmp[i - 1], ' ').size() >= 10)
        {
            parser->getResponseFromServer(tmp[i - 1]);
            if (std::stoi(parser->splitString(tmp[i - 1], ' ')[4]) != 0)
                this->shape->drawCube({(float)std::stoi(parser->splitString(tmp[i - 1], ' ')[1]) - 5, 0, (float)std::stoi(parser->splitString(tmp[i - 1], ' ')[2]) - 5}, 0.5, 0.1, 0.5, BLUE);
            if (std::stoi(parser->splitString(tmp[i - 1], ' ')[3]) != 0)
                this->shape->drawCube({(float)std::stoi(parser->splitString(tmp[i - 1], ' ')[1]) - 5, 0.2, (float)std::stoi(parser->splitString(tmp[i - 1], ' ')[2]) - 5}, 0.5, 0.1, 0.5, GREEN);
            if (std::stoi(parser->splitString(tmp[i - 1], ' ')[5]) != 0)
                this->shape->drawCube({(float)std::stoi(parser->splitString(tmp[i - 1], ' ')[1]) - 5, 0.4, (float)std::stoi(parser->splitString(tmp[i - 1], ' ')[2]) - 5}, 0.5, 0.1, 0.5, WHITE);
            if (std::stoi(parser->splitString(tmp[i - 1], ' ')[6]) != 0)
                this->shape->drawCube({(float)std::stoi(parser->splitString(tmp[i - 1], ' ')[1]) - 5, 0.6, (float)std::stoi(parser->splitString(tmp[i - 1], ' ')[2]) - 5}, 0.5, 0.1, 0.5, YELLOW);
            if (std::stoi(parser->splitString(tmp[i - 1], ' ')[7]) != 0)
                this->shape->drawCube({(float)std::stoi(parser->splitString(tmp[i - 1], ' ')[1]) - 5, 0.8, (float)std::stoi(parser->splitString(tmp[i - 1], ' ')[2]) - 5}, 0.5, 0.1, 0.5, RED);
            if (std::stoi(parser->splitString(tmp[i - 1], ' ')[8]) != 0)
                this->shape->drawCube({(float)std::stoi(parser->splitString(tmp[i - 1], ' ')[1]) - 5, 1, (float)std::stoi(parser->splitString(tmp[i - 1], ' ')[2]) - 5}, 0.5, 0.1, 0.5, MAGENTA);

            // testBool = true;
        }
        // if (testBool == true)
    }
    return;
}

bool DisplayModule::mapIsDrawable(void)
{
    return this->readyToDraw;
}

int DisplayModule::connectWithServer(uint16_t port, std::string address)
{
    return connection->setConnection(port, address);
}

void DisplayModule::handleBuffer(void)
{
    connection->handleCommunication();
}

// void DisplayModule::getDimension(void)
// {
//     if (connection->getBuffer().length() < 9)
//         return;
//     if (strcmp("msz", parser->splitString(connection->getBuffer(), ' ')[0].c_str()) == 0)
//     {
//         parser->getResponseFromServer(connection->getBuffer());
//         this->width = parser->getWidth();
//         this->height = parser->getHeight();
//         readyToDraw = true;
//     }
// }

void DisplayModule::getDimension(void)
{
    std::vector<std::string> tmp = parser->splitString(connection->getBuffer(), '\n');

    for (int i = 0; i != tmp.size(); i++)
    {
        if (strcmp("msz", parser->splitString(tmp[i], ' ')[0].c_str()) == 0)
        {
            parser->getResponseFromServer(tmp[i]);
            this->width = parser->getWidth();
            this->height = parser->getHeight();
            readyToDraw = true;
            break;
        }
    }
    parser->getResponseFromServer(connection->getBuffer());
}

void DisplayModule::manageCamera(void)
{
    this->modelLib = std::make_unique<RayGraph::ModelC>();
    this->modelLib->initCaseMod();
    this->modelLib->initBgMod();
    this->caseMap->fillMap();

    // camera = {0};
    // camera.position = (Vector3){6.0f, 20.0f, 20.0f}; // Camera position
    // camera.target = (Vector3){6.0f, -10.0f, 0.0f};  // Camera looking at point
    // camera.up = (Vector3){0.0f, 1.0f, 0.0f};        // Camera up vector (rotation towards target)
    // camera.fovy = 25.0f;                            // Camera field-of-view Y
    // camera.projection = CAMERA_PERSPECTIVE;
    camera = {{16.0f, 14.0f, 16.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 20.0f, 0};
    // camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    // camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    // camera.fovy = 45.0f;                                // Camera field-of-view Y
    // camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
}