#ifndef WINDOW_H_
#define WINDOW_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct SDL_Window;

class Window
{
public:
	int32_t init();
	void deinit();

	SDL_Window* getInstance() const;

private:
	static SDL_Window* _gWindow;
};

#endif // !WINDOW_H_