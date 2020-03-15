#include "player_customization.h"

#include "managers\game_manager.h"
#include "managers\main_menu_manager.h"
#include "utility\UI.h"

namespace MyGame {
namespace PlayerCustomization {
using namespace GameManager;

	static void initColors();
	static void initPlayerRecs();
	static void initButtons();
	static void updateButtons();
	static void updateColor(Color &color, int counter);
	static void counterLogic(int &counter);
	static void drawColorNames(Rectangle rec, int counter);

	static const int maxButtons = 4;
	static const int maxColors = 23;

	static float titleFontSize = 50.0f;
	static float textFontSize = 25.0f;
	static int colorCounterPlayer1;
	static int colorCounterPlayer2;
	static float buttonDistanceFromX = 150;
	static float distanceFromY = 120;
	static float textDistanceFromY = 60;

	static Color colorSelection[maxColors];

	static Rectangle player1Rec;
	static Rectangle player2Rec;
	Color player1Color;
	Color player2Color;
	static Color edgesColor = LIGHTGRAY;

	static UI::Button changePlayerColorButton[maxButtons];

	static UI::Button startGame;
	static UI::Button backButton;

	void init() {

		colorCounterPlayer1 = 0;
		colorCounterPlayer2 = 0;

		initColors();
		initPlayerRecs();
		initButtons();
	}

	void update() {

		updateColor(player1Color, colorCounterPlayer1);
		updateColor(player2Color, colorCounterPlayer2);
		updateButtons();
	}

	void draw() {

		UI::drawProText("Choose your paddle´s color", screenWidth / 2, screenHeight / 2 - 350, titleFontSize, LIGHTGRAY);

		DrawRectangleRec(player1Rec, player1Color);
		DrawRectangleLinesEx(player1Rec, 5, edgesColor);

		DrawRectangleRec(player2Rec, player2Color);
		DrawRectangleLinesEx(player2Rec, 5, edgesColor);

		UI::drawButton("-", changePlayerColorButton[0]);
		UI::drawButton("+", changePlayerColorButton[1]);
		UI::drawButton("-", changePlayerColorButton[2]);
		UI::drawButton("+", changePlayerColorButton[3]);

		drawColorNames(player1Rec, colorCounterPlayer1);
		drawColorNames(player2Rec, colorCounterPlayer2);

		UI::drawButton("Start game", startGame);
		UI::drawButton("Back", backButton);
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

	void initPlayerRecs() {

		player1Rec.width = 230;
		player1Rec.height = 50;
		player1Rec.x = screenWidth / 2 - player1Rec.width / 2;
		player1Rec.y = screenHeight / 2 - distanceFromY - player1Rec.height / 2;

		player2Rec.width = 230;
		player2Rec.height = 50;
		player2Rec.x = screenWidth / 2 - player2Rec.width / 2;
		player2Rec.y = screenHeight / 2 + distanceFromY - player2Rec.height / 2;
	}

	void initButtons() {

		for (int i = 0; i < 4; i++)
		{
			changePlayerColorButton[i].rec.width = 30;
			changePlayerColorButton[i].rec.height = 30;
			changePlayerColorButton[i].lineThickness = 2;
			changePlayerColorButton[i].fontSize = 40;
			changePlayerColorButton[i].edgesColor = SKYBLUE;
			changePlayerColorButton[i].textColor = SKYBLUE;
			changePlayerColorButton[i].buttonColor = BLANK;
		}

		changePlayerColorButton[0].rec.x = screenWidth / 2 - buttonDistanceFromX - changePlayerColorButton[0].rec.width / 2;
		changePlayerColorButton[0].rec.y = screenHeight / 2 - distanceFromY - changePlayerColorButton[0].rec.height / 2;

		changePlayerColorButton[1].rec.x = screenWidth / 2 + buttonDistanceFromX - changePlayerColorButton[1].rec.width / 2;
		changePlayerColorButton[1].rec.y = screenHeight / 2 - distanceFromY - changePlayerColorButton[1].rec.height / 2;

		changePlayerColorButton[2].rec.x = screenWidth / 2 - buttonDistanceFromX - changePlayerColorButton[2].rec.width / 2;
		changePlayerColorButton[2].rec.y = screenHeight / 2 + distanceFromY - changePlayerColorButton[2].rec.height / 2;

		changePlayerColorButton[3].rec.x = screenWidth / 2 + buttonDistanceFromX - changePlayerColorButton[3].rec.width / 2;
		changePlayerColorButton[3].rec.y = screenHeight / 2 + distanceFromY - changePlayerColorButton[3].rec.height / 2;

		startGame.rec.width = 300;
		startGame.rec.height = 60;
		startGame.rec.x = screenWidth / 2 - startGame.rec.width / 2;
		startGame.rec.y = screenHeight / 2 + 270 - startGame.rec.height / 2;
		startGame.lineThickness = 3;
		startGame.fontSize = 40;
		startGame.edgesColor = SKYBLUE;
		startGame.textColor = SKYBLUE;
		startGame.buttonColor = BLANK;

		backButton.rec.width = 100;
		backButton.rec.height = 50;
		backButton.rec.x = screenWidth / 2 - backButton.rec.width / 2;
		backButton.rec.y = screenHeight / 2 + 340 - backButton.rec.height / 2;
		backButton.lineThickness = 3;
		backButton.fontSize = 30;
		backButton.edgesColor = SKYBLUE;
		backButton.textColor = SKYBLUE;
		backButton.buttonColor = BLANK;
	}

	void updateButtons() {

		counterLogic(colorCounterPlayer1);
		counterLogic(colorCounterPlayer2);

		UI::updateButtonColor(startGame);
		if (CheckCollisionPointRec(GetMousePosition(), startGame.rec))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				actualScene = Game;
			}
		}

