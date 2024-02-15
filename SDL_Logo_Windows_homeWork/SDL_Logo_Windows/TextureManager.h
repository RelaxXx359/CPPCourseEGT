#pragma once
#include <string>
#include "Game.h"
#include <map>


class TextureManager {
public:

	// метод за зареждане на текстура от файл
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);


	// метод за изчертаване на текстура на екрана

	void drawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* ren, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// метод за изчетраване на единичен кадър от текстура
	void drawOneFrameTexture(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	//статичен метод за достъп до инстанцията на клас
	static TextureManager* Instance();
		
	void changeTexture(std::string id);


private:
	std::map<std::string, SDL_Texture*> textureMap;
	std::map<std::string, bool> display;

	TextureManager(){}
	static TextureManager* instance;


};

