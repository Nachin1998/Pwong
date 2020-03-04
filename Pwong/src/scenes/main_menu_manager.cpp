#include "main_menu_manager.h"

#include "scenes\main_menu.h"
#include "scenes\controls.h"

namespace MyGame {
namespace MainMenuManager {

	MainMenuScene mainMenuScene = MainMenu;

	void init() {

		MainMenu::init();
		Controls::init();
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

		case Credits:
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

		case Credits:
			break;

		default:
			break;
		}
	}
}
}