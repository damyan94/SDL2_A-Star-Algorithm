#ifndef IMAGE_H_
#define IMAGE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations

class Image : public DrawObject
{
public:
	int32_t init(int32_t imageId);
	void deinit();
	void draw() const;

	void setFrame(int32_t frame);
	void setPrevFrame();
	void setNextFrame();

	int32_t getCurrFrame() const;
	int32_t getFramesCount() const;

private:
	int32_t framesCount = 1;
	int32_t currFrame = 1;
};

#endif // !IMAGE_H_