#ifndef UI_H
#define UI_H

#include "raylib.h"

namespace MyGame {
namespace UI {
	
	struct Button {
		Rectangle rec;
		float lineThickness;
		float fontSize;
		Color edgesColor;
		Color textColor;
		Color buttonColor;
	};

	void createTitle(const char *title, Button button, Color edgesColor, Color textColor, float fontSize);
	void createButton(const char *text, Button button);
	void drawProText(const char *text, float posX, float posY, float fontSize, Color textColor);
}
}

#endif