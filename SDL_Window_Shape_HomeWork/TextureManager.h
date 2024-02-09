#pragma once
#include "Game.h"
#include <string>
#include <map>

class TextureManager {
public:
        // Метод за зареждане на текстура от файл
    bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);

    // Метод за изчертаване на цяла текстура на екрана
    void drawTexture(std::string id, int x, int y, int weidth, int height,
		SDL_Renderer* ren, SDL_RendererFlip flip = SDL_FLIP_NONE);


    // Метод за изчертаване на единичен кадър от текстура
    void drawOneFrameFromeTexture(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer* ren, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Статичен метод за достъп до инстанцията на класа (Singleton)
    static TextureManager* Instance() {
		if (instance == 0) {
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}

private:
    // Асоциативен контейнер за съхранение на текстурите
    std::map<std::string, SDL_Texture*> textureMap;
    // Конструктор, скрит от външния свят (приватен)
    TextureManager(){}
    // Указател към единствената инстанция на класа (Singleton)
    static TextureManager* instance;
};
