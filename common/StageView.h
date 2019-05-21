//
// Created by ndv on 5/13/19.
//

#ifndef PORTAL_STAGEVIEW_H
#define PORTAL_STAGEVIEW_H
#include <unordered_map>
#include <exception>
#include <map>
#include <yaml-cpp/yaml.h>
#include "Window.h"
#include "Sprite.h"
#include <utility>
#include <string>

#define TEXTURES_STATICOBJETS_KEY "StaticObjects"
#define EXTRA_TILES 1


class StageViewAddTileException : public std::exception{
    virtual const char* what() const throw () {
        std::string message = "Couldn't add the tile, that's not a valid element!\n";
        return message.c_str();
    }
};

class StageView {
    int matrixToPixelFactor;
    std::unordered_map<std::string, Sprite*> textures;
    std::map<std::pair<int, int>, std::string> tiles;

public:
    StageView(Window& window, YAML::Node& texturesInfo, int factor);
    ~StageView();
    void addTile(int x, int y, std::string& tileName);
    void draw(Window& window, SDL_Rect* camera);
};


#endif //PORTAL_STAGEVIEW_H