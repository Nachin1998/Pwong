#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

namespace MyGame {
namespace Gameplay {

	const int maxScore = 5;

	extern bool pause;
	extern bool startGame;

	void init();
	void update();
	void draw();
	void deInit();
}
}

#endif
