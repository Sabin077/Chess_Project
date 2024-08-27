#include "SceneManager.h"

void SceneManager::pushScene(std::unique_ptr<Scene> scene) {
    scenes.push(std::move(scene));
}

void SceneManager::popScene() {
    if (!scenes.empty()) {
        scenes.pop();
    }
}

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    if (!scenes.empty()) {
        scenes.pop();
    }
    scenes.push(std::move(scene));
}

Scene* SceneManager::getCurrentScene() {
    if (!scenes.empty()) {
        return scenes.top().get();
    }
    return nullptr;
}

void SceneManager::handleInput(sf::RenderWindow& window) {
    if (Scene* scene = getCurrentScene()) {
        scene->handleInput(window);
    }
}


void SceneManager::Update(sf::RenderWindow& window) {
    if (Scene* scene = getCurrentScene()) {
        scene->Update(window);
    }
}
