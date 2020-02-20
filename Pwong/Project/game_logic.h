#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "raylib.h"

namespace MyGame {
namespace GameLogic {

	struct Ball {
		Vector2 position;
		float radius;
		bool active;
		Color color;
	};

	extern Ball ball;
	extern bool pause;
	extern bool startGame;

	void init();
	void update();
	void draw();
}
}

#endif
