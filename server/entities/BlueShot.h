//
// Created by cecix on 2/06/19.
//

#ifndef PORTAL_BLUESHOT_H
#define PORTAL_BLUESHOT_H

#include <Box2D/Dynamics/b2Body.h>
#include "Chell.h"
#include "Shot.h"

class BlueShot: public Shot {
public:
    BlueShot(b2Body *body, Chell* chell, Coordinate* target);

    /* Handles collision against other objects in the world */
    void handleCollision(Entity* entity) override;
};

#endif //PORTAL_BLUESHOT_H
