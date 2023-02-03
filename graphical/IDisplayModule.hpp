/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** IDisplayModule.hpp
*/

#ifndef IDISPLAY_MODULE_HPP_
#define IDISPLAY_MODULE_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "window.hpp"
#include "connection.hpp"
#include "Parser.hpp"

class IDisplayModule
{
public:
    virtual ~IDisplayModule() = default;
    virtual void loadMap(std::string path) = 0;
    virtual void displayMap(void) = 0;
};

class DisplayModule : public IDisplayModule
{
public:
    DisplayModule(int width, int height);
    int connectWithServer(uint16_t port, std::string address);
    void loadMap(std::string path) override;
    void displayMap(void) override;
    bool getIsRunning();
    void manageCamera(void);
    void handleBuffer(void);
    void getDimension(void);
    bool mapIsDrawable(void);
    void getFood(int x, int y);

public:
    Window window;
    std::vector<std::string> map;
    std::unique_ptr<RayGraph::Shape> shape;
    std::unique_ptr<RayGraph::ModelC> modelLib;
    std::unique_ptr<RayGraph::Map> caseMap;
    bool isRunning = true;
    bool readyToDraw = false;
    Camera3D camera;
    std::unique_ptr<Connection> connection;
    std::unique_ptr<Parser> parser;
    std::string machine_;
    uint16_t port_;
    bool testBool = false;
    int width = 0;
    int height = 0;
    bool isParser = true;
};

#endif