#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "all_header.h"
#include "textures.h"
#include "On_Button_Click.h"

class Update_Board {
public:

	Event event;
	Vector2i pos;
	sf::Texture whitewin_tex;
	sf::Sprite whitewin_sprite;

	sf::Texture blackwin_tex;
	sf::Sprite blackwin_sprite;

	sf::Texture draw_tex;
	sf::Sprite draw_sprite;

	void update_board(sf::RenderWindow& window);

};
