#include "UI.h"

#include "game_manager.h"

namespace MyGame {
namespace UI {
using namespace GameManager;

	Vector2 mousePos = GetMousePosition();

	void createTitle(const char* title, Button button, Color edgesColor, Color titleColor, float fontSize) {
		DrawRectangleRec(button.rec, button.buttonColor);
		DrawRectangleLinesEx(button.rec, static_cast<int>(button.lineThickness), edgesColor);
		DrawText(title, static_cast<int>(button.rec.x) - (MeasureText(title, static_cast<int>(fontSize)) / 2) + static_cast<int>(button.rec.width / 2),
			static_cast<int>(button.rec.y) - (static_cast<int>(fontSize) / 2) + static_cast<int>(button.rec.height) / 2,
			static_cast<int>(fontSize),
			titleColor);
	}

	void createButton(const char* text, Button button, Color edgesColor, Color titleColor, float fontSize) {
		DrawRectangleRec(button.rec, button.buttonColor);
		DrawRectangleLinesEx(button.rec, static_cast<int>(button.lineThickness), edgesColor);
		DrawText(text, static_cast<int>(button.rec.x) - (MeasureText(text, static_cast<int>(fontSize)) / 2) + static_cast<int>(button.rec.width / 2),
			static_cast<int>(button.rec.y) - (static_cast<int>(fontSize) / 2) + static_cast<int>(button.rec.height) / 2,
			static_cast<int>(fontSize),
			titleColor);
	}

	void createProText(const char *text, float posX, float posY, float fontSize, Color textColor) {

		DrawText(text, posX - MeasureText(text, fontSize) / 2, posY, fontSize, textColor);
	}
}
}