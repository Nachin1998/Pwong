#include "main_menu.h"

#include <iostream>

#include "managers\main_menu_manager.h"
#include "managers\game_manager.h"
#include "scenes\player_customization.h"
#include "utility\UI.h"

namespace MyGame {
namespace MainMenu {
using namespace GameManager;
using namespace MainMenuManager;

	static const int maxButtons = 5;

	static UI::Button mainTitle;
	static UI::Button menuButtons[maxButtons];

	static int subTitleFontSize = 60;
	static int textFontSize = 30;
	static int distanceBetweenButtons = 95;
	static Color titleTextColor = SKYBLUE;
	static Color textColor = LIGHTGRAY;

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

		PlayerCustomization::init();
	}

	void update() {

		for (int i = 0; i < maxButtons; i++)
		{
			UI::updateButtonColor(menuButtons[i]);
			if (CheckCollisionPointRec(GetMousePosition(), menuButtons[i].rec))
			{
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					switch (i)
					{
					case 0:
						mainMenuScene = playerCustomization;
						break;

					case 1:
						mainMenuScene = Controls;
						break;

					case 2:
						mainMenuScene = Options;
						break;

					case 3:
						mainMenuScene = MainMenuManager::Credits;
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
		}
	}

	void draw() {

		drawButton("PWONG", mainTitle);

		drawButton("Start", menuButtons[0]);
		drawButton("Controls", menuButtons[1]);
		drawButton("Options", menuButtons[2]);
		drawButton("Credits", menuButtons[3]);
		drawButton("Exit", menuButtons[4]);
	}
}
}