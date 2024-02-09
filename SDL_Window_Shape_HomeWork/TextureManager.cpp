#include "TextureManager.h"

bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {
    SDL_Surface* tempSurface = IMG_Load(fileName); // Зарежда изображението от файл във временна повърхност

    if (tempSurface == nullptr) // Проверява дали зареждането е било успешно
        return false;

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface); // Създава текстура от повърхността
    SDL_FreeSurface(tempSurface); // Освобождава паметта на временната повърхност

    if (tex != nullptr) { // Проверява дали създаването на текстурата е било успешно
        textureMap[id] = tex; // Съхранява текстурата в асоциативния контейнер с ключа id
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

void TextureManager::drawOneFrameFromeTexture(std::string id, int x, int y, int width, int height, int currentRow,
                                              int currentFrame, SDL_Renderer* ren, SDL_RendererFlip flip) {
    // Създаване на ректни обекти за източната и целевата област
    SDL_Rect srcRect;
    SDL_Rect destRect;

    // Изчисляване на координатите на източната област в зависимост от текущия кадър и ред
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    // Задаване на координатите на целевата област
    destRect.x = x;
    destRect.y = y;

    // Копиране на единичния кадър от текстурата на целевата област с възможност за преобразуване (flip)
    SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

// Инициализация на указателя към единствената инстанция на класа
TextureManager* TextureManager::instance = nullptr;