		UI::updateButtonColor(backButton);
		if (CheckCollisionPointRec(GetMousePosition(), backButton.rec))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				MainMenuManager::mainMenuScene = MainMenuManager::menuSelection;
			}
		}

		for (int i = 0; i < maxButtons; i++)
		{
			UI::updateButtonColor(changePlayerColorButton[i]);
			if (CheckCollisionPointRec(GetMousePosition(), changePlayerColorButton[i].rec))
			{
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
				{
					switch (i)
					{
					case 0:
						colorCounterPlayer1--;
						break;

					case 1:
						colorCounterPlayer1++;
						break;

					case 2:
						colorCounterPlayer2--;
						break;

					case 3:
						colorCounterPlayer2++;
						break;

					default:
						break;
					}
				}
			}
		}
	}

	void counterLogic(int &counter) {

		if (counter < 0)
		{
			counter = 22;
		}

		if (counter > 22)
		{
			counter = 0;
		}
	}

	void updateColor(Color &color, int counter) {

		for (int i = 0; i <= maxColors; i++)
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
				color = colorSelection[counter];
				break;
			default:
				break;
			}
		}
	}

	void drawColorNames(Rectangle rec, int counter) {

		if (colorCounterPlayer1 == 21)
		{
			UI::drawProText("Player 1", player1Rec.x + player1Rec.width / 2, player1Rec.y - 30, textFontSize, LIGHTGRAY);
		}
		else
		{
			UI::drawProText("Player 1", player1Rec.x + player1Rec.width / 2, player1Rec.y - 30, textFontSize, colorSelection[colorCounterPlayer1]);
		}

		if (colorCounterPlayer2 == 21)
		{
			UI::drawProText("Player 2", player2Rec.x + player2Rec.width / 2, player2Rec.y - 30, textFontSize, LIGHTGRAY);
		}
		else
		{
			UI::drawProText("Player 2", player2Rec.x + player2Rec.width / 2, player2Rec.y - 30, textFontSize, colorSelection[colorCounterPlayer2]);
		}
		
		for (int i = 0; i <= maxColors; i++)
		{
			switch (counter)
			{
			case 0:
				UI::drawProText("LIGHTGRAY", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 1:
				UI::drawProText("GRAY", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 2:
				UI::drawProText("DARKGRAY", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 3:
				UI::drawProText("YELLOW", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 4:
				UI::drawProText("GOLD", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 5:
				UI::drawProText("ORANGE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 6:
				UI::drawProText("PINK", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 7:
				UI::drawProText("RED", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 8:
				UI::drawProText("MAROON", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 9:
				UI::drawProText("GREEN", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 10:
				UI::drawProText("LIME", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 11:
				UI::drawProText("DARKGREEN", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 12:
				UI::drawProText("SKYBLUE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 13:
				UI::drawProText("BLUE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 14:
				UI::drawProText("DARKBLUE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 15:
				UI::drawProText("PURPLE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 16:
				UI::drawProText("VIOLET", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 17:
				UI::drawProText("DARKPURPLE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 18:
				UI::drawProText("BEIGE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 19:
				UI::drawProText("BROWN", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 20:
				UI::drawProText("DARKBROWN", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			case 21:
				UI::drawProText("WHITE", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, LIGHTGRAY);
				break;

			case 22:
				UI::drawProText("MAGENTA", rec.x + rec.width / 2, rec.y + textDistanceFromY, textFontSize, colorSelection[counter]);
				break;

			default:
				break;
			}
		}
	}
}
}