#ifndef GAME_UI_UI_WIDGETS_CHECKBOX_H_
#define GAME_UI_UI_WIDGETS_CHECKBOX_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

class CheckBox
{
public:
	int32_t init();
	void deinit();
	void handleEvent(const InputEvent& e);
	void update();
	void draw() const;

private:

};

#endif // !GAME_UI_UI_WIDGETS_CHECKBOX_H_