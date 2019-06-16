//
// Created by camix on 15/06/19.
//

#include "Receptor.h"

Receptor::Receptor(std::string &path, Window &window, const std::string& name, int w, int h) :
        StaticObject(path, window, name, w, h) {}

bool Receptor::hasGravity() {
    return false;
}

Receptor::~Receptor() = default;


void Receptor::setName(std::pair<int, int>& position, std::string& enteredName) {
    for(auto it = names.begin(); it != names.end(); it++) {
        if (it->second == enteredName && it->first != position) {
            throw SetNameException(this->name);
        }
    }
    std::cerr << "Soy un receptor ";
    names[position] = enteredName;
    std::cerr << "y mi nombre es " << names[position] << std::endl;
}

bool Receptor::doesThisNameExist(std::string &string) {
    auto it = this->names.begin();

    std::cerr << "iterando por nombres: " << std::endl;
    for(; it != this->names.end(); it++) {

        std::cerr << it->second << std::endl;
        if (it->second == string) {
            std::cerr << "este es igual" << std::endl;
            return true;
        }
    }
    return false;
}

void Receptor::removeFrom(int x, int y, std::map<std::pair<int, int>, std::string> &tiles,
                        std::unordered_map<std::string, Object *> &textures) {
    names.erase(std::make_pair(x, y));
    Object::removeFrom(x, y, tiles, textures);
}

void Receptor::addTo(int x, int y, std::map<std::pair<int, int>,
        std::string> &tiles, std::unordered_map<std::string,
        Object *> &textures, std::string sentinel) {
    Object::addTo(x, y, tiles, textures, RECEPTOR_SENTINEL);
}
