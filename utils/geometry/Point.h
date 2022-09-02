#ifndef POINT_H_
#define POINT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

struct Point
{
	int32_t x = 0;
	int32_t y = 0;

	Point() = default;
	Point(int32_t posX, int32_t posY);

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	static const Point ZERO;
	static const Point UNDEFINED;
};

#endif // !POINT_H_