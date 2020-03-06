#include "options.h"

#include "managers\game_manager.h"
#include "managers\main_menu_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace Options {
using namespace GameManager;

	static void muteButtonInit();
	static void muteButtonUpdate();
	static void darkModeInit();
	static void darkModeUpdate();

	struct tickButton {
		Rectangle outerRec;
		Rectangle innerRec;
		float linesThick;
		bool active;
		Color outerColor;
		Color innerColor;
	};

	static UI::Button optionsTitle;
	static UI::Button backButton;

	static tickButton muteButton;

	Color mouseOverButton = LIGHTGRAY;
	Color mouseAwayFromButton = BLANK;

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

		backButton.rec.width = 130;
		backButton.rec.height = 70;
		backButton.rec.x = screenWidth / 2 - backButton.rec.width / 2;
		backButton.rec.y = (screenHeight / 2 + 250) - backButton.rec.height / 2;
		backButton.lineThickness = 3;
		backButton.fontSize = 30;
		backButton.textColor = SKYBLUE;
		backButton.edgesColor = SKYBLUE;
		backButton.buttonColor = BLANK;

		muteButtonInit();
	}

	void update() {

		if (CheckCollisionPointRec(GetMousePosition(), backButton.rec))
		{
			backButton.buttonColor = mouseOverButton;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				MainMenuManager::mainMenuScene = MainMenuManager::MainMenu;
			}
		}
		else
		{
			backButton.buttonColor = mouseAwayFromButton;
		}

		muteButtonUpdate();
	}

	void draw() {

		UI::createButton("OPTIONS", optionsTitle);

		UI::drawProText("Mute song", screenWidth / 2 - 100, screenHeight / 2 - 50, 50, SKYBLUE);
		DrawRectangleLinesEx(muteButton.outerRec, muteButton.linesThick, muteButton.outerColor);
		DrawRectangleRec(muteButton.innerRec, muteButton.innerColor);

		UI::createButton("Back", backButton);
	}

	void muteButtonInit() {

		muteButton.outerRec.width = 50;
		muteButton.outerRec.height = 50;
		muteButton.outerRec.x = screenWidth / 2 + 100 - muteButton.outerRec.width / 2;
		muteButton.outerRec.y = screenHeight / 2 - 25 - muteButton.outerRec.height / 2;
		muteButton.innerRec.width = muteButton.outerRec.width - 20;
		muteButton.innerRec.height = muteButton.outerRec.height - 20;
		muteButton.innerRec.x = screenWidth / 2 + 100 - muteButton.innerRec.width / 2;
		muteButton.innerRec.y = screenHeight / 2 - 25 - muteButton.innerRec.height / 2;
		muteButton.linesThick = 5;
		muteButton.active = false;
		muteButton.outerColor = LIGHTGRAY;
		muteButton.innerColor = BLANK;
	}

	void muteButtonUpdate() {

		if (muteButton.active)
		{
			muteButton.outerColor = GREEN;
			muteButton.innerColor = GREEN;
			PauseMusicStream(pongMusic);
		}
		else
		{
			ResumeMusicStream(pongMusic);
		}

		if (CheckCollisionPointRec(GetMousePosition(), muteButton.outerRec))
		{
			if (muteButton.active)
			{
				muteButton.outerColor = DARKGREEN;
				muteButton.innerColor = DARKGREEN;
			}
			else
			{
				muteButton.outerColor = mouseOverButton;
				muteButton.innerColor = mouseOverButton;
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (muteButton.active)
				{
					muteButton.active = false;
				}
				else
				{
					muteButton.active = true;
				}
			}
		}
		else
		{
			if (muteButton.active)
			{
				muteButton.outerColor = GREEN;
				muteButton.innerColor = GREEN;
			}
			else
			{
				muteButton.outerColor = LIGHTGRAY;
				muteButton.innerColor = BLANK;
			}

		}
	}
}
}