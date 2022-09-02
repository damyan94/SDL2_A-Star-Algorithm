#ifndef RECTANGLE_H_
#define RECTANGLE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct Point;

struct Rectangle
{
	int32_t x = 0;
	int32_t y = 0;
	int32_t w = 0;
	int32_t h = 0;

	Rectangle() = default;
	Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height);

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool isPointInside(const Point& point) const;

	static const Rectangle ZERO;
	static const Rectangle UNDEFINED;
};

#endif // !RECTANGLE_H_