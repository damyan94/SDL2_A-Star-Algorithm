// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_image.h>

// Own includes
#include "defines/ImageDefines.h"
#include "sdl_utils/Texture.h"

std::unordered_map<int32_t, ImageContainer::ImageUnit> ImageContainer::_images;

ImageContainer::~ImageContainer()
{
	deinit();
}

// Texture::createTextureFromFile
int32_t ImageContainer::init()
{
	for (const auto& imageInfo : imagesInfo)
	{
		int32_t id = imageInfo.id;
		if (_images.find(id) != _images.end())
		{
			std::cout << "Error, found existing image with the same id: " << id << std::endl;
			return EXIT_FAILURE;
		}

		Texture::createTextureFromFile(imageInfo.fileName, _images[id].texture, _images[id].frameRect.w, _images[id].frameRect.h);
		if (!_images[id].texture)
		{
			std::cout << "Error, Texture::createTextureFromFile() failed for file: " << imageInfo.fileName << std::endl;
			return EXIT_FAILURE;
		}
		_images[id].frameRect.w /= imageInfo.frames;
		_images[id].frameRect.x = 0;
		_images[id].frameRect.y = 0;

		Texture::setTextureBlendMode(_images[id].texture, BlendMode::BLEND);

		_images[id].framesCount = imageInfo.frames;
	}

	return EXIT_SUCCESS;
}

// SDL_DestroyTexture
void ImageContainer::deinit()
{
	for (auto& image : _images)
		if (image.second.texture)
		{
			SDL_DestroyTexture(image.second.texture);
			image.second.texture = nullptr;
		}
}

SDL_Texture* ImageContainer::getImageTextureById(int32_t id)
{
	if (_images.find(id) == _images.end())
	{
		std::cout << "Error, could not find texture with id: " << id << std::endl;
		return nullptr;
	}

	return _images[id].texture;
}

Rectangle ImageContainer::getImageTextureFrameById(int32_t id)
{
	if (_images.find(id) == _images.end())
	{
		std::cout << "Error, could not find textureFrame with id: " << id << std::endl;
		return Rectangle::UNDEFINED;
	}

	return _images[id].frameRect;
}

int32_t ImageContainer::getImageFramesCountById(int32_t id)
{
	if (_images.find(id) == _images.end())
	{
		std::cout << "Error, could not find texture with id: " << id << std::endl;
		return EXIT_FAILURE;
	}

	return _images[id].framesCount;
}