#include "main_menu_manager.h"

#include <iostream>

#include "managers\game_manager.h"
#include "scenes\main_menu.h"
#include "scenes\controls.h"
#include "scenes\options.h"
#include "scenes\credits.h"

namespace MyGame {
namespace MainMenuManager {

	MainMenuScene mainMenuScene = MainMenu;

	void init() {

		MainMenu::init();
		Controls::init();
		Options::init();
		Credits::init();
	}

	void update() {

		switch (mainMenuScene)
		{
		case MainMenu:
			MainMenu::update();
			break;

		case Controls:
			Controls::update();
			break;

		case Options:
			Options::update();
			break;

		case Credits:
			Credits::update();
			break;

		default:
			std::cout << "There was an error in the main menu manager Update section" << std::endl;
			break;
		}
	}

	void draw() {

		switch (mainMenuScene)
		{
		case MainMenu:
			MainMenu::draw();
			break;

		case Controls:
			Controls::draw();
			break;

		case Options:
			Options::draw();
			break;

		case Credits:
			Credits::draw();
			break;

		default:
			std::cout << "There was an error in the main menu manager Drawing section" << std::endl;
			break;
		}
	}
}
}