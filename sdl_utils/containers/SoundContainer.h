#ifndef SOUNDCONTAINER_H_
#define SOUNDCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes

// Forward declarations
struct Mix_Chunk;

class SoundContainer
{
public:
	~SoundContainer();

	int32_t init();
	void deinit();

	static Mix_Chunk* getSoundById(int32_t id);

private:
	static std::unordered_map<int32_t, Mix_Chunk*> _sounds;
};

#endif // !SOUNDCONTAINER_H_