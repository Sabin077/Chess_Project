#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <stack>
#include <memory>
#include "Scene.h"

class SceneManager {
private:
    std::stack<std::unique_ptr<Scene>> scenes;

    SceneManager() = default;  // Private constructor

public:
    // Deleted copy constructor and assignment operator
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

    // Static method to access the single instance of the class
    static SceneManager& getInstance() {
        static SceneManager instance;
        return instance;
    }

    void pushScene(std::unique_ptr<Scene> scene);
    void popScene();
    void changeScene(std::unique_ptr<Scene> scene);

    Scene* getCurrentScene();

    void handleInput(sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
};

#endif // SCENEMANAGER_H

