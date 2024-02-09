#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
	if(Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 4096) == -1){
		std::cout << Mix_GetError() << std::endl;
	}
}


bool SoundManager::load(const char* fileName, std::string id, int type) {
	//type1 => music, type0 => sfx
	if (type == 1) {
		Mix_Music* music = Mix_LoadMUS(fileName);
		if (music == 0) {
			std::cout << "Could not load music" << Mix_GetError() << std::endl;
			return false;
		}
		s_mMusic[id] = music;
		return true;
	}
	else {
		if (type == 0) { // SFX
			Mix_Chunk* chunk = Mix_LoadWAV(fileName);
			if (chunk == 0) {
				std::cout << "Could not load sfx" << Mix_GetError() << std::endl;
				return false;
			}
			s_mSfxs[id]= chunk;
			return true;
		}
	}
}
void SoundManager::playMusic(std::string id, int loop, int ms) {
	Mix_FadeInMusic(s_mMusic[id], loop, ms);
}

void SoundManager::playSound(std::string id, int loop, int ms) {
	Mix_FadeInChannel(-1, s_mSfxs[id], loop, ms);
}

void SoundManager::changeVolume(int c) {
	int currentVolume = Mix_VolumeMusic(-1);
	std::cout << currentVolume << " " << Mix_VolumeMusic(-1) << std::endl;
	currentVolume += c; 
	Mix_VolumeMusic(currentVolume);
}

// задавасе името на музиката и се увеличава или намалява
void SoundManager::changeVolumeSfx(std::string id, int c) {
	int currentVolume = Mix_VolumeChunk(s_mSfxs[id], -1);
	currentVolume += c;
	Mix_VolumeChunk(s_mSfxs[id], currentVolume);
}
void SoundManager::setMusicPosition(double pos) {
	if (Mix_SetMusicPosition(pos) == -1) {
		std::cout << "Something failed:" << Mix_GetError() << std::endl;
	}
}


void SoundManager::pauseOrPlay() {
	std::cout << Mix_PlayingMusic() << std::endl;
	if (Mix_PlayingMusic() == 0) {
		Mix_PausedMusic();
	}
	else{
		Mix_ResumeMusic();
	}
}
//void SoundManager::pauseOrPlay() {
//	std::cout << Mix_PlayingMusic() << std::endl;
//	if (Mix_PlayingMusic() == 0) {
//		Mix_PauseMusic(); // Паузирай музиката ако се възпроизвежда
//	}
//	else {
//		Mix_ResumeMusic(); // Продължи възпроизвеждането на музиката ако е паузирана
//	}
//}

SoundManager* SoundManager::s_mInstance = 0;







