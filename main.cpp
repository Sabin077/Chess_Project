#include <sfml/Graphics.hpp>
#include <iostream>
//#include "all_header.h"
//#include "textures.h"
#include "On_Button_Click.h"
#include "Update_board.h"
#include "SceneManager.h"
#include "Scene.h"
#include "MenuScene.h"

using namespace sf;


int main()
{
	//object of other classes

	On_Button_Click be;
	Update_Board ub;

		RenderWindow window(VideoMode(800, 800), "Sabin");
		window.setKeyRepeatEnabled(false);


		SceneManager::getInstance().pushScene(std::make_unique<MenuScene>());

		while (window.isOpen()) {

			SceneManager::getInstance().handleInput(window);
			SceneManager::getInstance().Update(window);
		}

	return 0;
}

