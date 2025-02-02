//
// Created by cecix on 22/06/19.
//

#include "Drawer.h"

Drawer::Drawer(Protocol &clientProtocol, Socket &clientSocket, Window& window,
        int mtpFactor):
    clientProtocol(clientProtocol), clientSocket(clientSocket),
    newWindow(window), mtpFactor(mtpFactor) {
}

void Drawer::draw(std::string& idChell) {
    const int screenWidth = 1050;
    const int screenHeight = 700;
    YAML::Node textures = YAML::LoadFile(CLIENT_TEXTURE_CONFIG_FILE);
    SoundCodeQueue soundQueue;
    AudioSystem audioSystem(soundQueue);
    std::string title = "Portal";
    
    std::string bgPath = "resources/editor-stage-bg.png";
    Sprite background(bgPath, newWindow);

    //Here we'll receive the metadata
    std::string jsonMetadata = clientProtocol.receiveMessage();
    nlohmann::json metadata = nlohmann::json::parse(jsonMetadata);

    float stageWidth = metadata["stage"]["width"].get<float>();
    float stageHeight = metadata["stage"]["height"].get<float>();

    int levelWidth = stageWidth * mtpFactor;
    int levelHeight = stageHeight * mtpFactor;

    Camera camera(screenWidth, screenHeight, levelWidth, levelHeight);

    UserEventQueue userEventQueue;
    UserEventHandler userEventHandler(camera, userEventQueue,
                                      idChell, levelHeight,
                                      soundQueue,
                                      newWindow,
                                      1.0f / mtpFactor);
    StageStatusQueue stageStatusQueue;

    EventSender eventSender(clientSocket, userEventQueue);
    StageStatusReceiver stageStatusReceiver(clientSocket, stageStatusQueue);

    // Here we'll receive two jsons with the data of the map to be played.
    // First one is for static objects without state.
    std::string jsonStaticObjects = clientProtocol.receiveMessage();

    // Second one is for objects with state.
    std::string jsonDynamicObjects = clientProtocol.receiveMessage();

    nlohmann::json staticObjects = nlohmann::json::parse(jsonStaticObjects);
    nlohmann::json dynamicObjects = nlohmann::json::parse(jsonDynamicObjects);

    StageView stageView(newWindow, textures, mtpFactor, staticObjects, stageHeight);
    ViewManager viewManager(newWindow, levelHeight,
                            mtpFactor, idChell, dynamicObjects, soundQueue, metadata);
    audioSystem.playMusic(BG_SONG_GAME);
    userEventHandler.start();
    eventSender.start();
    stageStatusReceiver.start();

    nlohmann::json stageUpdateRequest = "{}"_json;
    stageUpdateRequest["Game"] = {
            {"state", PLAYING}, {"x", 0}, {"y", 0}
    };
    const SDL_Rect& cameraRect = camera.getCameraRectangle();

    bool quit = false;
    while (!quit) {
        if (!stageStatusQueue.empty()) {
            std::string stageStatusString = stageStatusQueue.pop();
            stageUpdateRequest = nlohmann::json::parse(stageStatusString);
        }
        if (userEventHandler.isDead()) {
            quit = true;
        }
        GameState gameState = stageUpdateRequest["Game"]["state"].get<GameState>();
        if (gameState == LOST) {
            OutputText output(newWindow,"  ", GREEN_MOLD);
            std::string s = "All players have left the game. You lose!";
            output.writeTheScreen(s);
            quit = true;
        }
        if (gameState == WON) {

            OutputText output(newWindow,"  ", GREEN_MOLD);
            std::string s = "Your team has won! Congratulations!";
            output.writeTheScreen(s);
            quit = true;
        }
        if (quit) break;
        // Time to draw!
        newWindow.clear();
        SDL_Rect* bgRect = nullptr;
        background.draw(bgRect);
        stageView.draw(cameraRect);
        viewManager.showAndUpdateViews(stageUpdateRequest, camera);
        newWindow.render();
        audioSystem.playSoundEffects();

    }
    UserEvent eventSenderSuicidePill = UserEvent(idChell, USER_QUIT_CODE, 0, 0);
    userEventQueue.push(eventSenderSuicidePill);

    clientSocket.shutdownAndClose();
    userEventHandler.stop();
    userEventHandler.join();
    eventSender.stop();
    eventSender.join();
    stageStatusReceiver.stop();
    stageStatusReceiver.join();
}
