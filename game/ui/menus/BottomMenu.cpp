// Corresponding header
#include "game/ui/menus/BottomMenu.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// ================================================================================
int32_t BottomMenu::init(bool background)
{
	hasBackground = background;
	pos = Point(STANDARD_POS_X, STANDARD_POS_Y);
	width = STANDARD_WIDTH;
	height = STANDARD_HEIGHT;
	colorBackground = Colors::LIGHT_GREY;

	buttons.resize(ButtonId::COUNT);
	buttons[ButtonId::RESET].init("Reset", FontId::SYSTEM_BOLD_12, Colors::BLACK);

	int32_t spacingX = 12;
	int32_t totalButtonsWidth = 0;
	std::vector<int32_t> widths;
	widths.resize(ButtonId::COUNT);
	for (int32_t i = 0; i < ButtonId::COUNT; i++)
	{
		widths[i] = buttons[i].getWidth();
		totalButtonsWidth += widths[i];
	}

	totalButtonsWidth += (buttons.size() - 1) * spacingX;
	int32_t buttonsPosX = (width - totalButtonsWidth) / 2;
	int32_t buttonsPosY = pos.y + (height - buttons[ButtonId::INVALID + 1].getHeight()) / 2;

	buttons[ButtonId::RESET].setPos(Point(buttonsPosX + (widths[ButtonId::RESET] + spacingX) * 0, buttonsPosY));

	return EXIT_SUCCESS;
}

// ================================================================================
void BottomMenu::deinit()
{

}

// ================================================================================
void BottomMenu::handleEvent(const InputEvent& e)
{
	for (auto& button : buttons)
	{
		button.handleEvent(e);
	}
}

// ================================================================================
void BottomMenu::update()
{
	for (auto& button : buttons)
	{
		button.update();
	}
}

// ================================================================================
void BottomMenu::draw() const
{
	if (hasBackground)
	{
		SDLDrawing::drawFilledRectangle(pos.x, pos.y, width, height, colorBackground);
	}

	for (const auto& button : buttons)
	{
		button.draw();
	}
}

int32_t BottomMenu::getClickedButtonId() const
{
	if (buttons[ButtonId::RESET].wasClicked())
	{
		return ButtonId::RESET;
	}

	return ButtonId::INVALID;
}