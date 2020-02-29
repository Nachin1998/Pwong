#include "UI.h"

#include "game_manager\game_manager.h"

namespace MyGame {
namespace UI {
using namespace GameManager;

	void createButton(const char* text, Button button) {

		DrawRectangleRec(button.rec, button.buttonColor);
		DrawRectangleLinesEx(button.rec, static_cast<int>(button.lineThickness), button.edgesColor);
		DrawText(text, static_cast<int>(button.rec.x) - (MeasureText(text, static_cast<int>(button.fontSize)) / 2) + static_cast<int>(button.rec.width / 2),
			static_cast<int>(button.rec.y) - (static_cast<int>(button.fontSize) / 2) + static_cast<int>(button.rec.height) / 2,
			static_cast<int>(button.fontSize),
			button.textColor);
	}

	void drawProText(const char *text, float posX, float posY, float fontSize, Color textColor) {

		DrawText(text, posX - MeasureText(text, fontSize) / 2, posY, fontSize, textColor);
	}
}
}