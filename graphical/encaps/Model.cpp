/*
** EPITECH PROJECT, 2022
** Indiee
** File description:
** Model
*/

#include "Raylib.hpp"
#include "raymath.h"
#include <iostream>
#include <iomanip>
#include <memory>

RayGraph::ModelC::ModelC()
{
}

void RayGraph::ModelC::initRssMod()
{
    // init resources differents textures
    this->textureMap.emplace("sibur", LoadTexture("GRAPHICAL/asset/quartz/textures/quartz.png"));
    this->textureMap.emplace("phiras", LoadTexture("GRAPHICAL/asset/emerald/textures/emerald.png"));
    this->textureMap.emplace("deraumere", LoadTexture("GRAPHICAL/asset/quartz/textures/quartz.png"));
    this->textureMap.emplace("linemate", LoadTexture("GRAPHICAL/asset/diamond/textures/diamond.png"));
    this->textureMap.emplace("mendiane", LoadTexture("GRAPHICAL/asset/magic/textures/magic.png"));
    this->textureMap.emplace("thystame", LoadTexture("GRAPHICAL/asset/energy/textures/energy.png"));

    // init model resources
    this->modelMap.emplace("sibur", modelLoad(LoadModel("GRAPHICAL/../asset/jade/jade.obj"), 0, 0, this->getTexture("sibur")));
    this->modelMap.emplace("phiras", modelLoad(LoadModel("GRAPHICAL/../asset/emerald/emerald.obj"), 0, 0, this->getTexture("phiras")));
    this->modelMap.emplace("deraumere", modelLoad(LoadModel("GRAPHICAL/../asset/quartz/quartz.obj"), 0, 0, this->getTexture("deraumere")));
    this->modelMap.emplace("linemate", modelLoad(LoadModel("GRAPHICAL/../asset/diamond/diamond.obj"), 0, 0, this->getTexture("linemate")));
    this->modelMap.emplace("mendiane", modelLoad(LoadModel("GRAPHICAL/../asset/magic/magic.obj"), 0, 0, this->getTexture("mendiane")));
    this->modelMap.emplace("thystame", modelLoad(LoadModel("GRAPHICAL/../asset/energy/energy.obj"), 0, 0, this->getTexture("thystame")));
}

void RayGraph::ModelC::initIaMod()
{
    // init level differents textures
    this->textureMap.emplace("level-1", LoadTexture("GRAPHICAL/asset/lava-monster/textures/level-1.png"));
    this->textureMap.emplace("level-2", LoadTexture("GRAPHICAL/asset/lava-monster/textures/level-2.png"));
    this->textureMap.emplace("level-3", LoadTexture("GRAPHICAL/asset/lava-monster/textures/level-3.png"));
    this->textureMap.emplace("level-4", LoadTexture("GRAPHICAL/asset/lava-monster/textures/level-4.png"));

    // init IA model
    this->modelMap.emplace("monster", modelLoad(LoadModel("GRAPHICAL/../asset/lava-monster/lavaWalk.iqm"), 0, 0, this->getTexture("level-1")));
}

void RayGraph::ModelC::initBgMod()
{
    this->modelMap.emplace(std::make_pair(std::string("bg"), modelLoad(LoadModel("GRAPHICAL/../asset/bg/bg.obj"), 0, 0, this->getTexture("floor"))));
}

void RayGraph::ModelC::initCaseMod()
{
    // init floor texture
    this->textureMap.emplace("floor", LoadTexture("GRAPHICAL/../asset/floor2/textures/floor.png"));

    // init map resource
    this->modelMap.emplace(std::make_pair(std::string("floor"), modelLoad(LoadModel("GRAPHICAL/../asset/floor2/floor.obj"), 0, 0, this->getTexture("floor"))));
    SetMaterialTexture(&this->getModelLoad("floor")._model.materials[0], MATERIAL_MAP_DIFFUSE, this->getTexture("floor"));
}

const Model &RayGraph::ModelC::getModel(const std::string &key)
{
    return this->modelMap.find(key)->second._model;
}

const RayGraph::ModelC::modelLoad &RayGraph::ModelC::getModelLoad(const std::string &key)
{
    return this->modelMap.find(key)->second;
}

void RayGraph::ModelC::initNewClient(int id, const std::string &key)
{
    Model mod = this->getModel(key);

    this->clientTab.emplace_back(Client(id, modelLoad(mod, 0, 0, getTexture("level-1"))));
}

Texture2D &RayGraph::ModelC::getTexture(const std::string &key)
{
    return this->textureMap.find(key)->second;
}

const RayGraph::ModelC::Client &RayGraph::ModelC::getClient(const int &id)
{
    for (auto &i : clientTab)
    {
        if (i._id == id)
            return i;
    }
}

void RayGraph::ModelC::DrawModelC(const std::string &key, Vector3 pos, float scale)
{
    Model mod = modelMap.find(key)->second._model;

    DrawModel(mod, pos, scale, WHITE);
}

RayGraph::ModelC::~ModelC()
{
}