#include "credits.h"

#include "managers\game_manager.h"
#include "managers\main_menu_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace Credits {
using namespace GameManager;
using namespace MainMenuManager;

	static UI::Button creditsTitle;
	static UI::Button backToMainMenu;

	static int subTitleFontSize = 40;
	static int textFontSize = 30;
	static Color titleTextColor = SKYBLUE;
	static Color textColor = LIGHTGRAY;

	static Color mouseOverButton = LIGHTGRAY;
	static Color mouseAwayFromButton = BLANK;

	void init() {

		creditsTitle.rec.width = 380;
		creditsTitle.rec.height = 120;
		creditsTitle.rec.x = screenWidth / 2 - creditsTitle.rec.width / 2;
		creditsTitle.rec.y = (screenHeight / 2 - 300) - creditsTitle.rec.height / 2;
		creditsTitle.lineThickness = 5;
		creditsTitle.fontSize = 70;
		creditsTitle.edgesColor = LIGHTGRAY;
		creditsTitle.textColor = WHITE;
		creditsTitle.buttonColor = SKYBLUE;

		backToMainMenu.rec.width = 350;
		backToMainMenu.rec.height = 70;
		backToMainMenu.rec.x = screenWidth / 2 - backToMainMenu.rec.width / 2;
		backToMainMenu.rec.y = (screenHeight / 2 + 320) - backToMainMenu.rec.height / 2;
		backToMainMenu.lineThickness = 3;
		backToMainMenu.fontSize = 30;
		backToMainMenu.textColor = SKYBLUE;
		backToMainMenu.edgesColor = SKYBLUE;
		backToMainMenu.buttonColor = BLANK;
	}

	void update() {

		if (CheckCollisionPointRec(GetMousePosition(), backToMainMenu.rec))
		{
			backToMainMenu.buttonColor = mouseOverButton;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				mainMenuScene = menuSelection;
			}
		}
		else
		{
			backToMainMenu.buttonColor = mouseAwayFromButton;
		}
	}

	void draw() {

		UI::drawButton("Credits", creditsTitle);
		UI::drawProText("Pwong", screenWidth / 2, screenHeight / 2 - 230, 60, titleTextColor);

		UI::drawProText("Lead Progammer", screenWidth / 2, screenHeight / 2 - 120, subTitleFontSize, titleTextColor);
		UI::drawProText("Ignacio Fernández Lemos", screenWidth / 2, screenHeight / 2 - 75, textFontSize, textColor);

		UI::drawProText("Music & SFX", screenWidth / 2, screenHeight / 2, subTitleFontSize, titleTextColor);
		UI::drawProText("Song: `At Night` - Diys", screenWidth / 2, screenHeight / 2 + 45, textFontSize, textColor);
		UI::drawProText("SFX: Ignacio Fernández Lemos", screenWidth / 2, screenHeight / 2 + 85, textFontSize, textColor);

		UI::drawProText("Programs used", screenWidth / 2, screenHeight / 2 + 150, subTitleFontSize, titleTextColor);
		UI::drawProText("Visual Studio C++", screenWidth / 2, screenHeight / 2 + 195, textFontSize, textColor);
		UI::drawProText("Raylib Library", screenWidth / 2, screenHeight / 2 + 235, textFontSize, textColor);

		UI::drawButton("Back to main menu", backToMainMenu);
	}
}
}