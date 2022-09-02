#ifndef GLOBALCONSTANTS_H_
#define GLOBALCONSTANTS_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"

// Forward declarations

namespace WindowConstants
{
	inline constexpr const char* WINDOW_NAME = "Application";
	inline constexpr int32_t WINDOW_POS_X = 0x1FFF0000u; // SDL_WINDOWPOS_UNDEFINED
	inline constexpr int32_t WINDOW_POS_Y = 0x1FFF0000u; // SDL_WINDOWPOS_UNDEFINED
	inline constexpr int32_t WINDOW_WIDTH = 1280;
	inline constexpr int32_t WINDOW_HEIGHT = 720;
	inline constexpr int32_t WINDOW_FLAGS = 4; // SDL_WINDOW_SHOWN
}

namespace EngineConstants
{
	inline constexpr int32_t FPS = 50;
	inline constexpr int32_t TIME_PER_FRAME = 1000 / FPS;
	inline const Color RENDERER_DRAW_COLOR = Colors::BLACK;
}

namespace GameConstants
{

}

#endif // !GLOBALCONSTANTS_H_