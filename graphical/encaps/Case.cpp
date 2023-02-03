/*
** EPITECH PROJECT, 2022
** GRAPHICAL
** File description:
** Case
*/

#include "Raylib.hpp"

RayGraph::Case::Case(std::string &rss)
{
    this->model.initCaseMod();
}

RayGraph::ModelC &RayGraph::Case::getModel()
{
    return this->model;
}

void RayGraph::Case::drawCase(int x, int y)
{
    this->model.DrawModelC("floor", (Vector3){(float)y - 5, 0, (float)x - 5}, 0.009);
}

RayGraph::Case::~Case()
{

}
