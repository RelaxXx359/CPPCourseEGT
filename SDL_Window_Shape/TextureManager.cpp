#include "TextureManager.h"

bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {
	SDL_Surface* tempSurface = IMG_Load(fileName);

	if (tempSurface == 0)
		return false;

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tex != 0) {
		textureMap[id] = tex;
		return true;
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

void TextureManager::drawOneFrameFromeTexture(std::string id, // id of texture to draw
	int x, int y,	// window x,y to draw at;
	int width, int height,  // width and height of texture
	int currentRow, int currentFrame, //row starts from 1
	SDL_Renderer* ren,
	SDL_RendererFlip flip) { // flag to flip texture

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
TextureManager* TextureManager::instance = 0;