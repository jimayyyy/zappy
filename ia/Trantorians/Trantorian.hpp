/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** Trantorian
*/

#ifndef TRANTORIAN_HPP_
#define TRANTORIAN_HPP_

#include <array>
#include "Tool.hpp"

typedef struct inventory_s {
    int food = 0;
    int linemate = 0;
    int deraumere = 0;
    int sibur = 0;
    int mendiane = 0;
    int phiras = 0;
    int thystame = 0;
} inventory_t;

typedef struct objectifs_s {
    int linemate = 0;
    int deraumere = 0;
    int sibur = 0;
    int mendiane = 0;
    int phiras = 0;
    int thystame = 0;
} objectifs_t;

typedef struct tile_s {
    int player = 0;
    int food = 0;
    int linemate = 0;
    int deraumere = 0;
    int sibur = 0;
    int mendiane = 0;
    int phiras = 0;
    int thystame = 0;
} tile_t;

typedef struct position_s {
    int x;
    int y;
} position_t;

class Trantorian {
    public:
        Trantorian(int x, int y, std::string team, int socket);
        void clearInventory(void);
        void setObj(void);
        ~Trantorian() = default;

        void moveForward(void);
        void turnRight(void);
        void turnLeft(void);
        void lookAround(void);
        void checkInventory(void);
        void broadcastText(void);
        void ConnectNbr(void);
        void forkPlayer(void);
        void ejectPlayer(void);
        void deathPlayer(void);
        void takeObject(void);
        void setObject(void);
        void startIncantation(void);
        void fillObj(int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
        void checkStones(void);
        bool checkIsObjectifComplete(void);
        void evolution(void);
        void TrantLoop(void);
        void definePriority(void);
        void behavior(void);
        bool getIsReproducing(void) {return isReproducing;};

        void commandLook(void);
        tile_t createTile(std::vector<std::string> vectile_temp);
        void commandInventory(void);
        bool checkTile(tile_t tile);
        void movement(void);
        bool checkAround(void);
        bool checkVecTile(void);
        void randomTurn(void);
        void checkTake(void);

    protected:
    private:
        inventory_t TrantInv;
        objectifs_t TrantObj;
        bool _isDead;
        std::string _team;
        int range;
        bool _lvlMax;
        int _level;
        position_t _pos;
        int _life;
        int _food;
        std::string _priorityStone = "";
        int _socket;
        int _angle = 0;
        bool isReproducing = false;
        std::vector<tile_t> vecLook;
        Tool tool;
};

#endif /* !TRANTORIAN_HPP_ */
