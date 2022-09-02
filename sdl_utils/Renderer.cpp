// Corresponding header
#include "sdl_utils/Renderer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_render.h>

// Own includes
#include "defines/GlobalConstants.h"
#include "utils/drawing/Color.h"

SDL_Renderer* Renderer::_gRenderer = nullptr;

// SDL_CreateRenderer
int32_t Renderer::init(SDL_Window* window, const Color& color)
{
	_gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!_gRenderer)
	{
		std::cerr << "Error, SDL_CreateRenderer() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawBlendMode(_gRenderer, SDL_BlendMode::SDL_BLENDMODE_BLEND))
	{
		std::cerr << "Error, SDL_SetRenderDrawBlendMode() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_gRenderer, color.r, color.g, color.b, color.a))
	{
		std::cerr << "Error, SDL_SetRenderDrawColor() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

// SDL_DestroyRenderer
void Renderer::deinit()
{
	if (_gRenderer)
	{
		SDL_DestroyRenderer(_gRenderer);
		_gRenderer = nullptr;
	}
}

// SDL_RenderClear
void Renderer::update()
{
	if (EXIT_SUCCESS != SDL_RenderClear(_gRenderer))
	{
		std::cerr << "Error, SDL_RenderClear() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

// SDL_RenderPresent
void Renderer::draw() const
{
	SDL_RenderPresent(_gRenderer);
}

// SDL_SetRenderDrawColor
void Renderer::setDrawColor(const Color& color)
{
	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_gRenderer, color.r, color.g, color.b, color.a))
	{
		std::cerr << "Error, SDL_SetRenderDrawColor() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

Color Renderer::getDefaultDrawColor()
{
	return EngineConstants::RENDERER_DRAW_COLOR;
}

SDL_Renderer* Renderer::getInstance()
{
	return _gRenderer;
}