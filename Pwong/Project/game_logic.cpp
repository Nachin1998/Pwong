#include "game_logic.h"

#include "player.h"
#include "game_manager.h"

namespace MyGame {
namespace GameLogic {
using namespace GameManager;

	static void gameUpdate();

	bool pause = false;
	bool startGame = false;

	Ball ball;

	void init() {
		ball.active = false;
		ball.position.x = screenWidth / 2;
		ball.position.y = screenHeight / 2;
		ball.radius = 5.0f;
		ball.color = LIGHTGRAY;

		Player::init();
	}

	void update() {
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
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			startGame = true;
		}
		
		gameUpdate();
	}

	void draw() {
		if (!pause)
		{
			Player::draw();
			DrawCircleV(ball.position, ball.radius, ball.color);
		}
		else
		{
			DrawText("Paused", screenWidth / 2 - MeasureText("Paused", 80) / 2, screenHeight / 2 - 50, 80, LIGHTGRAY);
			DrawText("Press ´P´ to continue", screenWidth / 2 - MeasureText("Press ´P´ to continue", 40) / 2, screenHeight / 2 + 30, 40, LIGHTGRAY);
			
			DrawCircleLines(ball.position.x, ball.position.y, ball.radius, ball.color);
			DrawRectangleLinesEx(Player::player1.rec, 3, Player::player1.color);
			DrawRectangleLinesEx(Player::player2.rec, 3, Player::player2.color);
		}
	}

	void gameUpdate() {

	}

}
}