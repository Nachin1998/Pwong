#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

namespace MyGame {
namespace Gameplay {

	struct Ball {
		Vector2 pos;
		float radius;
		Vector2 movementSpeed;
		bool active;
		Color color;
	};

	extern Ball ball;

	const int maxScore = 5;

	extern bool pause;
	extern bool startGame;

	void init();
	void update();
	void draw();
}
}

#endif
