//
// Created by cecix on 10/06/19.
//

#include "EnergyTransmitterRight.h"

EnergyTransmitterRight::EnergyTransmitterRight(b2Body* body):
        EnergyTransmitter(body)  {
}

Coordinate* EnergyTransmitterRight::throwEnergyBall() {
    float offset = gameConfiguration.offsetEnergyTransmitter;
    float x_pos = getHorizontalPosition() + offset;
    float y_pos = getVerticalPosition();
    if (isTimeToThrow()) {
        return new Coordinate(x_pos, y_pos);
    }
}