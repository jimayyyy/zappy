/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** Trantorian
*/

#include <vector>
#include <string>
#include <array>
#include <unistd.h>
#include "Trantorian.hpp"

Trantorian::Trantorian(int x, int y, std::string team, int socket) : _level(1), _pos{x, y}, _life(10), _team(team), _socket(socket), _isDead(false)
{
}

void Trantorian::fillObj(int l, int d, int s, int m, int p, int t)
{
    TrantObj.linemate = l;
    TrantObj.deraumere = d;
    TrantObj.sibur = s;
    TrantObj.mendiane = m;
    TrantObj.phiras = p;
    TrantObj.thystame = t;
}

bool Trantorian::checkIsObjectifComplete(void)
{
    int valid = 0;

    if (TrantInv.deraumere >= TrantObj.deraumere)
        valid += 1;
    if (TrantInv.linemate >= TrantObj.linemate)
        valid += 1;
    if (TrantInv.mendiane >= TrantObj.mendiane)
        valid += 1;
    if (TrantInv.phiras >= TrantObj.phiras)
        valid += 1;
    if (TrantInv.sibur >= TrantObj.sibur)
        valid += 1;
    if (TrantInv.thystame >= TrantObj.thystame)
        valid += 1;
    // printf("J'ai %i linemate !\n", TrantInv.linemate);
    //  printf("VALEUR DE VALIDE : %i\n", valid);
    if (valid == 6)
        return true;
    return false;
}

bool Trantorian::checkTile(tile_t tile)
{
    if (tile.deraumere > 0 && TrantInv.deraumere < TrantObj.deraumere)
        return true;
    if (tile.linemate > 0 && TrantInv.linemate < TrantObj.linemate)
        return true;
    if (tile.mendiane > 0 && TrantInv.mendiane < TrantObj.mendiane)
        return true;
    if (tile.phiras > 0 && TrantInv.phiras < TrantObj.phiras)
        return true;
    if (tile.sibur > 0 && TrantInv.sibur < TrantObj.sibur)
        return true;
    if (tile.thystame > 0 && TrantInv.thystame < TrantObj.thystame)
        return true;
    return false;
}

void Trantorian::movement(void)
{
    std::string response;
    for (int i = 0; i != _level; i += 1)
    {
        tool.send_command("Forward", _socket);
        response = tool.get_response(_socket);
        //usleep(70000);
        // printf("REPONSE FORWARD: %s\n", response.c_str());
    }
}

bool Trantorian::checkAround(void)
{
    std::string response;
    for (int i = 0; i != 3; i += 1)
    {
        tool.send_command("Left", _socket);
        response = tool.get_response(_socket);
        //usleep(70000);
        // printf("REPONSE LEFT: %s\n", response.c_str());
        if (checkVecTile() == true)
            return true;
    }
    return false;
}

bool Trantorian::checkVecTile(void)
{
    commandLook();
    for (int i = 0; i != vecLook.size(); i += 1)
    {
        if (checkTile(vecLook[i]) == true)
        {
            return true;
        }
    }
    return false;
}

void Trantorian::randomTurn(void)
{
    std::string response;
    int value = rand() % 4;
    for (int i = 0; i != value; i += 1)
    {
        tool.send_command("Left", _socket);
        response = tool.get_response(_socket);
        //usleep(70000);
        // printf("REPONSE left: %s\n", response.c_str());
    }
}

void Trantorian::checkTake(void)
{
    std::string response;
    if (checkTile(vecLook[0]) == true)
    {
        printf("Je prends un objet!\n");
        if (vecLook[0].food > 0 && TrantInv.food < 20)
        {
            // printf("Je prends a manger\n");
            tool.send_command("Take food", _socket);
            response = tool.get_response(_socket);
        }
        if (vecLook[0].deraumere > 0 && TrantInv.deraumere < TrantObj.deraumere)
            tool.send_command("Take deraumere", _socket);
        if (vecLook[0].linemate > 0 && TrantInv.linemate < TrantObj.linemate)
        {
            printf("Je prends du linemate\n");
            tool.send_command("Take linemate", _socket);
        }
        if (vecLook[0].mendiane > 0 && TrantInv.mendiane < TrantObj.mendiane)
            tool.send_command("Take mendiane", _socket);
        if (vecLook[0].phiras > 0 && TrantInv.phiras < TrantObj.phiras)
            tool.send_command("Take phiras", _socket);
        if (vecLook[0].sibur > 0 && TrantInv.sibur < TrantObj.sibur)
            tool.send_command("Take sibur", _socket);
        if (vecLook[0].thystame > 0 && TrantInv.thystame < TrantObj.thystame)
            tool.send_command("Take thystame", _socket);
        response = tool.get_response(_socket);
        //usleep(70000);
        // printf("REPONSE TAKE: %s\n", response.c_str());
    }
}

void Trantorian::behavior(void)
{
    std::string response;

    setObj();
    if (checkIsObjectifComplete() == false)
    {
        commandInventory();
        if (checkVecTile() == true)
        {
            printf("Il y a un objet dans cette direction !\n");
            movement();
        }
        if (checkVecTile() == false)
        {
            printf("il n'y a rien par la !\n");
            if (checkAround() == true)
            {
                printf("Il y a un truc bien autour de moi\n");
                movement();
            }
            if (checkAround() == false)
            {
                printf("Je change de direction\n");
                randomTurn();
                movement();
            }
        }
        checkTake();
    }
    if (checkIsObjectifComplete() == true)
    {
        printf("J'évolue !\n");
        tool.send_command("Incantation", _socket);
        response = tool.get_response(_socket);
        //usleep(3000000);
        printf("REPONSE EVOLUTION: %s\n", response.c_str());
        _level += 1;
        commandInventory();
    }
    // avance
    // regarde
    // check inv
    // check si il need
    // si oui
    // il avance
    // si nn
    // tourne sur lui meme
    // rand angle
    // avance
}

