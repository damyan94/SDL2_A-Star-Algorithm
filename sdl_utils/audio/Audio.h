#ifndef AUDIO_H_
#define AUDIO_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"
#include "defines/id/MusicId.h"

// Forward declarations

namespace Audio
{
	constexpr int32_t LOOP_NONE = 0;
	constexpr int32_t LOOP_INFINITELY = -1;
	constexpr int32_t FIRST_FREE_CHANNEL = -1;
	constexpr int32_t ALL_CHANNELS = -1;
	constexpr uint8_t VOLUME_ZERO = 0;
	constexpr uint8_t VOLUME_MAX = 128;

	void playSound(int32_t soundId, int32_t loops);
	void pauseSounds();
	void stopSounds();

	void playMusic(int32_t musicId, int32_t loops);
	void pauseMusic();
	void stopMusic();

	void setSoundsVolume(uint8_t volume);
	void setMusicVolume(uint8_t volume);

	uint8_t getSoundsVolume();
	uint8_t getMusicVolume();

	bool playingMusic();
	bool pausedMusic();
};

#endif // !AUDIO_H_