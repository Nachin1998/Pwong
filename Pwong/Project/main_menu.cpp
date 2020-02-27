#include "main_menu.h"

#include <iostream>

#include "game_manager.h"
#include "UI.h"

namespace MyGame {
namespace MainMenu {
using namespace GameManager;
using namespace UI;

	static void initControls();
	static void updateControls();
	static void drawControls();
	
	static Button mainTitle;
	static Button menuButtons[maxButtons];
	static Button controlsTitle;
	static Button controlsButton;

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
		mainTitle.linesColor = LIGHTGRAY;
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
			menuButtons[i].linesColor = SKYBLUE;
			menuButtons[i].textColor = SKYBLUE;
			menuButtons[i].buttonColor = BLANK;
		}

		initControls();
	}

	void update() {

		if (!controlsActive) {
			for (int i = 0; i < maxButtons; i++) {
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
							std::exit(0);
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
			createButton("PWONG", mainTitle, mainTitle.linesColor, mainTitle.textColor, mainTitle.fontSize);

			createButton("Start", menuButtons[0], menuButtons[0].linesColor, menuButtons[0].textColor, menuButtons[0].fontSize);
			createButton("Controls", menuButtons[1], menuButtons[1].linesColor, menuButtons[1].textColor, menuButtons[1].fontSize);
			createButton("Credits", menuButtons[2], menuButtons[2].linesColor, menuButtons[2].textColor, menuButtons[2].fontSize);
			createButton("Exit", menuButtons[3], menuButtons[3].linesColor, menuButtons[3].textColor, menuButtons[3].fontSize);
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
		controlsTitle.linesColor = LIGHTGRAY;
		controlsTitle.textColor = WHITE;
		controlsTitle.buttonColor = SKYBLUE;

		controlsButton.rec.width = 150;
		controlsButton.rec.height = 70;
		controlsButton.rec.x = screenWidth / 2 - controlsButton.rec.width / 2;
		controlsButton.rec.y = (screenHeight / 2 + 300) - controlsButton.rec.height / 2;
		controlsButton.lineThickness = 5;
		controlsButton.fontSize = 30;
		controlsButton.linesColor = SKYBLUE;
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

		createButton("Controls", controlsTitle, controlsTitle.linesColor, controlsTitle.textColor, controlsTitle.fontSize);

		drawProText("Movement", screenWidth / 2, screenHeight / 2 - 200, subTitleFontSize, titleTextColor);
		drawProText("Player 1 - W/S", screenWidth / 2, screenHeight / 2 - 120, textFontSize, textColor);
		drawProText("Player 2 - UP/DOWN", screenWidth / 2, screenHeight / 2 - 80, textFontSize, textColor);

		drawProText("Rules", screenWidth / 2, screenHeight / 2, subTitleFontSize, titleTextColor);
		drawProText("Control your paddle by moving it vertically", screenWidth / 2, screenHeight / 2 + 70, textFontSize, textColor);
		drawProText("and use it to hit the ball back and forth.", screenWidth / 2, screenHeight / 2 + 100, textFontSize, textColor);
		drawProText("Score 5 points before the opponent..", screenWidth / 2, screenHeight / 2 + 130, textFontSize, textColor);
		drawProText("Points are earned when one fails to return the ball.", screenWidth / 2, screenHeight / 2 + 160, textFontSize, textColor);

		createButton("Back", controlsButton, controlsButton.linesColor, controlsButton.textColor, controlsButton.fontSize);
	}
}
}