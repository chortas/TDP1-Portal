//
// Created by camix on 11/06/19.
//

#include "DiagonalBlockRightUp.h"

DiagonalBlockRightUp::DiagonalBlockRightUp(std::string &path, Window &window,
                                           int id, int w, int h) :
        DiagonalBlockUp(path, window, id, w, h) {}

DiagonalBlockRightUp::~DiagonalBlockRightUp() = default;

std::pair<float, float> DiagonalBlockRightUp::matrixPosToCenterOfMass(
        const std::pair<int, int> &position) {
    float ax = position.first;
    float ay = position.second ;//+1;

    float bx = ax + w;
    float by = ay;

    float cx = ax;
    float cy = ay - h;
    return this->triangleMatrixPosToCenterOfMass(position, std::make_pair(bx, by),
                                                 std::make_pair(cx, cy));
}

std::pair<int, int> DiagonalBlockRightUp::centerOfMassToMatrixPos(
        const std::pair<float, float> &pair) {
    return std::pair<int, int>();
}
