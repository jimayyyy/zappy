/*
** EPITECH PROJECT, 2022
** GRAPHICAL
** File description:
** Map
*/

#include "Raylib.hpp"

RayGraph::Map::Map(int width, int height, std::string buf) :
    _width(width), _height(height), map(this->pars.splitString(buf, '\n'))
{
}

void RayGraph::Map::fillMap()
{
    // std::cout << "height = " << this->_height << std::endl;
    for (int i = 0; i < this->_height; ++i) {
        this->caseMap.emplace_back(RayGraph::Case(this->map[i]));
        std::cout << "size = " << this->caseMap.size() << std::endl;
    }
}

std::vector<RayGraph::Case> &RayGraph::Map::getMap()
{
    return this->caseMap;
}

const RayGraph::Case &RayGraph::Map::getCase(int index)
{
    return this->map[index];
}

RayGraph::Map::~Map()
{

}
