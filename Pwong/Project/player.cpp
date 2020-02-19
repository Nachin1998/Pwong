#include "player.h"

#include "game_manager.h"

namespace MyGame {
namespace Player {
using namespace GameManager;

	void init();
	void update();
	void draw();
	static void playerMovement(Rectangle &rec, int keyUp, int keyDown);

	static int playerWidth = 20;
	static int playerHeight = 120;
	static int playerSpeed = 300;
	static int playerStartPosition = 45;
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
		DrawRectangleRec(player2.rec, player2.color);
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