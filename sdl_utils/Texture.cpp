// Corresponding header
#include "sdl_utils/Texture.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/drawing/DrawObject.h"

// IMG_Load
void Texture::createSurfaceFromFile(const char* fileName, SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight)
{
	outSurface = IMG_Load(fileName);
	if (!outSurface)
	{
		std::cout << "Error, IMG_Load() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	outWidth = outSurface->w;
	outHeight = outSurface->h;
}

// TTF_RenderText_Solid
void Texture::createSurfaceFromText(const char* text, const Color& color, TTF_Font* font, SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight)
{
	outSurface = TTF_RenderText_Blended(font, text, SDL_Color{ color.r, color.g, color.b, color.a });
	if (!outSurface)
	{
		std::cout << "Error, TTF_RenderText_Blended() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	outWidth = outSurface->w;
	outHeight = outSurface->h;
}

// SDL_CreateTextureFromSurface
void Texture::createTextureFromSurface(SDL_Surface* surface, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	outTexture = SDL_CreateTextureFromSurface(Renderer::getInstance(), surface);
	if (!outTexture)
	{
		std::cout << "Error, SDL_CreateTextureFromSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}

	outWidth = surface->w;
	outHeight = surface->h;
}

void Texture::createTextureFromFile(const char* fileName, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	createSurfaceFromFile(fileName, surface, outWidth, outHeight);
	if (!surface)
	{
		std::cout << "Error, createSurfaceFromFile() failed." << std::endl;
		return;
	}

	createTextureFromSurface(surface, outTexture, outWidth, outHeight);
	if (!outTexture)
	{
		std::cout << "Error, createTextureFromSurface() failed." << std::endl;
		return;
	}

	destroySurface(surface);
}

void Texture::createTextureFromText(const char* text, const Color& color, TTF_Font* font, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	createSurfaceFromText(text, color, font, surface, outWidth, outHeight);
	if (!surface)
	{
		std::cout << "Error, createSurfaceFromFile() failed." << std::endl;
		return;
	}

	createTextureFromSurface(surface, outTexture, outWidth, outHeight);
	if (!outTexture)
	{
		std::cout << "Error, createTextureFromSurface() failed." << std::endl;
		return;
	}

	destroySurface(surface);
}

// SDL_SetTextureBlendMode
void Texture::setTextureBlendMode(SDL_Texture*& texture, const BlendMode& blendMode)
{
	if (EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode)))
	{
		std::cerr << "Error, SDL_SetTextureBlendMode() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

// SDL_SetTextureAlphaMod
void Texture::setTextureAlphaMod(SDL_Texture* texture, int32_t alpha)
{
	if (alpha < ZERO_OPACITY)
		alpha = ZERO_OPACITY;

	if (alpha > FULL_OPACITY)
		alpha = FULL_OPACITY;

	if (EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, (uint8_t)alpha))
	{
		std::cerr << "Error, SDL_SetTextureAlphaMod() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

// SDL_RenderCopy
void Texture::renderTexture(SDL_Texture* texture, const Rectangle& srcRect, const Rectangle& dstRect, double angle, const Point& center, const FlipMode& flipMode)
{
	if (!&srcRect || !&dstRect)
	{
		std::cout << "Error, Texture::renderTexture() failed. Received invalid src or dst rectangle." << std::endl;
		return;
	}

	const SDL_Rect src{ srcRect.x, srcRect.y, srcRect.w, srcRect.h };
	const SDL_Rect dst{ dstRect.x, dstRect.y, dstRect.w, dstRect.h };
	const SDL_Point cntr{ center.x, center.y };

	if (EXIT_SUCCESS != SDL_RenderCopyEx(Renderer::getInstance(), texture, &src, &dst, angle, &cntr, (SDL_RendererFlip) flipMode))
	{
		std::cout << "Error, SDL_RenderCopy() failed. Reason: " << SDL_GetError() << std::endl;
		return;
	}
}

// SDL_FreeSurface
void Texture::destroySurface(SDL_Surface*& outSurface)
{
	if (outSurface)
	{
		SDL_FreeSurface(outSurface);
		outSurface = nullptr;
	}
}

// SDL_DestroyTexture
void Texture::destroyTexture(SDL_Texture*& outTexture)
{
	if (outTexture)
	{
		SDL_DestroyTexture(outTexture);
		outTexture = nullptr;
	}
}