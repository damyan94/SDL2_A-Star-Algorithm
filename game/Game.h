#ifndef GAME_H_
#define GAME_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

// Forward declarations
class Pathfinder;
class HUD;
class BottomMenu;

class Game
{
public:
	int32_t init();
	void deinit();
	void handleEvent(const InputEvent& e);
	void update();
	void draw() const;

private:
	Pathfinder* pathfinder;
	HUD* hud;
	BottomMenu* bottomMenu;
};

#endif // !GAME_H_