// Corresponding header
#include "game/ui/hud/HUD.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// ================================================================================
int32_t HUD::init()
{
	textCountX.init("0", FontId::CONSOLA_24, Colors::WHITE);
	textCountY.init("0", FontId::CONSOLA_24, Colors::WHITE);
	textStart.init("0", FontId::CONSOLA_24, Colors::WHITE);
	textFinish.init("0", FontId::CONSOLA_24, Colors::WHITE);
	textBlocked.init("0", FontId::CONSOLA_24, Colors::WHITE);
	textPath.init("0", FontId::CONSOLA_24, Colors::WHITE);

	pos = Point(40, 10);
	const int32_t spacingX = 200;
	textCountX.setPos(pos.x + 0 * spacingX, pos.y);
	textCountY.setPos(pos.x + 1 * spacingX, pos.y);
	textStart.setPos(pos.x + 2 * spacingX, pos.y);
	textFinish.setPos(pos.x + 3 * spacingX, pos.y);
	textBlocked.setPos(pos.x + 4 * spacingX, pos.y);
	textPath.setPos(pos.x + 5 * spacingX, pos.y);

	return EXIT_SUCCESS;
}

// ================================================================================
void HUD::deinit()
{

}

// ================================================================================
void HUD::handleEvent(const InputEvent& e)
{

}

// ================================================================================
void HUD::update(int32_t w, int32_t h, const Point& start, const Point& finish,
	int32_t blocked, int32_t path)
{
	textCountX.setText(("|Cells X: " + std::to_string(w)).c_str());
	textCountY.setText(("|Cells Y: " + std::to_string(h)).c_str());

	if (start == Point::UNDEFINED)
	{
		textStart.setText("|Start: n/a");
	}
	else
	{
		textStart.setText(("|Start: " + std::to_string(start.x) + ", " +
			std::to_string(start.y)).c_str());
	}

	if(finish == Point::UNDEFINED)
	{
		textFinish.setText("|Finish: n/a");
	}
	else
	{
		textFinish.setText(("|Finish: " + std::to_string(finish.x) + ", " +
			std::to_string(finish.y)).c_str());
	}

	textBlocked.setText(("|Blocked: " + std::to_string(blocked)).c_str());
	textPath.setText(("|Path: " + std::to_string(path)).c_str());
}

// ================================================================================
void HUD::draw() const
{
	textCountX.draw();
	textCountY.draw();
	textStart.draw();
	textFinish.draw();
	textBlocked.draw();
	textPath.draw();
	SDLDrawing::drawLine(40, pos.y + 30, WindowConstants::WINDOW_WIDTH - 40,
		pos.y + 30, Colors::WHITE);
}