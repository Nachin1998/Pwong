#include "game_manager.h"

#include <iostream>

#include "managers\main_menu_manager.h"
#include "scenes\gameplay.h"
#include "scenes\options.h"
#include "scenes\game_over.h"

namespace MyGame {
namespace GameManager{

	static void init();
	static void update();
	static void draw();
	static void deInit();

	struct GameEdge {
		Rectangle rec;
		int linesThick;
		Color color;
	};

	static GameEdge gameEdge;

	bool closeGame = false;

	Scene actualScene = MainMenu;

	Color backColor = WHITE;

	Music pongMusic;

	void runGame() {

		init();

		while (!WindowShouldClose() && !closeGame)
		{
			update();
			draw();
		}
		deInit();
	}

	void init() {

		InitWindow(screenWidth, screenHeight, "Pwong - by Ignacio Fernandez Lemos");
		InitAudioDevice();

		SetExitKey(KEY_F4);
		
		pongMusic = LoadMusicStream("res/music/BaseMusic.ogg");
		
		gameEdge.rec.width = screenWidth;
		gameEdge.rec.height = screenHeight;
		gameEdge.rec.x = screenWidth / 2 - gameEdge.rec.width / 2;
		gameEdge.rec.y = screenHeight / 2 - gameEdge.rec.height / 2;
		gameEdge.linesThick = 15;
		gameEdge.color = SKYBLUE;
		backColor = WHITE;

		MainMenuManager::init();
		Gameplay::init();
		GameOver::init();

		PlayMusicStream(pongMusic);
		SetMusicVolume(pongMusic, 1.0f);
	}

	void update() {

		UpdateMusicStream(pongMusic);

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
			MainMenuManager::update();
			break;

		case Game:
			Gameplay::update();
			break;

		case GameOver:
			GameOver::update();
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
			MainMenuManager::draw();
			break;

		case Game:
			Gameplay::draw();
			break;

		case GameOver:
			GameOver::draw();
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

		UnloadMusicStream(pongMusic);
		Gameplay::deInit();
		CloseAudioDevice();
		CloseWindow();
	}
}
}