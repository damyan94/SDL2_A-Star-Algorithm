// Corresponding header
#include "sdl_utils/audio/Audio.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_mixer.h>

// Own includes
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

// Mix_PlayChannel
void Audio::playSound(int32_t soundId, int32_t loops)
{
	Mix_PlayChannel(Audio::FIRST_FREE_CHANNEL, SoundContainer::getSoundById(soundId), loops);
}

// Mix_Pause
void Audio::pauseSounds()
{
	Mix_Pause(ALL_CHANNELS);
}

// Mix_HaltChannel
void Audio::stopSounds()
{
	Mix_HaltChannel(ALL_CHANNELS);
}

// Mix_PlayMusic
void Audio::playMusic(int32_t musicId, int32_t loops)
{
	Mix_PlayMusic(MusicContainer::getMusicById(musicId), loops);
}

// Mix_PauseMusic
void Audio::pauseMusic()
{
	Mix_PauseMusic();
}

// Mix_HaltMusic
void Audio::stopMusic()
{
	Mix_HaltMusic();
}

// Mix_Volume
void Audio::setSoundsVolume(uint8_t volume)
{
	if (volume < VOLUME_ZERO || volume > VOLUME_MAX)
	{
		std::cout << "Error, Audio::setSoundsVolume() received invalid parameter volume: " << volume << std::endl;
		return;
	}

	Mix_Volume(ALL_CHANNELS, volume);
}

// Mix_VolumeMusic
void Audio::setMusicVolume(uint8_t volume)
{
	if (volume < VOLUME_ZERO || volume > VOLUME_MAX)
	{
		std::cout << "Error, Audio::setSoundsVolume() received invalid parameter volume: " << volume << std::endl;
		return;
	}

	Mix_VolumeMusic(volume);
}

uint8_t Audio::getSoundsVolume()
{
	return Mix_Volume(ALL_CHANNELS, -1);
}

uint8_t Audio::getMusicVolume()
{
	return Mix_VolumeMusic(-1);
}

// Mix_PlayingMusic
bool Audio::playingMusic()
{
	return Mix_PlayingMusic();
}

// Mix_PausedMusic
bool Audio::pausedMusic()
{
	return Mix_PausedMusic();
}