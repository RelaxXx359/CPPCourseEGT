// TextureManager.h
#pragma once
#include "Game.h"
#include <string>
#include <map>

class TextureManager {
public:
	//зарежда текстура от файл и я асоциира с определено идентификатор.
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);

	
	//  Функцията drawTexture рисува текстура
	 //  id Идентификатор на текстурата, която ще бъде нарисувана
	 //  x X-координата на горния ляв ъгъл на местоположението, където текстурата ще бъде нарисувана
	 //  y Y-координата на горния ляв ъгъл на местоположението, където текстурата ще бъде нарисувана
	 //  width Ширина на текстурата
	 //  height Височина на текстурата
	 //  ren Указател към рендеръра, който ще използва за рисуване на текстурата
	 //  flip Флаг за обръщане на текстурата 

	void drawTexture(std::string id,int x, int y,int width, int height,SDL_Renderer* ren,SDL_RendererFlip flip = SDL_FLIP_NONE);

		
	 //Функцията drawOneFrameFromTexture рисува един кадър от текстура
	 //
	 //  id Идентификатор на текстурата, от която ще бъде извлечен един кадър за рисуване
	 //  x X-координата на горния ляв ъгъл на местоположението, където кадърът ще бъде нарисуван
	 //  y Y-координата на горния ляв ъгъл на местоположението, където кадърът ще бъде нарисуван
	 //  ren Указател към рендеръра, който ще използва за рисуване на кадъра
	 //  flip Флаг за обръщане на кадъра 
	 
	void drawOneFrameFromTexture(std::string id, 
		int x, int y,	
		int width, int height,  
		int currentRow, int currentFrame,   
		SDL_Renderer* ren,
		SDL_RendererFlip flip);


	
	static TextureManager* Instance() { // предоставя достъп до единствения екземпляр на TextureManager
		if (instance == 0) {
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}

	
	 //Функцията drawRotation рисува текстура с въртене на определена скорост
	 //
	 //  id Идентификатор на текстурата, която ще бъде нарисувана
	 //  x X-координата на горния ляв ъгъл на местоположението, където текстурата ще бъде нарисувана
	 //  y Y-координата на горния ляв ъгъл на местоположението, където текстурата ще бъде нарисувана
	 //  width Ширина на текстурата
	 //  height Височина на текстурата
	 //  ren Указател към рендеръра, който ще използва за рисуване на текстурата
	 //  rotationSpeed Скорост на въртене на текстурата
 
	void drawRotation(std::string id, int x, int y, int width, int height, SDL_Renderer* ren, int rotationSpeed);



private:
	std::map<std::string, SDL_Texture*> textureMap; // съхранява заредените текстури като ги съпоставя с техните идентификатори.
	TextureManager() {} // частен конструктор използван за налагане на шаблона Singleton.
	static TextureManager* instance; // Статичен член, който съдържа единствения екземпляр на класа. 
	
};