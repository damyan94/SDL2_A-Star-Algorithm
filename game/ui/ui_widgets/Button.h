#ifndef GAME_UI_UI_WIDGETS_BUTTON_H_
#define GAME_UI_UI_WIDGETS_BUTTON_H_

// C/C++ system includes
#include <cstdint>
#include <any>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

// Forward declarations

namespace ButtonFrames
{
	enum Frames
	{
		NORMAL = 1,
		CLICKED = 2,
		SELECTED = 3
	};
}

class Button
{
public:
	static const int32_t STANDARD_WIDTH;
	static const int32_t STANDARD_HEIGHT;
	static const int32_t STANDARD_IMAGE_ID;

public:
	int32_t init(const char* txt, int32_t fontId, const Color& color);
	void deinit();
	void handleEvent(const InputEvent& e);
	void update();
	void draw() const;

	void setPos(const Point& newPos);
	void setWidth(int32_t newWidth);
	void setHeight(int32_t newHeight);

	int32_t getWidth() const;
	int32_t getHeight() const;
	bool wasClicked() const;

	void reset();

private:
	Point pos = Point::UNDEFINED;
	bool pressed = false;
	bool clicked = false;

	Image image;
	Text text;
};

#endif // !GAME_UI_UI_WIDGETS_BUTTON_H_