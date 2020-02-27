#include "game_over.h"

#include "game_manager.h"
#include "UI.h"

namespace MyGame {
namespace GameOver {
using namespace UI;
using namespace GameManager;

	static const int maxButtons = 3;

	static Button gameOverButton[maxButtons];

	void init() {

		for (int i = 0; i < maxButtons; i++)
		{
			gameOverButton[i].rec.width = 280;
			gameOverButton[i].rec.height = 90;
			gameOverButton[i].rec.x = screenWidth / 2 - 400 + (400 * i) - gameOverButton[i].rec.width / 2;
			gameOverButton[i].rec.y = screenHeight / 2 + 280 - gameOverButton[i].rec.height / 2;
			gameOverButton[i].fontSize = 40;
			gameOverButton[i].lineThickness = 3;
			gameOverButton[i].edgesColor = SKYBLUE;
			gameOverButton[i].textColor = SKYBLUE;
			gameOverButton[i].buttonColor = BLANK;
		}
	}

	void update() {

		for (int i = 0; i < maxButtons; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), gameOverButton[i].rec))
			{
				gameOverButton[i].buttonColor = LIGHTGRAY;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					switch (i)
					{
					case 0:
						actualScene = Game;
						break;

					case 1:
						actualScene = MainMenu;
						break;

					case 2:
						actualScene = Credits;
						break;

					default:
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

		createButton("Play Again", gameOverButton[0]);
		createButton("Main Menu", gameOverButton[1]);
		createButton("Credits", gameOverButton[2]);
	}
}
}