#include "UI.h"

#include "game_manager.h"

namespace MyGame {
namespace UI {
using namespace GameManager;

	void createButton(const char* title, Button button, Color edgesColor, Color titleColor, float fontSize) {
		DrawRectangleRec(button.rec, button.color);
		DrawRectangleLinesEx(button.rec, static_cast<int>(button.lineThickness), edgesColor);
		DrawText(title, static_cast<int>(button.rec.x) - (MeasureText(title, static_cast<int>(fontSize)) / 2) + static_cast<int>(button.rec.width / 2),
			static_cast<int>(button.rec.y) - (static_cast<int>(fontSize) / 2) + static_cast<int>(button.rec.height) / 2,
			static_cast<int>(fontSize),
			titleColor);
	}
}
}