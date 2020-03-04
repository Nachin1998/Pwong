#ifndef MAIN_MENU_MANAGER_H
#define MAIN_MENU_MANAGER_H

#include "raylib.h"

namespace MyGame {
namespace MainMenuManager {

	enum MainMenuScene {
		MainMenu,
		Controls,
		Options
	};

	extern MainMenuScene mainMenuScene;

	extern int subTitleFontSize;
	extern int textFontSize;
	extern int distanceBetweenButtons;
	extern Color titleTextColor;
	extern Color textColor;

	extern Color mouseOverButton;
	extern Color mouseAwayFromButton;

	void init();
	void update();
	void draw();
}
}

#endif
