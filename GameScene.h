#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class GameScene : public Scene {
public:
    void handleInput(sf::RenderWindow& window) override;
    void Update(sf::RenderWindow& window) override;
};

#endif // GAMESCENE_H
