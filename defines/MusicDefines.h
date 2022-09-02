#ifndef MUSICDEFINES_H_
#define MUSICDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"

// Forward declarations

struct MusicInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
};

// These IDs must be the same as the human readable version in the included enum
const std::vector<MusicInfo> musicsInfo =
{

};

#define MUSICS_COUNT musicsInfo.size();

#endif // !MUSICDEFINES_H_