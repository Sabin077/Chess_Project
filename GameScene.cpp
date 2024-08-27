#include "GameScene.h"
#include "MenuScene.h"
#include "On_Button_Click.h"
#include "Update_Board.h"
#include <iostream>

void GameScene::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "Pausing game, back to menu!" << std::endl;
        SceneManager::getInstance().changeScene(std::make_unique<MenuScene>());
    }

    On_Button_Click be;
    be.button_actions(window);

}


void GameScene::Update(sf::RenderWindow& window) {
    window.clear();
    // Draw game objects here
    Update_Board ub;
    ub.update_board(window);

    window.display();
}
