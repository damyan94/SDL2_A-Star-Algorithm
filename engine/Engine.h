#ifndef ENGINE_H_
#define ENGINE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/input/InputEvent.h"

#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/FontContainer.h"
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

#include "game/Game.h"

// Forward declarations
class Console;

class Engine
{
public:
	int32_t init();
	void deinit();
	void handleEvent();
	void update();
	void draw() const;

	void runApplication();

private:
	Window _window;
	Renderer _renderer;
	InputEvent _event;

	ImageContainer _imageContainer;
	FontContainer _fontContainer;
	SoundContainer _soundContainer;
	MusicContainer _musicContainer;

	Console* _console;
	Game _game;

	int64_t _currFPS = 0;
};

#endif // !ENGINE_H_