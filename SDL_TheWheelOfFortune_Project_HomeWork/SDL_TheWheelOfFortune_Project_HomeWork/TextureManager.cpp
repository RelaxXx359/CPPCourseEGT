﻿  #include "TextureManager.h"

bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {

	SDL_Surface* tempSurface = IMG_Load(fileName); //fileName е пътят на файла до изображението

	if (tempSurface == 0)
		return false;  

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tex != 0) { 
		textureMap[id] = tex; 
	}

	return false; 

}

void TextureManager::drawTexture(std::string id,
	int x, int y,
	int width, int height,
	SDL_Renderer* ren,
	SDL_RendererFlip flip) {

	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawOneFrameFromTexture(std::string id, 
	int x, int y,
	int width, int height, 
	int currentRow, int currentFrame, 
	SDL_Renderer* ren,
	SDL_RendererFlip flip) { 

	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);

}

	void TextureManager::drawRotation(std::string id, int x, int y, int width, int height, SDL_Renderer * ren, int rotationSpeed) {

		static float angle = 0;
		angle += rotationSpeed;

		
		SDL_Rect srcRect;
		SDL_Rect destRect;
		SDL_Point center;
		center.x = width / 2;
		center.y = height / 2;

		srcRect.x = srcRect.y = 0;
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;

		SDL_RenderCopyEx(ren, textureMap[id], nullptr, &destRect, angle, &center, SDL_FLIP_NONE);

}

TextureManager* TextureManager::instance = 0;