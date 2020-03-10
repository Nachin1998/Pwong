#include "UI.h"

#include "managers\game_manager.h"

namespace MyGame {
namespace UI {
using namespace GameManager;

	void initTickBox(TickBox &tickBox, float size, float posX, float posY, int edgeThick, bool active, Color linesColor) {

		tickBox.outerRec.width = size;
		tickBox.outerRec.height = size;
		tickBox.outerRec.x = posX - tickBox.outerRec.width / 2;
		tickBox.outerRec.y = posY - tickBox.outerRec.height / 2;
		tickBox.innerRec.width = tickBox.outerRec.width - size / 2.5f;
		tickBox.innerRec.height = tickBox.outerRec.height - size / 2.5f;
		tickBox.innerRec.x = posX - tickBox.innerRec.width / 2;
		tickBox.innerRec.y = posY - tickBox.innerRec.height / 2;
		tickBox.linesThick = edgeThick;
		tickBox.active = active;
		tickBox.outerColor = LIGHTGRAY;
		tickBox.innerColor = BLANK;
	}

	void tickBoxCollision(TickBox &tickBox) {

		if (CheckCollisionPointRec(GetMousePosition(), tickBox.outerRec))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (tickBox.active)
				{
					tickBox.active = false;
				}
				else
				{
					tickBox.active = true;
				}
			}

			if (tickBox.active)
			{
				tickBox.outerColor = DARKGREEN;
				tickBox.innerColor = DARKGREEN;
			}
			else
			{
				tickBox.outerColor = LIGHTGRAY;
				tickBox.innerColor = LIGHTGRAY;
			}
		}
		else
		{
			if (tickBox.active)
			{
				tickBox.outerColor = GREEN;
				tickBox.innerColor = GREEN;
			}
			else
			{
				tickBox.outerColor = LIGHTGRAY;
				tickBox.innerColor = BLANK;
			}
		}
	}

	void drawTickBox(TickBox tickBox) {

		DrawRectangleLinesEx(tickBox.outerRec, tickBox.linesThick, tickBox.outerColor);
		DrawRectangleRec(tickBox.innerRec, tickBox.innerColor);
	}

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