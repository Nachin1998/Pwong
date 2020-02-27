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

	static struct GameEdge {
		Rectangle rec;
		int linesThick;
		Color color;
	};

	static GameEdge gameEdge;
	
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
		
		gameEdge.rec.width = screenWidth;
		gameEdge.rec.height = screenHeight;
		gameEdge.rec.x = screenWidth / 2 - gameEdge.rec.width / 2;
		gameEdge.rec.y = screenHeight / 2 - gameEdge.rec.height / 2;
		gameEdge.linesThick = 5;
		gameEdge.color = LIGHTGRAY;

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

		DrawRectangleLinesEx(gameEdge.rec, gameEdge.linesThick, gameEdge.color);

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