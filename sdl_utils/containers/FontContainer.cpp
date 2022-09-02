// Corresponding header
#include "sdl_utils/containers/FontContainer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_ttf.h>

// Own includes
#include "defines/FontDefines.h"
#include "sdl_utils/Texture.h"

std::unordered_map<int32_t, FontContainer::FontUnit> FontContainer::_fonts;

FontContainer::~FontContainer()
{
	deinit();
}

// TTF_OpenFont
int32_t FontContainer::init()
{
	for (const auto& fontInfo : fontsInfo)
	{
		int32_t id = fontInfo.id;
		if(_fonts.find(id) != _fonts.end())
		{
			std::cout << "Error, found existing font with the same id: " << id << std::endl;
			return EXIT_FAILURE;
		}

		_fonts[id].size = fontInfo.size;
		_fonts[id].font = TTF_OpenFont(fontInfo.fileName, fontInfo.size);
		if (!_fonts[id].font)
		{
			std::cout << "Error, TTF_OpenFont() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

// TTF_CloseFont
void FontContainer::deinit()
{
	for (auto& font : _fonts)
		if (font.second.font)
		{
			TTF_CloseFont(font.second.font);
			font.second.font = nullptr;
		}
}

TTF_Font* FontContainer::getFontById(int32_t id)
{
	if (_fonts.find(id) == _fonts.end())
	{
		std::cout << "Error, could not find font with id: " << id << std::endl;
		return nullptr;
	}

	return _fonts[id].font;
}

int32_t FontContainer::getFontSizeById(int32_t id)
{
	if (_fonts.find(id) == _fonts.end())
	{
		std::cout << "Error, could not find font with id: " << id << std::endl;
		return EXIT_FAILURE;
	}

	return _fonts[id].size;
}