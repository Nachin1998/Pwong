#include "game_manager.h"

#include <iostream>
#include "raylib.h"

#include "gameplay.h"

namespace MyGame {
namespace GameManager{

	static void init();
	static void update();
	static void draw();
	static void deInit();
	
	Scene actualScene = Game;

	Color backColor = WHITE;

	void runGame() {

		init();

		while (!WindowShouldClose())
		{
			update();
			draw();
		}
		deInit();
	}

	void init() {

		InitWindow(screenWidth, screenHeight, "Pwong - by Ignacio Fernandez Lemos");

		//InitAudioDevice();
		
		SetExitKey(KEY_F4);

		Gameplay::init();
		//All inits
	}

	void update() {
		//UpdateMusicStream(musica);

		if (Gameplay::pause) 
		{
			backColor = BLACK;
		}
		else
		{
			backColor = WHITE;
		}

		switch (actualScene)
		{
		case MainMenu:
			break;

		case Game:
			Gameplay::update();
			break;

		case Credits:
			break;

		default:
			std::cout << "There was an error in the game manager Update section" << std::endl;
			break;
		}
	}

	void draw() {

		BeginDrawing();

		ClearBackground(backColor);

		switch (actualScene)
		{
		case MainMenu:
			break;

		case Game:
			Gameplay::draw();
			break;

		case Credits:
			break;

		default:
			std::cout << "There was an error in the game manager Drawing section" << std::endl;
			break;
		}

		EndDrawing();
	}

	void deInit() {

	}
}
}