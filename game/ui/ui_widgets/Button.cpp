// Corresponding header
#include "game/ui/ui_widgets/Button.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

const int32_t Button::STANDARD_WIDTH = 120;
const int32_t Button::STANDARD_HEIGHT = 36;
const int32_t Button::STANDARD_IMAGE_ID = ImageId::BUTTON_80X24;

// ================================================================================
int32_t Button::init(const char* txt, int32_t fontId = FontId::SYSTEM_BOLD_12,
	const Color& color = Colors::BLACK)
{
	image.init(STANDARD_IMAGE_ID);
	text.init(txt, fontId, Colors::BLACK);

	return EXIT_SUCCESS;
}

// ================================================================================
void Button::deinit()
{

}

// ================================================================================
void Button::handleEvent(const InputEvent& e)
{
	if (image.containsPoint(e.pos) && e.type == EventType::MOUSE_BUTTONDOWN &&
		e.mouse == Mouse::LEFT_BUTTON)
	{
		pressed = true;
		image.setFrame(ButtonFrames::CLICKED);
		text.moveDown(1);
		text.moveRight(1);
	}

	else if (pressed && e.type == EventType::MOUSE_BUTTONUP &&
		e.mouse == Mouse::LEFT_BUTTON)
	{
		reset();
		clicked = true;
	}
}

// ================================================================================
void Button::update()
{
	clicked = false;
}

// ================================================================================
void Button::draw() const
{
	image.draw();
	text.draw();
}

// ================================================================================
void Button::setPos(const Point& newPos)
{
	pos = newPos;
	image.setPos(pos.x, pos.y);
	text.setPos(pos.x + (image.getWidth() - text.getWidth()) / 2,
		pos.y + (image.getHeight() - text.getHeight()) / 2);
}

// ================================================================================
void Button::setWidth(int32_t newWidth)
{
	image.setWidth(newWidth);
	setPos(image.getPos());
}

// ================================================================================
void Button::setHeight(int32_t newHeight)
{
	image.setHeight(newHeight);
	setPos(image.getPos());
}

// ================================================================================
int32_t Button::getWidth() const
{
	return image.getWidth();
}

// ================================================================================
int32_t Button::getHeight() const
{
	return image.getHeight();
}

// ================================================================================
bool Button::wasClicked() const
{
	return clicked;
}

// ================================================================================
void Button::reset()
{
	pressed = false;
	clicked = false;
	image.setFrame(ButtonFrames::NORMAL);
	setPos(pos);
}