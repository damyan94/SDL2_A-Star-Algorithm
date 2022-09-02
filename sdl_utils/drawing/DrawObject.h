#ifndef DRAWOBJECT_H_
#define DRAWOBJECT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
struct SDL_Texture;

inline constexpr int32_t INVALID_ID = -1;
inline constexpr int32_t ZERO_OPACITY = 0;
inline constexpr int32_t FULL_OPACITY = 255;
inline constexpr int32_t ZERO_ROTATION = 0;
inline constexpr int32_t FULL_ROTATION = 360;

enum class ObjectType
{
	IMAGE = 0,
	TEXT = 1,
	UNDEFINED = -1
};

enum class BlendMode : uint8_t
{
	NONE = 0,
	BLEND = 1,
	ADD = 2,
	MOD = 4
};

enum class FlipMode : uint8_t
{
	NONE = 0,
	HORIZONTAL = 1,
	VERTICAL = 2,
	HORIZONTAL_AND_VERTICAL = 3
};

struct DrawObject
{
	virtual ~DrawObject() = default;

	void deinit();
	void reset();

	// Setters
	void setPos(int32_t x, int32_t y);
	void setWidth(int32_t width);
	void setHeight(int32_t height);
	void setFrameRect(Rectangle rect);
	void setOpacity(int32_t opacity);
	void setRotationAngle(int32_t rotationAngle);
	void setRotationCenter(Point rotationCenter);
	void setId(int32_t id);
	void setType(ObjectType type);
	void setBlendMode(BlendMode mode);
	void setFlipMode(FlipMode mode);

	// Getters
	Point getPos() const;
	int32_t getWidth() const;
	int32_t getHeight() const;
	Rectangle getFrameRect() const;
	int32_t getOpacity() const;
	int32_t getRotationAngle() const;
	Point getRotationCenter() const;
	int32_t getId() const;
	ObjectType getType();
	BlendMode getBlendMode();
	FlipMode getFlipMode();

	// Others
	void moveUp(int32_t delta);
	void moveDown(int32_t delta);
	void moveLeft(int32_t delta);
	void moveRight(int32_t delta);

	void increaseWidth(int32_t delta);
	void increaseHeight(int32_t delta);
	void resize(int32_t width, int32_t height);
	void resize(int32_t percentage);

	void increaseOpacity(int32_t delta);
	void setZeroOpacity();
	void setMaxOpacity();
	void rotate(int32_t delta);

	void show();
	void hide();

	bool isVisible() const;
	bool containsPoint(const Point& point) const;

protected:
	Point pos = Point::UNDEFINED;
	int32_t width = 0;
	int32_t height = 0;
	int32_t standardWidth = 0;
	int32_t standardHeight = 0;

	Rectangle frameRect = Rectangle::ZERO;

	int32_t opacity = FULL_OPACITY;
	int32_t rotationAngle = ZERO_ROTATION;
	Point rotationCenter = Point::UNDEFINED;

	int32_t id = INVALID_ID;
	ObjectType type = ObjectType::UNDEFINED;
	BlendMode blendMode = BlendMode::BLEND;
	FlipMode flipMode = FlipMode::NONE;

	bool visible = true;

	SDL_Texture* texture = nullptr;
};

#endif // !DRAWOBJECT_H_