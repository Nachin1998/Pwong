#include "player.h"

#include "game_manager.h"

namespace MyGame {
namespace Player {
using namespace GameManager;

	static void playerMovement(Rectangle &playerRec, int keyUp, int keyDown);

	static float playerWidth = 25.0f;
	static float playerHeight = 150.0f;
	static int playerSpeed = 300;
	static int playerStartPosition = 80;
	static int mapLimit = 5;
	static Color playerEdges = LIGHTGRAY;
	static int playerEdgesThickness = 3;

	Player player1;
	Player player2;

	void init() {

		player1.rec.width = playerWidth;
		player1.rec.height = playerHeight;
		player1.rec.x = playerStartPosition - player1.rec.width / 2;
		player1.rec.y = screenHeight / 2 - player1.rec.height / 2;
		player1.score = 5;
		player1.color = RED;

		player2.rec.width = playerWidth;
		player2.rec.height = playerHeight;
		player2.rec.x = screenWidth - playerStartPosition - player2.rec.width / 2;
		player2.rec.y = screenHeight / 2 - player2.rec.height / 2;
		player2.score = 0;
		player2.color = GREEN;
	}

	void update() {

		playerMovement(player1.rec, KEY_W, KEY_S);
		playerMovement(player2.rec, KEY_UP, KEY_DOWN);
	}

	void draw() {

		DrawRectangleRec(player1.rec, player1.color);
		DrawRectangleLinesEx(player1.rec, playerEdgesThickness, playerEdges);

		DrawRectangleRec(player2.rec, player2.color);
		DrawRectangleLinesEx(player2.rec, playerEdgesThickness, playerEdges);
	}

	void playerMovement(Rectangle &playerRec, int keyUp, int keyDown) {

		if (playerRec.y > mapLimit)
		{
			if (IsKeyDown(keyUp))
			{
				playerRec.y -= playerSpeed * GetFrameTime();
			}
		}
		
		if (playerRec.y + playerRec.height < screenHeight - mapLimit)
		{
			if (IsKeyDown(keyDown))
			{
				playerRec.y += playerSpeed * GetFrameTime();
			}
		}
	}
}
}