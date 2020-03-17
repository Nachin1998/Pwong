#ifndef MAIN_MENU_MANAGER_H
#define MAIN_MENU_MANAGER_H

#include "raylib.h"

namespace MyGame {
namespace MainMenuManager {

	enum MainMenuScene {
		menuSelection,
		playerCustomization,
		Controls,
		Options,
		Credits
	};

	extern MainMenuScene mainMenuScene;

	void init();
	void update();
	void draw();
}
}

#endif
