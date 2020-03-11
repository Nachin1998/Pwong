#include "options.h"

#include "managers\game_manager.h"
#include "managers\main_menu_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace Options {
using namespace GameManager;
using namespace MainMenuManager;

	static void muteButtonUpdate();
	static void darkModeUpdate();

	static UI::Button optionsTitle;
	static UI::Button backButton;

	static UI::TickBox muteTickBox;
	static UI::TickBox darkModeTickBox;

	static Color mouseOverButton = LIGHTGRAY;
	static Color mouseAwayFromButton = BLANK;

	bool darkMode = false;

	void init() {

		optionsTitle.rec.width = 380;
		optionsTitle.rec.height = 120;
		optionsTitle.rec.x = screenWidth / 2 - optionsTitle.rec.width / 2;
		optionsTitle.rec.y = (screenHeight / 2 - 270) - optionsTitle.rec.height / 2;
		optionsTitle.lineThickness = 5;
		optionsTitle.fontSize = 70;
		optionsTitle.edgesColor = LIGHTGRAY;
		optionsTitle.textColor = WHITE;
		optionsTitle.buttonColor = SKYBLUE;

		backButton.rec.width = 160;
		backButton.rec.height = 70;
		backButton.rec.x = screenWidth / 2 - backButton.rec.width / 2;
		backButton.rec.y = (screenHeight / 2 + 300) - backButton.rec.height / 2;
		backButton.lineThickness = 3;
		backButton.fontSize = 40;
		backButton.textColor = SKYBLUE;
		backButton.edgesColor = SKYBLUE;
		backButton.buttonColor = BLANK;

		UI::initTickBox(muteTickBox, 50.0f, screenWidth / 2 + 120, screenHeight / 2 - 25, 5, false, LIGHTGRAY);
		UI::initTickBox(darkModeTickBox, 50.0f, screenWidth / 2 + 120, screenHeight / 2 + 75, 5, false, LIGHTGRAY);
	}

	void update() {

		if (CheckCollisionPointRec(GetMousePosition(), backButton.rec))
		{
			backButton.buttonColor = mouseOverButton;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				mainMenuScene = menuSelection;
			}
		}
		else
		{
			backButton.buttonColor = mouseAwayFromButton;
		}

		muteButtonUpdate();
		darkModeUpdate();
	}

	void draw() {

		UI::createButton("OPTIONS", optionsTitle);

		UI::drawProText("Mute song", screenWidth / 2 - 100, screenHeight / 2 - 50, 50, SKYBLUE);
		UI::drawTickBox(muteTickBox);

		UI::drawProText("Dark mode", screenWidth / 2 - 100, screenHeight / 2 + 50, 50, SKYBLUE);
		UI::drawTickBox(darkModeTickBox);

		UI::createButton("Back", backButton);
	}

	void muteButtonUpdate() {

		if (muteTickBox.active)
		{
			muteTickBox.outerColor = GREEN;
			muteTickBox.innerColor = GREEN;
			PauseMusicStream(pongMusic);
		}
		else
		{
			ResumeMusicStream(pongMusic);
		}

		UI::tickBoxCollision(muteTickBox);
	}

	void darkModeUpdate() {

		if (darkModeTickBox.active)
		{
			darkModeTickBox.outerColor = GREEN;
			darkModeTickBox.innerColor = GREEN;
			darkMode = true;
		}
		else
		{
			darkMode = false;
		}

		UI::tickBoxCollision(darkModeTickBox);

		if (darkMode)
		{
			backColor = BLACK;
		}
		else
		{
			backColor = WHITE;
		}
	}
}
}