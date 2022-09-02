#ifndef TEXT_H_
#define TEXT_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations

class Text : public DrawObject
{
public:
	~Text();

	int32_t init(const char* text, int32_t fontId, const Color& textColor);
	void deinit();
	void draw() const;

	void setText(const char* newText);
	void setColor(const Color& newColor);

	std::string getText() const;
	Color getColor() const;
	int32_t getFontSize() const;

private:
	std::string text;
	Color color = Colors::BLACK;
	int32_t fontSize = 0;
};

#endif // !TEXT_H_