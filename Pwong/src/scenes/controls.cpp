#include "controls.h"

#include "managers\main_menu_manager.h"
#include "managers\game_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace Controls {
using namespace GameManager;

	static UI::Button controlsTitle;
	static UI::Button controlsButton;

	static int subTitleFontSize = 60;
	static int textFontSize = 30;
	static int distanceBetweenButtons = 95;
	static Color titleTextColor = SKYBLUE;
	static Color textColor = LIGHTGRAY;

	static Color mouseOverButton = LIGHTGRAY;
	static Color mouseAwayFromButton = BLANK;

	void init() {

		controlsTitle.rec.width = 380;
		controlsTitle.rec.height = 120;
		controlsTitle.rec.x = screenWidth / 2 - controlsTitle.rec.width / 2;
		controlsTitle.rec.y = (screenHeight / 2 - 300) - controlsTitle.rec.height / 2;
		controlsTitle.lineThickness = 5;
		controlsTitle.fontSize = 70;
		controlsTitle.edgesColor = LIGHTGRAY;
		controlsTitle.textColor = WHITE;
		controlsTitle.buttonColor = SKYBLUE;

		controlsButton.rec.width = 150;
		controlsButton.rec.height = 70;
		controlsButton.rec.x = screenWidth / 2 - controlsButton.rec.width / 2;
		controlsButton.rec.y = (screenHeight / 2 + 300) - controlsButton.rec.height / 2;
		controlsButton.lineThickness = 5;
		controlsButton.fontSize = 30;
		controlsButton.edgesColor = SKYBLUE;
		controlsButton.textColor = SKYBLUE;
		controlsButton.buttonColor = BLANK;
	}

	void update() {

		if (CheckCollisionPointRec(GetMousePosition(), controlsButton.rec))
		{
			controlsButton.buttonColor = mouseOverButton;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				MainMenuManager::mainMenuScene = MainMenuManager::MainMenu;
			}
		}
		else
		{
			controlsButton.buttonColor = mouseAwayFromButton;
		}
	}

	void draw() {

		createButton("Controls", controlsTitle);

		UI::drawProText("Player 1 movement- W/S", screenWidth / 2, screenHeight / 2 - 200, textFontSize, textColor);
		UI::drawProText("Player 2 movement- UP/DOWN", screenWidth / 2, screenHeight / 2 - 150, textFontSize, textColor);
		UI::drawProText("Press ´P´ to pause", screenWidth / 2, screenHeight / 2 - 100, textFontSize, textColor);

		UI::drawProText("Rules", screenWidth / 2, screenHeight / 2, subTitleFontSize, titleTextColor);
		UI::drawProText("Control your paddle by moving it vertically", screenWidth / 2, screenHeight / 2 + 70, textFontSize, textColor);
		UI::drawProText("and use it to hit the ball back and forth.", screenWidth / 2, screenHeight / 2 + 100, textFontSize, textColor);
		UI::drawProText("Score 5 points before the opponent.", screenWidth / 2, screenHeight / 2 + 130, textFontSize, textColor);
		UI::drawProText("Points are earned when one fails to return the ball.", screenWidth / 2, screenHeight / 2 + 160, textFontSize, textColor);

		UI::createButton("Back", controlsButton);
	}
}
}