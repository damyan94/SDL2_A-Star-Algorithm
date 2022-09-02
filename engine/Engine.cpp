// Corresponding header
#include "engine/Engine.h"

// C/C++ system includes
#include <iostream>
#include <thread>

// Third-party includes

// Own includes
#include "defines/GlobalConstants.h"
#include "utils/time/Timer.h"
#include "sdl_utils/SDLLoader.h"
#include "engine/console/Console.h"

int32_t Engine::init()
{
	// SDL init
	if (EXIT_SUCCESS != SDLLoader::init())
	{
		std::cerr << "Error, SDLLoader::init() failed." << std::endl;
		return EXIT_FAILURE;
	}
	
	// Base functionalities init
	if (EXIT_SUCCESS != _window.init())
	{
		std::cerr << "Error, _window.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _renderer.init(_window.getInstance(), EngineConstants::RENDERER_DRAW_COLOR))
	{
		std::cerr << "Error, _renderer.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _event.init())
	{
		std::cerr << "Error, _event.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	// Containers init
	if (EXIT_SUCCESS != _imageContainer.init())
	{
		std::cerr << "Error, _imageContainer.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _fontContainer.init())
	{
		std::cerr << "Error, _fontContainer.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _soundContainer.init())
	{
		std::cerr << "Error, _soundContainer.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _musicContainer.init())
	{
		std::cerr << "Error, _musicContainer.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	// Game init
	if (EXIT_SUCCESS != _game.init())
	{
		std::cerr << "Error, _game.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	_console = new Console;
	_console->init();

	Timer::startGlobalTimer();

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	_console->deinit();
	_game.deinit();

	_musicContainer.deinit();
	_soundContainer.deinit();
	_fontContainer.deinit();
	_imageContainer.deinit();

	_event.deinit();
	_renderer.deinit();
	_window.deinit();
	SDLLoader::deinit();
}

void Engine::handleEvent()
{
	_console->handleEvent(_event);
	if (_console->getIsActive())
		return;

	_game.handleEvent(_event);
}

void Engine::update()
{
	Timer::updateTimers();
	_game.update();
	_console->update(_currFPS);
	_renderer.update();
}

void Engine::draw() const
{
	_game.draw();
	_console->draw();
	_renderer.draw();
}

void Engine::runApplication()
{
	Time clock;

	while (true)
	{
		while (_event.pollEvent())
		{
			if (_event.type == EventType::QUIT)
				return;

			handleEvent();
		}

		update();
		draw();

		int64_t elapsedTime = clock.getElapsedTime(UnitsOfTime::MILLISECONDS);
		int64_t totalFrameTime = elapsedTime;
		auto sleepTime = std::chrono::milliseconds(EngineConstants::TIME_PER_FRAME - elapsedTime);
		if (sleepTime.count() > 0)
		{
			std::this_thread::sleep_for(sleepTime);
			totalFrameTime += sleepTime.count();
		}

		if (totalFrameTime > 0)
			_currFPS = 1000 / totalFrameTime;
	}
}