#include "game_over.h"

#include <iostream>

#include "managers\game_manager.h"
#include "managers\main_menu_manager.h"
#include "scenes\player_customization.h"
#include "scenes\gameplay.h"
#include "player\player.h"
#include "utility\UI.h"

namespace MyGame {
namespace GameOver {
using namespace GameManager;

	static const int maxButtons = 3;

	static int buttonXdistance = 400;
	static float pointSize = 200.0f;
	static float scoreDistanceFromX = 120.0f;

	static Color textColor = SKYBLUE;

	static UI::Button gameOverButton[maxButtons];

	void init() {

		for (int i = 0; i < maxButtons; i++)
		{
			gameOverButton[i].rec.width = 280;
			gameOverButton[i].rec.height = 90;
			gameOverButton[i].rec.x = screenWidth / 2 - buttonXdistance + (buttonXdistance * i) - gameOverButton[i].rec.width / 2;
			gameOverButton[i].rec.y = screenHeight / 2 + 280 - gameOverButton[i].rec.height / 2;
			gameOverButton[i].fontSize = 40;
			gameOverButton[i].lineThickness = 3;
			gameOverButton[i].edgesColor = SKYBLUE;
			gameOverButton[i].textColor = SKYBLUE;
			gameOverButton[i].buttonColor = BLANK;
		}
	}

	void update() {

		for (int i = 0; i < maxButtons; i++) 
		{
			if (CheckCollisionPointRec(GetMousePosition(), gameOverButton[i].rec))
			{
				gameOverButton[i].buttonColor = LIGHTGRAY;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					switch (i)
					{
					case 0:
						Gameplay::init();
						actualScene = Game;
						break;

					case 1:
						Gameplay::init();
						PlayerCustomization::init();
						MainMenuManager::mainMenuScene = MainMenuManager::menuSelection;
						actualScene = MainMenu;
						break;

					case 2:
						Gameplay::init();
						PlayerCustomization::init();
						MainMenuManager::mainMenuScene = MainMenuManager::Credits;
						actualScene = MainMenu;
						break;

					default:
						std::cout<<"There was an error in the Game Over button selection."<<std::endl;
						break;
					}
				}
			}
			else
			{
				gameOverButton[i].buttonColor = BLANK;
			}
		}
	}

	void draw() {

		if (Player::player1.score == Gameplay::maxScore)
		{
			UI::drawProText("Player 1 won!", screenWidth / 2, screenHeight / 2 - 300, 80, textColor);
		}
		else if (Player::player2.score == Gameplay::maxScore)
		{
			UI::drawProText("Player 2 won!", screenWidth / 2, screenHeight / 2 - 300, 80, textColor);
		}

		DrawText(FormatText("%i", Player::player1.score), screenWidth / 2 - MeasureText("0", 200) / 2 - scoreDistanceFromX, screenHeight / 2 - 100, pointSize, textColor);
		UI::drawProText("|", screenWidth / 2, screenHeight / 2 - 120, 250, textColor);
		DrawText(FormatText("%i", Player::player2.score), screenWidth / 2 - MeasureText("0", 200) / 2 + scoreDistanceFromX, screenHeight / 2 - 100, pointSize, textColor);

		UI::drawButton("Play Again", gameOverButton[0]);
		UI::drawButton("Main Menu", gameOverButton[1]);
		UI::drawButton("Credits", gameOverButton[2]);
	}
}
}