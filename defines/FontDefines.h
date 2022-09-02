#ifndef FONTDEFINES_H_
#define FONTDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"

// Forward declarations

struct FontInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
	int32_t size = 12;
};

// These IDs must be the same as the human readable version in the included enum
const std::vector<FontInfo> fontsInfo =
{
	{"assets/fonts/vgasysr.fon", FontId::SYSTEM_BOLD_12, 12},

	{"assets/fonts/Consola.ttf", FontId::CONSOLA_12, 12},
	{"assets/fonts/Consola.ttf", FontId::CONSOLA_18, 18},
	{"assets/fonts/Consola.ttf", FontId::CONSOLA_24, 24},

	{"assets/fonts/ROGFontsv1.6-Regular.ttf", FontId::ROG_36, 36},
	{"assets/fonts/ROGFontsv1.6-Regular.ttf", FontId::ROG_72, 72}
};

#define FONTS_COUNT fontsInfo.size();

#endif // !FONTDEFINES_H_