// TextureManager.h
#pragma once
#include "Game.h"
#include <string>
#include <map>

class TextureManager {
public:
	//зарежда текстура от файл и я асоциира с определено идентификатор.
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);

	// изчертава текстура на определена позиция с опция за обръщане.
	void drawTexture(std::string id,int x, int y,int width, int height,SDL_Renderer* ren,SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawOneFrameFromTexture(std::string id, // id of texture to draw
		int x, int y,	// window x,y to draw at;
		int width, int height,  // width and height of texture
		int currentRow, int currentFrame, //row starts from 1
		SDL_Renderer* ren,
		SDL_RendererFlip flip);
	static TextureManager* Instance() { // предоставя достъп до единствения екземпляр на TextureManager
		if (instance == 0) {
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}
	// изчертава текстура на определена позиция с възможност за въртене.
	void drawRotation(std::string id, int x, int y, int width, int height, SDL_Renderer* ren, int rotationSpeed);

private:
	std::map<std::string, SDL_Texture*> textureMap; // съхранява заредените текстури като ги съпоставя с техните идентификатори.
	TextureManager() {} // частен конструктор използван за налагане на шаблона Singleton.
	static TextureManager* instance; // Статичен член, който съдържа единствения екземпляр на класа. 
	
};