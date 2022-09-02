// Corresponding header
#include "sdl_utils/input/InputEvent.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_events.h>

// Own includes

int32_t InputEvent::init()
{
	_event = new SDL_Event{};
	if (!_event)
	{
		std::cerr << "Error, failed to init SDL_Event()." << std::endl;
		return EXIT_FAILURE;
	}
	_event->wheel.y;

	return EXIT_SUCCESS;
}

void InputEvent::deinit()
{
	if (_event)
	{
		delete _event;
		_event = nullptr;
	}
}

// SDL_PollEvent
bool InputEvent::pollEvent()
{
	if (SDL_PollEvent(_event))
	{
		SDL_GetMouseState(&pos.x, &pos.y);
		keystates = SDL_GetKeyboardState(NULL);
		type = _event->type;

		switch (type)
		{
		case EventType::KEYBOARD_PRESS:
			key = _event->key.keysym.sym;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::KEYBOARD_RELEASE:
			key = _event->key.keysym.sym;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::MOUSE_BUTTONDOWN:
			key = Keyboard::KEY_UNKNOWN;
			mouse = _event->button.button;
			if (mouse == Mouse::LEFT_BUTTON)
				lmbHold = true;
			break;

		case EventType::MOUSE_BUTTONUP:
			key = Keyboard::KEY_UNKNOWN;
			mouse = _event->button.button;
			if (mouse == Mouse::LEFT_BUTTON)
				lmbHold = false;
			break;

		case EventType::FINGER_DOWN:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::FINGER_UP:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::MOUSE_WHEEL:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			wheel = _event->wheel.y;
			break;

		case EventType::MOUSE_MOTION:
			if (lmbHold)
			{
				key = Keyboard::KEY_UNKNOWN;
				mouse = Mouse::LEFT_BUTTON;
				type = EventType::MOUSE_LMB_HOLD_MOTION;
			}
			break;

		default:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			break;
		}

		return true;
	}

	return false;
}