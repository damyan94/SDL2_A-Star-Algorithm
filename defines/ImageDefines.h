#ifndef IMAGEDEFINES_H_
#define IMAGEDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

// Forward declarations

struct ImageInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
	int32_t frames = 1;
};

// These IDs must be the same as the human readable version in the included enum
const std::vector<ImageInfo> imagesInfo =
{
	{"assets/images/ui/button_80x24.png", ImageId::BUTTON_80X24, 3}
};

#define IMAGES_COUNT imagesInfo.size();

#endif // !IMAGEDEFINES_H_