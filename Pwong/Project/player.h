#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace MyGame {
namespace Player {

	struct Player {
		Rectangle rec;
		int score;
		Color color;
	};

	extern Player player1;
	extern Player player2;

	void init();
	void update();
	void draw();
}
}

#endif
