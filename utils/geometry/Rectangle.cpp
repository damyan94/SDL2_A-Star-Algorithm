// Corresponding header
#include "utils/geometry/Rectangle.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"

const Rectangle Rectangle::ZERO = Rectangle(0, 0, 0, 0);
const Rectangle Rectangle::UNDEFINED = Rectangle(100000, 100000, 0, 0);

Rectangle::Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height) : x(posX), y(posY), w(width), h(height)
{

}

bool Rectangle::operator==(const Rectangle& other) const
{
	return (this->x == other.x) && (this->y == other.y) && (this->w == other.w) && (this->h == other.h);
}

bool Rectangle::operator!=(const Rectangle& other) const
{
	return !(*this == other);
}

bool Rectangle::isPointInside(const Point& point) const
{
	return (point.x >= this->x) && (point.x <= this->x + this->w) &&
		(point.y >= this->y) && (point.y <= this->y + this->h);
}