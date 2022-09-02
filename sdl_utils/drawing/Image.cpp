// Corresponding header
#include "sdl_utils/drawing/Image.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/ImageContainer.h"

int32_t Image::init(int32_t imageId)
{
	texture = ImageContainer::getImageTextureById(imageId);
	if (!texture)
	{
		std::cout << "Error, ImageContainer::getImageTextureById() failed for id: " << imageId << std::endl;
		return EXIT_FAILURE;
	}
	frameRect = ImageContainer::getImageTextureFrameById(imageId);

	pos = Point::ZERO;
	width = frameRect.w;
	height = frameRect.h;
	standardWidth = width;
	standardHeight = height;

	rotationCenter = Point(width / 2, height / 2);

	id = imageId;
	type = ObjectType::IMAGE;

	framesCount = ImageContainer::getImageFramesCountById(imageId);

	return EXIT_SUCCESS;
}

void Image::deinit()
{
	// This would destroy the texture inside the container
	//Texture::destroyTexture(texture);
}

void Image::draw() const
{
	if (!visible)
		return;

	Texture::setTextureAlphaMod(ImageContainer::getImageTextureById(id), opacity);

	if (opacity <= 0)
		return;

	Rectangle rect{ pos.x, pos.y, width, height };
	Texture::renderTexture(ImageContainer::getImageTextureById(id), frameRect, rect, (double)rotationAngle, rotationCenter, flipMode);
}

void Image::setFrame(int32_t frame)
{
	if (frame <= 0 || frame > framesCount)
	{
		std::cout << "Error, received invalid frame index for image with id: " << id << std::endl;
		return;
	}

	currFrame = frame;
	frameRect.x = (currFrame - 1) * standardWidth;
}

void Image::setPrevFrame()
{
	if (currFrame > 1)
		currFrame--;
	frameRect.x = (currFrame - 1) * standardWidth;
}

void Image::setNextFrame()
{
	if (currFrame < framesCount)
		currFrame++;
	frameRect.x = (currFrame - 1) * standardWidth;
}

int32_t Image::getCurrFrame() const
{
	return currFrame;
}

int32_t Image::getFramesCount() const
{
	return framesCount;
}