#pragma once
#include "Game.h"
#include <string>
#include <map>

class SoundManager {
public:
	static SoundManager* Instance() {
		if (s_mInstance == 0) {
			s_mInstance = new SoundManager();
			return s_mInstance;
		}
		return s_mInstance;
	}

	bool load(const char* fileName, std::string id, int type);
	void playSound(std::string id, int loop, int ms = 0);
	void playMusic(std::string id, int loop, int ms = 0);
	void changeVolume(int change);
	void pauseOrPlay();
	void changeVolumeSfx(std::string id, int c);
	void setMusicPosition(double pos);
private:
	static SoundManager* s_mInstance;
	// zvukovi failove
	std::map<std::string, Mix_Chunk*> s_mSfxs;

	//MIX MIZIC durji musizalnite failove
	std::map<std::string, Mix_Music*> s_mMusic;
	SoundManager();
	~SoundManager();

};