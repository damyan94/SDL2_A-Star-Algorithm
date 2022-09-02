#ifndef SOUNDDEFINES_H_
#define SOUNDDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"

// Forward declarations

struct SoundInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
};

// These IDs must be the same as the human readable version in the included enum
const std::vector<SoundInfo> soundsInfo =
{
	{"assets/sounds/clicks/mouse_click_full.wav", SoundId::MC_FULL},
	{"assets/sounds/clicks/mouse_click_press.wav", SoundId::MC_PRESS},
	{"assets/sounds/clicks/mouse_click_release.wav", SoundId::MC_RELEASE}
};

#define SOUNDS_COUNT soundsInfo.size();

#endif // !SOUNDDEFINES_H_