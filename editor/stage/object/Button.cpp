//
// Created by camix on 22/05/19.
//

#include <iostream>
#include "Button.h"

Button::Button(std::string &path, Window &window, int id, int w, int h) :
    StaticObject(path, window, id, w, h) {}

void Button::setName(std::pair<int, int>& position, std::string& enteredName) {
    for(auto it = names.begin(); it != names.end(); it++) {
        if (it->second == enteredName && it->first != position) {
            throw SetNameException();
        }
    }
    names[position] = enteredName;
}

bool Button::doesThisNameExist(std::string &string) {
    auto it = this->names.begin();
    for(; it != this->names.end(); it++) {
       if (it->second == string) {
           return true;
       }
    }
    return false;
}

void Button::removeFrom(int x, int y, std::map<std::pair<int, int>, int> &tiles,
                        std::unordered_map<int, Object *> &textures) {
    auto it = names.find(std::make_pair(x, y));
    if (it != names.end()) {
        lastName = it->second;
        names.erase(it);
    }
    Object::removeFrom(x, y, tiles, textures);
}

Button::~Button() = default;

std::pair<float, float> Button::matrixPosToCenterOfMass(const std::pair<int, int> &position) {
    return this->rectangleMatrixPosToCenterOfMass(position, BUTTON_WIDTH, BUTTON_HEIGHT);
}

std::map<std::pair<int, int>, std::string> &Button::getNames() {
    return names;
}

void Button::addTo(int x, int y, std::map<std::pair<int, int>, int> &tiles, std::unordered_map<int, Object *> &textures,
                 bool needGravitySentinel) {
    names[std::make_pair(x, y)] = lastName;
    Object::addTo(x, y, tiles, textures);
}

std::pair<int, int> Button::centerOfMassToMatrixPos(const std::pair<float, float> &pair) {
    return this->rectangleCenterOfMassToMatrixPos(pair, BUTTON_WIDTH, BUTTON_HEIGHT);
}

bool Button::hasName() {
    return true;
}