void Trantorian::clearInventory(void)
{
    TrantInv.linemate -= TrantObj.linemate;
    TrantInv.deraumere -= TrantObj.deraumere;
    TrantInv.sibur -= TrantObj.sibur;
    TrantInv.mendiane -= TrantObj.mendiane;
    TrantInv.phiras -= TrantObj.phiras;
    TrantInv.thystame -= TrantObj.thystame;
}

void Trantorian::setObj(void)
{
    switch (_level)
    {
    case (1):
        fillObj(1, 0, 0, 0, 0, 0);
        break;
    case (2):
        fillObj(1, 1, 1, 0, 0, 0);
        break;
    case (3):
        fillObj(2, 0, 1, 0, 2, 0);
        break;
    // case (4):
    //     fillObj(1, 1, 2, 0, 1, 0);
    //     evolution();
    //     break;
    // case (5):
    //     fillObj(1, 2, 1, 3, 0, 0);
    //     evolution();
    //     break;
    // case (6):
    //     fillObj(1, 2, 3, 0, 1, 0);
    //     evolution();
    //     break;
    // case (7):
    //     fillObj(2, 2, 2, 2, 2, 1);
    //     evolution();
    //     break;
    // case (8):
    //     _lvlMax = true;
    //     break;
    default:
        break;
    }
}

tile_t Trantorian::createTile(std::vector<std::string> vectile_temp)
{
    tile_t tile_temp;
    for (int i = 0; i != vectile_temp.size(); i += 1)
    {
        if (vectile_temp[i].compare("deraumere") == 0)
            tile_temp.deraumere += 1;
        if (vectile_temp[i].compare("food") == 0)
            tile_temp.food += 1;
        if (vectile_temp[i].compare("linemate") == 0)
            tile_temp.linemate += 1;
        if (vectile_temp[i].compare("mendiane") == 0)
            tile_temp.mendiane += 1;
        if (vectile_temp[i].compare("phiras") == 0)
            tile_temp.phiras += 1;
        if (vectile_temp[i].compare("player") == 0)
            tile_temp.player += 1;
        if (vectile_temp[i].compare("sibur") == 0)
            tile_temp.sibur += 1;
        if (vectile_temp[i].compare("thystame") == 0)
            tile_temp.thystame += 1;
    }
    return tile_temp;
}

void Trantorian::commandLook(void)
{
    tool.send_command("Look\n", _socket);
    std::string response = tool.get_response(_socket);
    //usleep(70000);
    // printf("REPONSE LOOK: %s\n", response.c_str());
    //  printf("réponse officilelle : %s\n", response.c_str());
    vecLook.clear();
    std::vector<std::string> vecTile = tool.parseResponse(response, ',');
    std::vector<std::string> vectile_temp;
    for (int i = 0; i != vecTile.size(); i += 1)
    {
        // printf("tile number %i: %s\n", i, vecTile[i].c_str());
        vectile_temp = tool.parseResponse(vecTile[i], ' ');
        vecLook.emplace_back(createTile(vectile_temp));
    }
    // for (int i = 0; i != vecLook.size(); i += 1) {
    //     printf("tile number %i got: %i deraumere, %i food, %i linemate, %i mendiane, %i phiras, %i player, %i sibur, %i thystame\n", i, vecLook[i].deraumere, vecLook[i].food, vecLook[i].linemate, vecLook[i].mendiane, vecLook[i].phiras, vecLook[i].player, vecLook[i].sibur, vecLook[i].thystame);
    // }
}

void Trantorian::commandInventory(void)
{
    tool.send_command("Inventory\n", _socket);
    std::string response = tool.get_response(_socket);
    //usleep(10000);
    printf("REPONSE INVENTORY: %s\n", response.c_str());
    std::vector<std::string> parseSpace = tool.parseResponse(response, ' ');
    // for (int i = 0; i != parseSpace.size(); i += 1) {
    //     printf("parseSpace[%i] = %s\n", i, parseSpace[i].c_str());
    // }
    if (parseSpace.size() == 16)
    {
        TrantInv.food = atoi(parseSpace[2].c_str());
        TrantInv.linemate = atoi(parseSpace[4].c_str());
        TrantInv.deraumere = atoi(parseSpace[6].c_str());
        TrantInv.sibur = atoi(parseSpace[8].c_str());
        TrantInv.mendiane = atoi(parseSpace[10].c_str());
        TrantInv.phiras = atoi(parseSpace[12].c_str());
        TrantInv.thystame = atoi(parseSpace[14].c_str());
    }
    // printf("REPONSE INVENTORY: food = %i, linemate = %i, deraumere = %i, sibur = %i, mendiane = %i, phiras = %i, thystame = %i\n", TrantInv.food, TrantInv.linemate, TrantInv.deraumere, TrantInv.sibur, TrantInv.mendiane, TrantInv.phiras, TrantInv.thystame);
}