#ifndef FONTCONTAINER_H_
#define FONTCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
typedef struct _TTF_Font TTF_Font;

class FontContainer
{
public:
	~FontContainer();

	int32_t init();
	void deinit();

	static TTF_Font* getFontById(int32_t id);
	static int32_t getFontSizeById(int32_t id);

private:
	struct FontUnit
	{
		TTF_Font* font = nullptr;
		int32_t size = 12;
	};

	static std::unordered_map<int32_t, FontUnit> _fonts;
};

#endif // !FONTCONTAINER_H_