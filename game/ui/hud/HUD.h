#ifndef GAME_UI_HUD_HUD_H_
#define GAME_UI_HUD_HUD_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

class HUD
{
public:
	int32_t init();
	void deinit();
	void handleEvent(const InputEvent& e);
	void update(int32_t w, int32_t h, const Point& start, const Point& finish,
		int32_t blocked, int32_t path);
	void draw() const;

private:
	Point pos = Point::UNDEFINED;

	Text textCountX;
	Text textCountY;
	Text textStart;
	Text textFinish;
	Text textBlocked;
	Text textPath;
};

#endif // !GAME_UI_HUD_HUD_H_