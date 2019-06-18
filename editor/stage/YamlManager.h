//
// Created by camix on 17/06/19.
//

#ifndef PORTAL_YAMLMANAGER_H
#define PORTAL_YAMLMANAGER_H

#include <yaml-cpp/node/node.h>
#include <unordered_map>
#include <map>
#include "object/Object.h"
#include "LogicGates.h"

class YamlManager {
private:
    std::unordered_map<int, Object *> &textures;
    std::map<std::pair<int, int>, int> &tiles;
    LogicGates &logicGates;

public:
    YamlManager(std::unordered_map<int, Object *> &textures,
                    std::map<std::pair<int, int>, int> &tiles,
                    LogicGates &logicGates);

    void write();

    void read(Window &window, YAML::Node &texturesInfo);

    void getWidthAndHeightInMeters(int *width, int *eight);
};


#endif //PORTAL_YAMLMANAGER_H
