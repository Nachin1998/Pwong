#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "raylib.h"

namespace MyGame {
namespace GameManager{

	const int screenWidth = 1500;
	const int screenHeight = 800;

	enum Scene {
		MainMenu,
		Game,
		GameOver,
		Credits
	};

	extern Scene actualScene;
	extern Music pongMusic;
	extern Color backColor;
	extern bool closeGame;

	void runGame();
}
}

#endif