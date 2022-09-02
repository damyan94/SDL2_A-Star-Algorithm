// Corresponding header
#include "sdl_utils/drawing/Text.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/FontContainer.h"

Text::~Text()
{
	deinit();
}

int32_t Text::init(const char* text, int32_t fontId, const Color& textColor)
{
	Texture::createTextureFromText(text, textColor, FontContainer::getFontById(fontId), texture, width, height);
	if (!texture)
	{
		std::cout << "Error, Texture::createTextureFromText() failed for id: " << id << std::endl;
		return EXIT_FAILURE;
	}

	pos = Point::ZERO;
	frameRect.w = width;
	frameRect.h = height;
	standardWidth = width;
	standardHeight = height;

	rotationCenter = Point(width / 2, height / 2);

	id = fontId;
	type = ObjectType::TEXT;

	this->text = text;
	color = textColor;
	fontSize = FontContainer::getFontSizeById(fontId);

	return EXIT_SUCCESS;
}

void Text::deinit()
{
	Texture::destroyTexture(texture);
}

void Text::draw() const
{
	if (!visible)
		return;

	Texture::setTextureAlphaMod(texture, opacity);

	if (opacity <= 0)
		return;

	Rectangle rect{ pos.x, pos.y, width, height };
	Texture::renderTexture(texture, frameRect, rect, (double)rotationAngle, rotationCenter, flipMode);
}

void Text::setText(const char* newText)
{
	Texture::destroyTexture(texture);
	Texture::createTextureFromText(newText, color, FontContainer::getFontById(id), texture, width, height);
	if (!texture)
	{
		std::cout << "Error, Texture::createTextureFromText() failed for id: " << id << std::endl;
		return;
	}

	frameRect.w = width;
	frameRect.h = height;
	standardWidth = width;
	standardHeight = height;
	text = newText;
}

void Text::setColor(const Color& newColor)
{
	Texture::destroyTexture(texture);
	Texture::createTextureFromText(text.c_str(), newColor, FontContainer::getFontById(id), texture, width, height);
	if (!texture)
	{
		std::cout << "Error, Texture::createTextureFromText() failed for id: " << id << std::endl;
		return;
	}

	frameRect.w = width;
	frameRect.h = height;
	standardWidth = width;
	standardHeight = height;
	color = newColor;
}

std::string Text::getText() const
{
	return text;
}

Color Text::getColor() const
{
	return color;
}

int32_t Text::getFontSize() const
{
	return fontSize;
}