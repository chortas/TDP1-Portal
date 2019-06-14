//
// Created by ndv on 6/12/19.
//

#ifndef PORTAL_USEREVENTHANDLER_H
#define PORTAL_USEREVENTHANDLER_H

#include "../common/constants.h"
#include "Camera.h"
#include "../common/UserEventQueue.h"
#include "SoundCodeQueue.h"

#define MTP_FACTOR_INV 0.01f

class UserEventHandler {
    const Camera& camera;
    UserEventQueue& userEventQueue;
    const std::string& userId;
    int levelHeight;
    SoundCodeQueue& soundCodeQueue;

public:
    UserEventHandler(const Camera& camera,
            UserEventQueue& userEventQueue,
            const std::string& userId,
            int levelHeight,
            SoundCodeQueue& soundCodeQueue);
    ~UserEventHandler();
    void run(SDL_Event& event);
};


#endif //PORTAL_USEREVENTHANDLER_H