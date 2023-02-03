/*
** EPITECH PROJECT, 2021
** B-YEP-410-PAR-4-1-zappy-jimy.xu
** File description:
** Shape.cpp
*/

#include "Raylib.hpp"

RayGraph::Shape::Shape()
{

}

void RayGraph::Shape::drawBackground(const std::string &key)
{
    DrawTexture(this->getTexture(key), 0, 0, WHITE);
}

Texture2D RayGraph::Shape::getTexture(const std::string &key)
{
    for (auto &i : this->textureLib) {
        if (i.first == key)
            return i.second;
    }
    throw std::runtime_error("Texture not found");
}

void RayGraph::Shape::drawTextureCube(float x, float y, float z, Vector3 dim, const std::string &key)
{
    Vector3 pos = {x, y, z};
    Texture2D texture = this->getTexture(key);

    DrawCubeTexture(texture, pos, dim.x, dim.y, dim.z, WHITE);
    DrawCubeWires(pos, dim.x, dim.y, dim.z, BLACK);
}

void RayGraph::Shape::drawCube(Vector3 pos, float width, float height, float lenght, Color color)
{
    DrawCube(pos, width, height, lenght, color);
}

void RayGraph::Shape::drawSphere(Vector3 pos, float radius, Color color)
{
    DrawSphere(pos, radius, color);
}

RayGraph::Shape::~Shape()
{
}