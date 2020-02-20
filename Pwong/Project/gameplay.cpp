#include "gameplay.h"

#include "player.h"
#include "game_manager.h"

namespace MyGame {
namespace GameLogic {
using namespace GameManager;

	static void ballUpdate();
	static void collisionManager(Rectangle &playerRec);
	//static void collisionManager(Player::Player player);

	bool pause = false;
	bool startGame = false;

	Ball ball;

	void init() {

		ball.active = false;
		ball.pos.x = screenWidth / 2;
		ball.pos.y = screenHeight / 2;
		ball.radius = 8.0f;
		ball.movementSpeed.x = 150.0f;
		ball.movementSpeed.y = 150.0f;
		ball.color = SKYBLUE;

		Player::init();
	}

	void update() {

		if (IsKeyPressed(KEY_SPACE))
		{
			startGame = true;
		}

		if(startGame)
		{
			if (IsKeyPressed(KEY_ENTER))
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
		}
	}

	void draw() {

		if (!startGame)
		{
			DrawText("Press ´Space´", screenWidth / 2 - MeasureText("Press ´Space´", 80) / 2, screenHeight / 2 - 50, 80, LIGHTGRAY);
			DrawText("to start the game", screenWidth / 2 - MeasureText("to start the game", 80) / 2, screenHeight / 2 + 30, 80, LIGHTGRAY);
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

		if (ball.pos.x - ball.radius - 3 < 0 || ball.pos.x + ball.radius + 3 > screenWidth)
		{
			ball.movementSpeed.x *= -1;
		}

		if (ball.pos.y - ball.radius - 3 < 0 || ball.pos.y + ball.radius + 3 > screenHeight)
		{
			ball.movementSpeed.y *= -1;
		}
	}

	void collisionManager(Rectangle &playerRec) {

		if (CheckCollisionCircleRec(ball.pos, ball.radius, playerRec))
		{
			ball.movementSpeed.x *= -1;
		}
	}
}
}