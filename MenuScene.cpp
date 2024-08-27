#include "MenuScene.h"
#include "GameScene.h"
#include "SceneManager.h"
#include <iostream>
#include <string>
#include <fstream>

void MenuScene::handleInput(sf::RenderWindow& window) {

    pos = Mouse::getPosition(window);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == Event::MouseButtonPressed)
        {
            //std::cout << pos.x << "  " << pos.y;
            if ((pos.x > 348 && pos.x < 452) && (pos.y > 330 && pos.y < 363))
            {
                b1 = 1;
                NameInput = "";
            }
            if ((pos.x > 210 && pos.x < 590) && (pos.y > 450 && pos.y < 519))
            {
                b2 = 1;
            }
            if ((pos.x > 195 && pos.x < 673) && (pos.y > 550 && pos.y < 619))
            {
                b3 = 1;
            }

        }

        if (b1 == 1) {
            if (event.type == sf::Event::TextEntered) {
                // Handle regular character input
                if (event.text.unicode >= 32 && event.text.unicode <= 126) { // Printable characters
                    NameInput += static_cast<char>(event.text.unicode);
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Backspace && !NameInput.empty()) {
                    // Handle backspace
                    NameInput.pop_back();
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    // Handle Enter key (e.g., to confirm the input)
                    b1 = 0;
                    writeToFile("name.txt", NameInput);
                }
            }
            // Update the text displayed
            Name.setString(NameInput);
            
        }
    }
}

void MenuScene::Update(sf::RenderWindow& window) {

   
    if (b2 == 1) {
        SceneManager::getInstance().pushScene(std::make_unique<GameScene>());
    }
    if (b3 == 1) {

    }

    window.clear();
    window.draw(backgroundSprite);
    window.draw(titleText);
    window.draw(playerText);
    window.draw(Name);
    window.draw(playSameDeviceButtonSprite);
    window.draw(playDifferentDeviceButtonSprite);
    window.draw(setNameButtonSprite);
    window.display();
}


MenuScene::MenuScene() {

    if (isFileEmpty("name.txt")) {
        NameInput = "Player 1";
    }
    else {
        NameInput = readFromFile("name.txt");
    }

    // Load background image
    if (!backgroundTexture.loadFromFile("images/background.jpg")) {
        std::cerr << "Error loading background image!" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Load play on same device button image
    if (!playSameDeviceButtonTexture.loadFromFile("images/button_play-on-same-device.png")) {
        std::cerr << "Error loading play on same device button image!" << std::endl;
    }
    playSameDeviceButtonSprite.setTexture(playSameDeviceButtonTexture);
    playSameDeviceButtonSprite.setPosition(210, 450);

    // Load play on different device button image
    if (!playDifferentDeviceButtonTexture.loadFromFile("images/button_play-on-different-device.png")) {
        std::cerr << "Error loading play on different device button image!" << std::endl;
    }
    playDifferentDeviceButtonSprite.setTexture(playDifferentDeviceButtonTexture);
    playDifferentDeviceButtonSprite.setPosition(195, 550);

    // Load set name button image
    if (!setNameButtonTexture.loadFromFile("images/button_set-name.png")) {
        std::cerr << "Error loading set name button image!" << std::endl;
    }
    setNameButtonSprite.setTexture(setNameButtonTexture);
    setNameButtonSprite.setPosition(348, 330);

    // Load font and set title text
    if (!font.loadFromFile("images/Arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    titleText.setFont(font);
    titleText.setString("Chess");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(300, 50);  // Centered at the top

    playerText.setFont(font);
    playerText.setCharacterSize(40);
    playerText.setFillColor(sf::Color::Black);
    playerText.setPosition(250, 200);
    playerText.setString("Player: ");

    Name.setFont(font);
    Name.setCharacterSize(40);
    Name.setFillColor(sf::Color::Black);
    Name.setPosition(390, 200);
    update_Name();


}

void MenuScene::update_Name() {
    Name.setString(NameInput);
}

void MenuScene::writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename); // Open the file for writing

    if (outFile.is_open()) {
        outFile << content; // Write the content to the file
        outFile.close(); // Close the file
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

std::string MenuScene::readFromFile(const std::string& filename) {
    std::ifstream inFile(filename); // Open the file for reading
    std::string content;

    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) { // Read line by line
            content += line + "\n"; // Add each line to the content string
        }
        inFile.close(); // Close the file
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }

    return content;
}

bool MenuScene::isFileEmpty(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate); // Open file in binary mode and move to the end
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return false; // or true, depending on how you want to handle errors
    }

    std::streampos fileSize = file.tellg(); // Get the current position, which is the file size
    return fileSize == 0; // If the size is 0, the file is empty
}
