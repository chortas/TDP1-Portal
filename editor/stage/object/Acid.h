//
// Created by camix on 10/06/19.
//

#ifndef PORTAL_ACID_H
#define PORTAL_ACID_H


#include "AnimatedObject.h"

class Acid : public AnimatedObject {
public:
    Acid(std::string &path, Window &window,
            int totalFrames, int id, int w, int h);
    ~Acid();
    void draw(SDL_Rect* rect) override;

    std::pair<float, float> matrixPosToCenterOfMass(
            const std::pair<int, int> &position) override;

    std::pair<int, int> centerOfMassToMatrixPos(
            const std::pair<float, float> &pair) override;
};


#endif //PORTAL_ACID_H
