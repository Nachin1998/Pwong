#include "main_menu_manager.h"

#include "managers\game_manager.h"
#include "scenes\main_menu.h"
#include "scenes\controls.h"
#include "scenes\options.h"

namespace MyGame {
namespace MainMenuManager {

	MainMenuScene mainMenuScene = Options;

	void init() {

		MainMenu::init();
		Controls::init();
		Options::init();
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

		default:
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

		default:
			break;
		}
	}
}
}