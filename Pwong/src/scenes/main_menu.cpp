#include "main_menu.h"

#include <iostream>

#include "managers\main_menu_manager.h"
#include "managers\game_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace MainMenu {
using namespace GameManager;

	static UI::Button mainTitle;
	static UI::Button menuButtons[maxButtons];

	static int subTitleFontSize = 60;
	static int textFontSize = 30;
	static int distanceBetweenButtons = 95;
	static Color titleTextColor = SKYBLUE;
	static Color textColor = LIGHTGRAY;

	static Color mouseOverButton = LIGHTGRAY;
	static Color mouseAwayFromButton = BLANK;

	void init() {

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
			menuButtons[i].rec.y = (screenHeight / 2 - 80 + (distanceBetweenButtons * i)) - menuButtons[i].rec.height / 2;
			menuButtons[i].lineThickness = 3;
			menuButtons[i].fontSize = 40;
			menuButtons[i].edgesColor = SKYBLUE;
			menuButtons[i].textColor = SKYBLUE;
			menuButtons[i].buttonColor = BLANK;
		}
	}

	void update() {

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
						MainMenuManager::mainMenuScene = MainMenuManager::Controls;
						break;

					case 2:
						MainMenuManager::mainMenuScene = MainMenuManager::Options;
						break;

					case 3:
						//Options
						break;

					case 4:
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

	void draw() {

		createButton("PWONG", mainTitle);

		createButton("Start", menuButtons[0]);
		createButton("Controls", menuButtons[1]);
		createButton("Options", menuButtons[2]);
		createButton("Credits", menuButtons[3]);
		createButton("Exit", menuButtons[4]);
	}
}
}