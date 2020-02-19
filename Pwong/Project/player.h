#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace MyGame {
namespace Player {

	struct Player {
		Rectangle rec;
		Color color;
	};

	void init();
	void update();
	void draw();

}
}

#endif
