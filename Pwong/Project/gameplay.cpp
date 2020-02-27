#include "gameplay.h"

#include "player.h"
#include "game_manager.h"

namespace MyGame {
namespace Gameplay {
using namespace GameManager;

	static struct MapDivision{
		Rectangle rec;
		Color color;
	};

	static MapDivision mapDivision;

	static void ballUpdate();
	static void collisionManager(Rectangle &playerRec);
	static void gameLogic(Player::Player &player);

	bool startGame = false;
	bool endGame = false;
	bool pause = false;

	Ball ball;

	void init() {

		startGame = false;
		endGame = false;
		pause = false;

		ball.pos.x = screenWidth / 2;
		ball.pos.y = screenHeight / 2;
		ball.radius = 8.0f;
		ball.movementSpeed.x = 250.0f;
		ball.movementSpeed.y = 250.0f;
		ball.active = false;
		ball.color = SKYBLUE;

		mapDivision.rec.width = 15;
		mapDivision.rec.height = screenHeight;
		mapDivision.rec.x = screenWidth / 2 - mapDivision.rec.width / 2;
		mapDivision.rec.y = screenHeight / 2 - mapDivision.rec.height / 2;
		mapDivision.color = LIGHTGRAY;

		Player::init();
	}

	void update() {

		if (IsKeyPressed(KEY_ENTER))
		{
			startGame = true;
		}

		if (startGame)
		{
			if (IsKeyPressed(KEY_P))
			{
				if (!pause)
				{
					pause = true;
				}
				else
				{
					pause = false;
				}
			}

			if (!pause)
			{
				Player::update();
				ballUpdate();
			}

			collisionManager(Player::player1.rec);
			collisionManager(Player::player2.rec);

			if (ball.pos.x + ball.radius + 3 > screenWidth)
			{
				gameLogic(Player::player1);
			}

			if (ball.pos.x - ball.radius - 3 < 0)
			{
				gameLogic(Player::player2);
			}
		}

		if (endGame == true)
		{
			actualScene = GameOver;
		}
	}

	void draw() {

		
		if (!startGame)
		{
			DrawText("Press ´Enter´", screenWidth / 2 - MeasureText("Press ´Enter´", 80) / 2, screenHeight / 2 - 50, 80, LIGHTGRAY);
			DrawText("to start the game", screenWidth / 2 - MeasureText("to start the game", 80) / 2, screenHeight / 2 + 30, 80, LIGHTGRAY);
		}

		if (startGame && !pause)
		{
			DrawText(FormatText("%i", Player::player1.score), screenWidth / 2 - MeasureText("0", 200) / 2 - 90, screenHeight / 2 - 92, 200, LIGHTGRAY);
			DrawRectangleRec(mapDivision.rec, mapDivision.color);
			DrawText(FormatText("%i", Player::player2.score), screenWidth / 2 - MeasureText("0", 200) / 2 + 90, screenHeight / 2 - 92, 200, LIGHTGRAY);
		}

		if (!pause)
		{
			Player::draw();
			DrawCircleV(ball.pos, ball.radius, ball.color);
			
		}
		else
		{
			DrawText("Paused", screenWidth / 2 - MeasureText("Paused", 80) / 2, screenHeight / 2 - 50, 80, LIGHTGRAY);
			DrawText("Press ´Enter´ to continue", screenWidth / 2 - MeasureText("Press ´Enter´ to continue", 40) / 2, screenHeight / 2 + 30, 40, LIGHTGRAY);
			
			DrawText(FormatText("%i", Player::player1.score), screenWidth / 2 - MeasureText("0", 200) / 2 - 90, screenHeight / 2 - 92, 200, RED);
			DrawText(FormatText("%i", Player::player2.score), screenWidth / 2 - MeasureText("0", 200) / 2 + 90, screenHeight / 2 - 92, 200, GREEN);

			DrawCircleGradient(ball.pos.x, ball.pos.y, ball.radius, BLACK, WHITE);
			DrawRectangleLinesEx(Player::player1.rec, 3, Player::player1.color);
			DrawRectangleLinesEx(Player::player2.rec, 3, Player::player2.color);
		}
	}

	void ballUpdate() {

		if (!startGame)
		{
			ball.active = false;
		}
		else
		{
			ball.active = true;
		}

		if (ball.active)
		{
			ball.pos.x += ball.movementSpeed.x * GetFrameTime();
			ball.pos.y += ball.movementSpeed.y * GetFrameTime();
		}
		else
		{
			ball.pos.x = screenWidth / 2;
			ball.pos.y = screenHeight / 2;
		}

		if (ball.pos.y - ball.radius - 3 < 0 || ball.pos.y + ball.radius + 3 > screenHeight)
		{
			ball.movementSpeed.y *= -1;
		}
	}

	void collisionManager(Rectangle &playerRec) {

		if (CheckCollisionCircleRec(ball.pos, ball.radius, playerRec))
		{
			if ((ball.pos.x < playerRec.x || ball.pos.x > playerRec.x) && (ball.pos.y < playerRec.y || ball.pos.y > playerRec.y))
			{
				ball.movementSpeed.x *= -1;
			}
		}
	}

	void gameLogic(Player::Player &player) {

		ball.pos.y = screenHeight / 2;
		ball.pos.x = screenWidth / 2;
		player.score += 1;

		if (player.score == 5) 
		{
			endGame = true;
		}
	}
}
}