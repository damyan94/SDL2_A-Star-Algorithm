#ifndef TEXTURE_H_
#define TEXTURE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations
struct Rectangle;
struct Color;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

namespace Texture
{
	void createSurfaceFromFile(const char* fileName, SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight);
	void createSurfaceFromText(const char* text, const Color& color, TTF_Font* font, SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight);

	void createTextureFromSurface(SDL_Surface* surface, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight);

	void createTextureFromFile(const char* fileName, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight);
	void createTextureFromText(const char* text, const Color& color, TTF_Font* font, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight);

	void setTextureBlendMode(SDL_Texture*& texture, const BlendMode& blendMode);
	void setTextureAlphaMod(SDL_Texture* texture, int32_t alpha);

	void renderTexture(SDL_Texture* texture, const Rectangle& srcRect, const Rectangle& dstRect, double angle, const Point& center, const FlipMode& flipMode);

	void destroySurface(SDL_Surface*& outSurface);
	void destroyTexture(SDL_Texture*& outTexture);
}

#endif // !TEXTURE_H_