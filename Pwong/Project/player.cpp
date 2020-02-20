#include "player.h"

#include "game_manager.h"

namespace MyGame {
namespace Player {
using namespace GameManager;

	static void playerMovement(Rectangle &rec, int keyUp, int keyDown);

	static float playerWidth = 20.0f;
	static float playerHeight = 120.0f;
	static int playerSpeed = 300;
	static int playerStartPosition = 80;
	static int mapLimit = 5;

	Player player1;
	Player player2;

	void init() {

		player1.rec.width = playerWidth;
		player1.rec.height = playerHeight;
		player1.rec.x = playerStartPosition - player1.rec.width / 2;
		player1.rec.y = screenHeight / 2 - player1.rec.width / 2;
		player1.color = RED;

		player2.rec.width = playerWidth;
		player2.rec.height = playerHeight;
		player2.rec.x = screenWidth - playerStartPosition - player2.rec.width / 2;
		player2.rec.y = screenHeight / 2 - player2.rec.width / 2;
		player2.color = GREEN;
	}

	void update() {

		playerMovement(player1.rec, KEY_W, KEY_S);
		playerMovement(player2.rec, KEY_UP, KEY_DOWN);
	
	}

	void draw() {

		DrawRectangleRec(player1.rec, player1.color);
		DrawRectangleLinesEx(player1.rec, 2, SKYBLUE);

		DrawRectangleRec(player2.rec, player2.color);
		DrawRectangleLinesEx(player2.rec, 2, SKYBLUE);
	}

	void playerMovement(Rectangle &rec, int keyUp, int keyDown) {

		if (rec.y  > mapLimit)
		{
			if (IsKeyDown(keyUp))
			{
				rec.y -= playerSpeed * GetFrameTime();
			}
		}
		
		if (rec.y + rec.height < screenHeight - mapLimit)
		{
			if (IsKeyDown(keyDown))
			{
				rec.y += playerSpeed * GetFrameTime();
			}
		}
	}
}
}