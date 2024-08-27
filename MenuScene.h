#ifndef MENUSCENE_H
#define MENUSCENE_H
#include <sfml/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "SceneManager.h"
using namespace sf;

class MenuScene : public Scene {
public:
    Event event;
    Vector2i pos;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture playSameDeviceButtonTexture;
    sf::Sprite playSameDeviceButtonSprite;

    sf::Texture playDifferentDeviceButtonTexture;
    sf::Sprite playDifferentDeviceButtonSprite;

    sf::Texture setNameButtonTexture;
    sf::Sprite setNameButtonSprite;

    sf::Font font;
    sf::Text titleText;
    sf::Text playerText;
    sf::Text Name;

    std::string NameInput = "";
    int b1, b2, b3;
    void update_Name();

    MenuScene();
    void handleInput(sf::RenderWindow& window) override;
    void Update(sf::RenderWindow& window) override;
    void writeToFile(const std::string& filename, const std::string& content);
    std::string readFromFile(const std::string& filename);
    bool isFileEmpty(const std::string& filename);

};

#endif // MENUSCENE_H
