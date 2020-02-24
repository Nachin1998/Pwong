#ifndef UI_H
#define UI_H

#include "raylib.h"

namespace MyGame {
namespace UI {
	
	struct Button {
		Rectangle rec;
		float lineThickness;
		Color color;
	};

	void createButton(const char* title, Button button, Color edgesColor, Color titleColor, float fontSize);
}
}

#endif