#ifndef PLAYER_CUSTOMIZATION_H
#define PLAYER_CUSTOMIZATION_H

#include "raylib.h"

namespace MyGame {
namespace PlayerCustomization {
	
	extern Color player1Color;
	extern Color player2Color;

	void init();
	void update();
	void draw();
}
}

#endif
