#ifndef INPUT_EVENT_H_
#define INPUT_EVENT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "sdl_utils/input/EventDefines.h"

// Forward declarations
union SDL_Event;

class InputEvent
{
public:
	int32_t init();
	void deinit();

	bool pollEvent();

	int32_t type = EventType::UNKNOWN;
	int32_t key = Keyboard::KEY_UNKNOWN;
	const uint8_t *keystates = nullptr;
	uint8_t mouse = Mouse::UNKNOWN;
	int32_t wheel = Mouse::WHEEL_UP_DOWN_TRESHOLD;

	Point pos = Point::UNDEFINED;

	bool lmbHold = false;

private:
	SDL_Event* _event = nullptr;
};

#endif // !INPUT_EVENT_H_