#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Shapes.h"
class Game {
public:
    Game();
    ~Game();
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning();
private:
    // Прозорец на SDL
    SDL_Window* window = NULL;
    // изображение на SDL
    SDL_Renderer* renderer = NULL;
    // Променлива, указваща дали играта продължава да работи
    bool running;
    // Променлива за текущия кадър
    int currentFrame;

};
