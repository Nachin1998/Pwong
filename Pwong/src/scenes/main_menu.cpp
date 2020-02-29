#include "main_menu.h"

#include <iostream>

#include "game_manager\game_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace MainMenu {
	using namespace GameManager;

	static void initControls();
	static void updateControls();
	static void drawControls();

	static UI::Button mainTitle;
	static UI::Button menuButtons[maxButtons];
	static UI::Button controlsTitle;
	static UI::Button controlsButton;

	static int subTitleFontSize = 60;
	static int textFontSize = 30;
	static int distanceBetweenButtons = 95;
	static Color titleTextColor = SKYBLUE;
	static Color textColor = LIGHTGRAY;

	static Color mouseOverButton = LIGHTGRAY;
	static Color mouseAwayFromButton = BLANK;

	bool controlsActive;

	void init() {

		controlsActive = false;

		mainTitle.rec.width = 420;
		mainTitle.rec.height = 150;
		mainTitle.rec.x = screenWidth / 2 - mainTitle.rec.width / 2;
		mainTitle.rec.y = (screenHeight / 2 - 250) - mainTitle.rec.height / 2;
		mainTitle.lineThickness = 5;
		mainTitle.fontSize = 100;
		mainTitle.edgesColor = LIGHTGRAY;
		mainTitle.textColor = WHITE;
		mainTitle.buttonColor = titleTextColor;

		for (int i = 0; i < maxButtons; i++)
		{
			menuButtons[i].rec.width = 250;
			menuButtons[i].rec.height = 75;
			menuButtons[i].rec.x = screenWidth / 2 - menuButtons[i].rec.width / 2;
			menuButtons[i].rec.y = (screenHeight / 2 - 50 + (distanceBetweenButtons * i)) - menuButtons[i].rec.height / 2;
			menuButtons[i].lineThickness = 3;
			menuButtons[i].fontSize = 40;
			menuButtons[i].edgesColor = SKYBLUE;
			menuButtons[i].textColor = SKYBLUE;
			menuButtons[i].buttonColor = BLANK;
		}

		initControls();
	}

	void update() {

		if (!controlsActive) {
			for (int i = 0; i < maxButtons; i++)
			{
				if (CheckCollisionPointRec(GetMousePosition(), menuButtons[i].rec))
				{
					menuButtons[i].buttonColor = mouseOverButton;

					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						switch (i)
						{
						case 0:
							actualScene = Game;
							break;

						case 1:
							controlsActive = true;
							break;

						case 2:
							actualScene = Credits;
							break;

						case 3:
							closeGame = true;
							break;

						default:
							std::cout << "There was an error in the button selection at the Main Menu" << std::endl;
							break;
						}
					}
				}
				else
				{
					menuButtons[i].buttonColor = mouseAwayFromButton;
				}
			}
		}
		else
		{
			updateControls();
		}

	}

	void draw() {

		if (!controlsActive)
		{
			createButton("PWONG", mainTitle);

			createButton("Start", menuButtons[0]);
			createButton("Controls", menuButtons[1]);
			createButton("Credits", menuButtons[2]);
			createButton("Exit", menuButtons[3]);
		}
		else
		{
			drawControls();
		}
	}

	void initControls() {

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

	void updateControls() {

		if (CheckCollisionPointRec(GetMousePosition(), controlsButton.rec))
		{
			controlsButton.buttonColor = mouseOverButton;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				controlsActive = false;
			}
		}
		else
		{
			controlsButton.buttonColor = mouseAwayFromButton;
		}
	}

	void drawControls() {

		createButton("Controls", controlsTitle);

		UI::drawProText("Movement", screenWidth / 2, screenHeight / 2 - 200, subTitleFontSize, titleTextColor);
		UI::drawProText("Player 1 - W/S", screenWidth / 2, screenHeight / 2 - 120, textFontSize, textColor);
		UI::drawProText("Player 2 - UP/DOWN", screenWidth / 2, screenHeight / 2 - 80, textFontSize, textColor);

		UI::drawProText("Rules", screenWidth / 2, screenHeight / 2, subTitleFontSize, titleTextColor);
		UI::drawProText("Control your paddle by moving it vertically", screenWidth / 2, screenHeight / 2 + 70, textFontSize, textColor);
		UI::drawProText("and use it to hit the ball back and forth.", screenWidth / 2, screenHeight / 2 + 100, textFontSize, textColor);
		UI::drawProText("Score 5 points before the opponent.", screenWidth / 2, screenHeight / 2 + 130, textFontSize, textColor);
		UI::drawProText("Points are earned when one fails to return the ball.", screenWidth / 2, screenHeight / 2 + 160, textFontSize, textColor);

		UI::createButton("Back", controlsButton);
	}
}
}