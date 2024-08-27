#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "all_header.h"
#include "textures.h"

using namespace sf;

class On_Button_Click {
public:

	Vector2i pos;
	void button_actions(sf::RenderWindow& window);
};

