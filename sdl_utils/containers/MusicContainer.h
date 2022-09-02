#ifndef MUSICCONTAINER_H_
#define MUSICCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes

// Forward declarations
typedef struct _Mix_Music Mix_Music;

class MusicContainer
{
public:
	~MusicContainer();

	int32_t init();
	void deinit();

	static Mix_Music* getMusicById(int32_t id);

private:
	static std::unordered_map<int32_t, Mix_Music*> _musics;
};

#endif // !MUSICCONTAINER_H_