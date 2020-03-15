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

	struct TickBox {
		Rectangle outerRec;
		Rectangle innerRec;
		float linesThick;
		bool active;
		Color outerColor;
		Color innerColor;
	};
	
	void initTickBox(TickBox &tickBox, float size, float posX, float posY, float edgeThick, bool active, Color linesColor);
	void tickBoxCollision(TickBox &tickBox);
	void drawTickBox(TickBox tickBox);

	void drawButton(const char *text, Button button);
	void updateButtonColor(Button &button);
	
	void drawProText(const char *text, float posX, float posY, float fontSize, Color textColor);
}
}

#endif