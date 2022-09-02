// Corresponding header
#include "sdl_utils/drawing/DrawObject.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"

void DrawObject::deinit()
{
	Texture::destroyTexture(texture);
}

void DrawObject::reset()
{
	pos = Point::UNDEFINED;
	width = 0;
	height = 0;
	standardWidth = 0;
	standardHeight = 0;

	frameRect = Rectangle::ZERO;

	opacity = FULL_OPACITY;
	rotationAngle = ZERO_ROTATION;
	rotationCenter = Point::UNDEFINED;

	id = INVALID_ID;
	type = ObjectType::UNDEFINED;
	texture = nullptr;
}

// Setters
void DrawObject::setPos(int32_t x, int32_t y)
{
	this->pos.x = x; this->pos.y = y;
}

void DrawObject::setWidth(int32_t width)
{
	this->width = width;
}

void DrawObject::setHeight(int32_t height)
{
	this->height = height;
}

void DrawObject::setFrameRect(Rectangle rect)
{
	this->frameRect = rect;
}

void DrawObject::setOpacity(int32_t opacity)
{
	this->opacity = opacity;
}

void DrawObject::setRotationAngle(int32_t rotationAngle)
{
	this->rotationAngle = rotationAngle;
}

void DrawObject::setRotationCenter(Point rotationCenter)
{
	this->rotationCenter = rotationCenter;
}

void DrawObject::setId(int32_t id)
{
	this->id = id;
}

void DrawObject::setType(ObjectType type)
{
	this->type = type;
}

void DrawObject::setBlendMode(BlendMode mode)
{
	this->blendMode = blendMode;
}

void DrawObject::setFlipMode(FlipMode mode)
{
	this->flipMode = mode;
}

// Getters
Point DrawObject::getPos() const
{
	return this->pos;
}

int32_t DrawObject::getWidth() const
{
	return this->width;
}

int32_t DrawObject::getHeight() const
{
	return this->height;
}

Rectangle DrawObject::getFrameRect() const
{
	return this->frameRect;
}

int32_t DrawObject::getOpacity() const
{
	return this->opacity;
}

int32_t DrawObject::getRotationAngle() const
{
	return this->rotationAngle;
}

Point DrawObject::getRotationCenter() const
{
	return this->rotationCenter;
}

int32_t DrawObject::getId() const
{
	return this->id;
}

ObjectType DrawObject::getType()
{
	return this->type;
}

BlendMode DrawObject::getBlendMode()
{
	return this->blendMode;
}

FlipMode DrawObject::getFlipMode()
{
	return this->flipMode;
}

// Others
void DrawObject::moveUp(int32_t delta)
{
	this->pos.y -= delta;
}

void DrawObject::moveDown(int32_t delta)
{
	this->pos.y += delta;
}

void DrawObject::moveLeft(int32_t delta)
{
	this->pos.x -= delta;
}

void DrawObject::moveRight(int32_t delta)
{
	this->pos.x += delta;
}

void DrawObject::increaseWidth(int32_t delta)
{
	this->width += delta;
}

void DrawObject::increaseHeight(int32_t delta)
{
	this->height += delta;
}

void DrawObject::resize(int32_t width, int32_t height)
{
	this->width = width; this->height = height;
}

void DrawObject::resize(int32_t percentage)
{
	this->width = this->width * percentage / 100;
	this->height = this->height * percentage / 100;
}

void DrawObject::increaseOpacity(int32_t delta)
{
	this->opacity += delta;
	if (this->opacity >= FULL_OPACITY)
		this->opacity = FULL_OPACITY;
	else if (this->opacity <= ZERO_OPACITY)
		this->opacity = ZERO_OPACITY;
}

void DrawObject::setZeroOpacity()
{
	this->opacity = ZERO_OPACITY;
}

void DrawObject::setMaxOpacity()
{
	this->opacity = FULL_OPACITY;
}

void DrawObject::rotate(int32_t delta)
{
	this->rotationAngle += delta;
}

void DrawObject::show()
{
	visible = true;
}

void DrawObject::hide()
{
	visible = false;
}

bool DrawObject::isVisible() const
{
	return visible;
}

bool DrawObject::containsPoint(const Point& point) const
{
	return Rectangle(pos.x, pos.y, width, height).isPointInside(point);
}