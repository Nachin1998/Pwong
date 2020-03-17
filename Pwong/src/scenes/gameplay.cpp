#include "gameplay.h"

#include "managers\game_manager.h"
#include "scenes\options.h"
#include "player\player.h"
#include "utility\UI.h"

namespace MyGame {
namespace Gameplay {
using namespace GameManager;

	struct Ball {
		Vector2 pos;
		int radius;
		Vector2 movementSpeed;
		bool active;
		Color color;
	};
	
	struct MapDivision{
		Rectangle rec;
		Color color;
	};

	static Ball ball;
	static MapDivision mapDivision;

	static void ballUpdate();
	static void muteUpdate();
	static void pauseUpdate();
	static void collisionManager(Rectangle &playerRec);
	static void gameLogic(Player::Player &player);

	static float mapLimit = 15.0f;
	static float pointsSize = 200.0f;
	static float ballSpeed = 400.0f;

	bool startGame = false;
	bool endGame = false;
	bool pause = false;

	static Sound hitSound;

	void init() {

		startGame = false;
		endGame = false;
		pause = false;

		ball.pos.x = screenWidth / 2;
		ball.pos.y = screenHeight / 2;
		ball.radius = 10;
		ball.movementSpeed.x = ballSpeed;
		ball.movementSpeed.y = ballSpeed;
		ball.active = false;
		ball.color = LIGHTGRAY;

		mapDivision.rec.width = 10;
		mapDivision.rec.height = screenHeight;
		mapDivision.rec.x = screenWidth / 2 - mapDivision.rec.width / 2;
		mapDivision.rec.y = screenHeight / 2 - mapDivision.rec.height / 2;
		mapDivision.color = SKYBLUE;

		hitSound = LoadSound("res/sounds/hitSound.ogg");
		SetSoundVolume(hitSound, 0.3f);

		Player::init();
	}

	void update() {

		if (IsKeyPressed(KEY_SPACE))
		{
			startGame = true;
			ball.active = true;
		}
		
		muteUpdate();

		if (startGame)
		{
			pauseUpdate();

			if (!pause)
			{
				Player::update();
				ballUpdate();
				SetMusicVolume(pongMusic, 1.0f);

				if (!Options::darkMode)
				{
					backColor = WHITE;
				}
			}
			else
			{
				SetMusicVolume(pongMusic, 0.3f);

				if (!Options::darkMode)
				{
					backColor = BLACK;
				}
			}

			collisionManager(Player::player1.rec);
			collisionManager(Player::player2.rec);

			if (ball.pos.x + ball.radius + mapLimit > screenWidth)
			{
				gameLogic(Player::player1);
			}

			if (ball.pos.x - ball.radius - mapLimit < 0)
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
			UI::drawProText("Press `Space`", screenWidth / 2, screenHeight / 2 - 50, 80, LIGHTGRAY);
			UI::drawProText("to start the game", screenWidth / 2, screenHeight / 2 + 30, 80, LIGHTGRAY);
		}

		if (startGame && !pause)
		{
			UI::drawProText(FormatText("%i", Player::player1.score), screenWidth / 2 - 90, screenHeight / 2 - 92, pointsSize, SKYBLUE);
			DrawRectangleRec(mapDivision.rec, mapDivision.color);
			UI::drawProText(FormatText("%i", Player::player2.score), screenWidth / 2 + 90, screenHeight / 2 - 92, pointsSize, SKYBLUE);
		}

		if (!pause)
		{
			Player::draw();
			DrawCircleV(ball.pos, static_cast<float>(ball.radius), ball.color);
		}
		else
		{
			UI::drawProText("Paused", screenWidth / 2, screenHeight / 2 - 250, 120, LIGHTGRAY);
			UI::drawProText("Press `P` to continue", screenWidth / 2, screenHeight / 2 + 150, 50, LIGHTGRAY);

			UI::drawProText(FormatText("%i", Player::player1.score), screenWidth / 2 - 90, screenHeight / 2 - 92, pointsSize, Player::player1.color);
			UI::drawProText(FormatText("%i", Player::player2.score), screenWidth / 2 + 90, screenHeight / 2 - 92, pointsSize, Player::player2.color);

			DrawCircleGradient(static_cast<int>(ball.pos.x), static_cast<int>(ball.pos.y), static_cast<float>(ball.radius), BLACK, WHITE);
			DrawRectangleLinesEx(Player::player1.rec, 3, Player::player1.color);
			DrawRectangleLinesEx(Player::player2.rec, 3, Player::player2.color);
		}
	}

	void deInit() {

		UnloadSound(hitSound);
	}

	void ballUpdate() {

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

		if (ball.pos.y - ball.radius - mapLimit < 0 || ball.pos.y + ball.radius + mapLimit > screenHeight)
		{
			ball.movementSpeed.y *= -1;
		}
	}

	void muteUpdate() {

		if (IsKeyPressed(KEY_M))
		{
			if (IsMusicPlaying(pongMusic))
			{
				PauseMusicStream(pongMusic);
			}
			else
			{
				ResumeMusicStream(pongMusic);
			}
		}
	}

	void pauseUpdate() {

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
	}

	void collisionManager(Rectangle &playerRec) {

		if (CheckCollisionCircleRec(ball.pos, static_cast<float>(ball.radius), playerRec))
		{
			PlaySound(hitSound);

			if (ball.pos.y > playerRec.y && ball.pos.y < playerRec.y + playerRec.height)
			{
				ball.movementSpeed.x *= -1;
			}

			if (ball.pos.y < playerRec.y || ball.pos.y >  playerRec.y + playerRec.height) 
			{
				ball.movementSpeed.y *= -1;
			}
		}
	}

	void gameLogic(Player::Player &player) {

		ball.active = false;
		player.score += 1;

		if (player.score == maxScore) 
		{
			endGame = true;
		}
	}
}
}