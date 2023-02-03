/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

#include <vector>
#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <map>
#include <array>
#include <sstream>
#include "raylib.h"
#include "Parser.hpp"

namespace RayGraph
{

    class Text
    {

    public:
        Text();
        ~Text();
        void drawText(const std::string text, unsigned int x, unsigned int y, unsigned int size, Color color);
        void drawFontText(const std::string text, unsigned int x, unsigned int y, unsigned int size, Color color);

    protected:
    private:
        Font font;
    };

    class Shape
    {
    public:
        Shape();
        ~Shape();

        void drawCube(Vector3 pos, float widht, float height, float lenght, Color color);
        void drawTextureCube(float x, float y, float z, Vector3 dim, const std::string &key);
        void drawSphere(Vector3 pos, float radius, Color color);
        Texture2D getTexture(const std::string &key);
        void drawBackground(const std::string &key);

    private:
        std::vector<std::pair<std::string, Texture2D>> textureLib;

    protected:
    };

    class Game
    {

    public:
        enum GameScreen
        {
            MENU,
            SETTINGS,
            GAMEPLAY
        };

        Game(int screenWidth, int screenHeight, int fps);
        ~Game();

        void displayWindow(void);
        void displayMenu(void);
        void displayTitle(void);
        void displayHTP(void);
        void displayGame(RayGraph::Shape shape);

    private:
        int _fps;
        GameScreen _currentScreen;
        std::vector<std::string> _playerName;

    protected:
    };

    class ModelC
    {
    public:
        struct modelLoad
        {
            modelLoad();
            modelLoad(Model model, unsigned int animsCount, int animFrameCounter, Texture2D texure) : _model(model),
                                                                                                      _animFrameCounter(animFrameCounter), _animsCount(animsCount), _texture(texure) {}

            Model _model;
            unsigned int _animsCount;
            int _animFrameCounter;
            Texture2D _texture;
        };
        struct Client
        {
            Client(int id, modelLoad model) : _id(id), _model(model) {}

            int _id;
            modelLoad _model;
        };

        ModelC();
        ~ModelC();
        Texture2D &getTexture(const std::string &key);
        void DrawModelC(const std::string &key, Vector3 pos, float scale);
        void initCaseMod();
        void initIaMod();
        void initRssMod();
        void initBgMod();
        void initNewClient(int id, const std::string &key);
        const modelLoad &getModelLoad(const std::string &key);
        const Client &getClient(const int &id);
        const Model &getModel(const std::string &key);
        RayGraph::ModelC::modelLoad &initNeWFloor();

    protected:
        std::vector<modelLoad> modelLoadTab;
        std::vector<Client> clientTab;
        std::map<std::string, modelLoad> modelMap;
        std::map<std::string, Texture2D> textureMap;
    };

    class Case
    {
    public:
        Case(std::string &rss);
        ~Case();
        RayGraph::ModelC &getModel();
        void drawCase(int x, int y);

    private:
    protected:
        RayGraph::ModelC model;
        std::pair<int, int> _coord;
        std::array<int, 6> _rss;
    };

    class Map
    {
    public:
        Map(int width, int height, std::string buf);
        ~Map();
        std::vector<Case> &getMap();
        void fillMap();
        const RayGraph::Case &getCase(int index);

    private:
        std::vector<Case> caseMap;
        int _width;
        int _height;
        Parser pars;
        std::vector<std::string> map;
    };

    class Camera
    {
    public:
        Camera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
        ~Camera();

    private:
        Camera3D cam;

    protected:
    };

    class Musics
    {
    public:
        void init_BombEffect(void);
        void init_MusicMenu(void);
        void init_PowerUps(void);
        void init_WinLoose(void);
        void Init_ButtonEffect(void);
        void playsound(Sound music, std::string actual_music);
        void stop(Sound music);
        void resume(Sound music);
        void pause(Sound music);
        void SetVolume(Sound music, float volume);
        void SetGeneralVolume(float volume);
        float GetGeneralVolume(void);
        float GetEffectVolume(void);
        Sound game_music;
        Sound menu_music;
        Sound button_effect;
        Sound effect_place_bomb;
        Sound effect_explode_bomb;
        Sound powerup_1;
        Sound powerup_2;
        Sound powerup_3;
        Sound powerup_4;
        Sound loose;
        Sound win;
        std::string _actualMusic;
    };
};

#endif /* !RAYLIB_HPP_ */
