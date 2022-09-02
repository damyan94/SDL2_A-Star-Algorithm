#ifndef RENDERER_H_
#define RENDERER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"

// Forward declarations
struct SDL_Renderer;
struct SDL_Window;

class Renderer
{
public:
	int32_t init(SDL_Window* window, const Color& color);
	void deinit();
	void update();
	void draw() const;

	static void setDrawColor(const Color& color);
	static Color getDefaultDrawColor();

	static SDL_Renderer* getInstance();

private:
	static SDL_Renderer* _gRenderer;
};

#endif // !RENDERER_H_