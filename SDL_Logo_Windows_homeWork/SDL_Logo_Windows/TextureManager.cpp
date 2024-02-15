#include "TextureManager.h"

// load image
bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {
	SDL_Surface* tempSurface = IMG_Load(fileName);

	// succes check
	if (tempSurface == nullptr) {
		return false;
	}
	// create texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);


	if (tex != nullptr) {
		textureMap[id] = tex;
		return true;
	}
	return false;
}
void TextureManager::drawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* ren, SDL_RendererFlip flip) {
	// Създаване на ректни обекти за източната и целевата област
	SDL_Rect srcRect;
	SDL_Rect destRect;

	// Задаване на координатите и размерите на източната област
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	// Задаване на координатите на целевата област
	destRect.x = x;
	destRect.y = y;

	// Копиране на текстурата на целевата област с възможност за преобразуване (flip)
	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::drawOneFrameTexture(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
	SDL_Renderer* ren,SDL_RendererFlip flip) {


	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}
void TextureManager::changeTexture(std::string id) {
	bool state = display[id];
	// Проверка дали текстурата със зададеното id съществува в картата display
	if (display.find(id) != display.end()) {
		// Превключване на видимостта
		display[id] = !display[id];
	}
}

TextureManager*  TextureManager::Instance() {
	if (instance == 0) {
		instance = new TextureManager();
		return instance;
	}
	return instance;
}
TextureManager* TextureManager::instance = nullptr;
