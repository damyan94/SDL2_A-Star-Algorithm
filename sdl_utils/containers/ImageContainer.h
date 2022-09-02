#ifndef IMAGECONTAINER_H_
#define IMAGECONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
struct SDL_Texture;

class ImageContainer
{
public:
	~ImageContainer();

	int32_t init();
	void deinit();

	static SDL_Texture* getImageTextureById(int32_t id);
	static Rectangle getImageTextureFrameById(int32_t id);
	static int32_t getImageFramesCountById(int32_t id);

private:
	struct ImageUnit
	{
		SDL_Texture* texture = nullptr;
		Rectangle frameRect = Rectangle::ZERO;
		int32_t framesCount = 1;
	};

	static std::unordered_map<int32_t, ImageUnit> _images;
};

#endif // !IMAGECONTAINER_H_