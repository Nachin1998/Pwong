#include "player_customization.h"

#include "managers\game_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace PlayerCustomization {
using namespace GameManager;

	static void initColors();
	static void initPlayerColorChoice();
	static void initButtons();
	static void updateButtons();

	static const int maxButtons = 4;
	static const int maxColors = 23;
	static int colorCounter = 0;
	static float distanceFromX = 150;
	static float distanceFromY = 120;

	static Color colorSelection[maxColors];

	Color player1Color = BLANK;
	Color player2Color = BLANK;

	Rectangle player1ColorChoice;
	Rectangle player2ColorChoice;

	UI::Button changePlayerColor[maxButtons];

	UI::Button startGame;

	void init() {

		initColors();
		initPlayerColorChoice();
		initButtons();
	}

	void update() {

		for (int i = colorCounter; i < maxColors; i++)
		{
			switch (i)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			case 22:
				player1Color = colorSelection[colorCounter];

			default:
				break;
			}
		}

		updateButtons();
	}

	void draw() {

		UI::drawProText("Choose your paddle´s color", screenWidth / 2, screenHeight / 2 - 350, 50, LIGHTGRAY);

		DrawRectangleRec(player1ColorChoice, player1Color);
		DrawRectangleLinesEx(player1ColorChoice, 5, LIGHTGRAY);

		DrawRectangleRec(player2ColorChoice, player2Color);
		DrawRectangleLinesEx(player2ColorChoice, 5, LIGHTGRAY);

		UI::drawButton("-", changePlayerColor[0]);
		UI::drawButton("+", changePlayerColor[1]);
		UI::drawButton("-", changePlayerColor[2]);
		UI::drawButton("+", changePlayerColor[3]);

		UI::drawProText(FormatText("%i", colorCounter), screenWidth / 2, screenHeight / 2, 10, BLACK);

		UI::drawButton("Start game", startGame);
	}

	void initColors() {

		colorSelection[0] = LIGHTGRAY;
		colorSelection[1] = GRAY;
		colorSelection[2] = DARKGRAY;
		colorSelection[3] = YELLOW;
		colorSelection[4] = GOLD;
		colorSelection[5] = ORANGE;
		colorSelection[6] = PINK;
		colorSelection[7] = RED;
		colorSelection[8] = MAROON;
		colorSelection[9] = GREEN;
		colorSelection[10] = LIME;
		colorSelection[11] = DARKGREEN;
		colorSelection[12] = SKYBLUE;
		colorSelection[13] = BLUE;
		colorSelection[14] = DARKBLUE;
		colorSelection[15] = PURPLE;
		colorSelection[16] = VIOLET;
		colorSelection[17] = DARKPURPLE;
		colorSelection[18] = BEIGE;
		colorSelection[19] = BROWN;
		colorSelection[20] = DARKBROWN;
		colorSelection[21] = WHITE;
		colorSelection[22] = MAGENTA;
	}

	void initPlayerColorChoice() {

		player1ColorChoice.width = 230;
		player1ColorChoice.height = 50;
		player1ColorChoice.x = screenWidth / 2 - player1ColorChoice.width / 2;
		player1ColorChoice.y = screenHeight / 2 - distanceFromY - player1ColorChoice.height / 2;

		player2ColorChoice.width = 230;
		player2ColorChoice.height = 50;
		player2ColorChoice.x = screenWidth / 2 - player2ColorChoice.width / 2;
		player2ColorChoice.y = screenHeight / 2 + distanceFromY - player2ColorChoice.height / 2;
	}

	void initButtons() {

		startGame.rec.width = 300;
		startGame.rec.height = 60;
		startGame.rec.x = screenWidth / 2 - startGame.rec.width / 2;
		startGame.rec.y = screenHeight / 2 + 320 - startGame.rec.height / 2;
		startGame.lineThickness = 3;
		startGame.fontSize = 40;
		startGame.edgesColor = SKYBLUE;
		startGame.textColor = SKYBLUE;
		startGame.buttonColor = BLANK;

		for (int i = 0; i < 4; i++)
		{
			changePlayerColor[i].rec.width = 30;
			changePlayerColor[i].rec.height = 30;
			changePlayerColor[i].lineThickness = 2;
			changePlayerColor[i].fontSize = 40;
			changePlayerColor[i].edgesColor = SKYBLUE;
			changePlayerColor[i].textColor = SKYBLUE;
			changePlayerColor[i].buttonColor = BLANK;
		}

		changePlayerColor[0].rec.x = screenWidth / 2 - distanceFromX - changePlayerColor[0].rec.width / 2;
		changePlayerColor[0].rec.y = screenHeight / 2 - distanceFromY - changePlayerColor[0].rec.height / 2;

		changePlayerColor[1].rec.x = screenWidth / 2 + distanceFromX - changePlayerColor[1].rec.width / 2;
		changePlayerColor[1].rec.y = screenHeight / 2 - distanceFromY - changePlayerColor[1].rec.height / 2;

		changePlayerColor[2].rec.x = screenWidth / 2 - distanceFromX - changePlayerColor[2].rec.width / 2;
		changePlayerColor[2].rec.y = screenHeight / 2 + distanceFromY - changePlayerColor[2].rec.height / 2;

		changePlayerColor[3].rec.x = screenWidth / 2 + distanceFromX - changePlayerColor[3].rec.width / 2;
		changePlayerColor[3].rec.y = screenHeight / 2 + distanceFromY - changePlayerColor[3].rec.height / 2;
	}

	void updateButtons() {

		for (int i = 0; i < maxButtons; i++)
		{
			if (CheckCollisionPointRec(GetMousePosition(), changePlayerColor[i].rec))
			{
				changePlayerColor[i].buttonColor = LIGHTGRAY;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
				{
					switch (i)
					{
					case 0:
					case 2:
						if (colorCounter == 0)
						{
							colorCounter = maxColors;
						}
						else
						{
							colorCounter--;
						}
						break;

					case 1:
					case 3:
						if (colorCounter == maxColors)
						{
							colorCounter = 0;
						}
						else
						{
							colorCounter++;
						}
						break;

					default:
						break;
					}
				}
			}
			else
			{
				changePlayerColor[i].buttonColor = BLANK;
			}
		}
	}
}
}