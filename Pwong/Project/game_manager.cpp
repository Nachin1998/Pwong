#include "game_manager.h"

#include <iostream>

#include "main_menu.h"
#include "gameplay.h"

namespace MyGame {
namespace GameManager{

	static void init();
	static void update();
	static void draw();
	static void deInit();

	Rectangle gameEdge;
	
	Scene actualScene = MainMenu;
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
		
		gameEdge.width = screenWidth;
		gameEdge.height = screenHeight;
		gameEdge.x = screenWidth / 2 - gameEdge.width / 2;
		gameEdge.y = screenHeight / 2 - gameEdge.height / 2;

		SetExitKey(KEY_F4);

		Gameplay::init();
		MainMenu::init();
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
			MainMenu::update();
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

		DrawRectangleLinesEx(gameEdge, 5, LIGHTGRAY);

		switch (actualScene)
		{
		case MainMenu:
			MainMenu::draw();
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