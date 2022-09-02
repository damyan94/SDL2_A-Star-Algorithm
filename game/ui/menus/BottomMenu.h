#ifndef GAME_UI_UI_MENUS_BOTTOMMENU_H_
#define GAME_UI_UI_MENUS_BOTTOMMENU_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"
#include "game/ui/ui_widgets/Button.h"

// Forward declarations

namespace ButtonId
{
	enum ButtonIds
	{
		INVALID = -1,
		RESET = 0,
		COUNT
	};
}

class BottomMenu
{
public:
	static constexpr int32_t STANDARD_WIDTH = WindowConstants::WINDOW_WIDTH;
	static constexpr int32_t STANDARD_HEIGHT = 48;
	static constexpr int32_t STANDARD_POS_X = 0;
	static constexpr int32_t STANDARD_POS_Y = WindowConstants::WINDOW_HEIGHT - STANDARD_HEIGHT;

public:
	int32_t init(bool background);
	void deinit();
	void handleEvent(const InputEvent& e);
	void update();
	void draw() const;

	int32_t getClickedButtonId() const;

private:
	Point pos = Point::UNDEFINED;
	int32_t width = 0;
	int32_t height = 0;
	Color colorBackground = Colors::BLACK;
	bool hasBackground = false;

	std::vector<Button> buttons;
};

#endif // !GAME_UI_UI_MENUS_BOTTOMMENU_H_