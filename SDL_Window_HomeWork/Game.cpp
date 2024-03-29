#include "Game.h"
#include <iostream>
int c = 0;
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window != 0) //window init success
        {
            std::cout << "window creation success\n";
            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer != 0) //renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


                // ADD PICTURE TO WINDOW
                SDL_Surface* tempSurface = SDL_LoadBMP("assets/bmp.bmp");
                texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
                SDL_FreeSurface(tempSurface);

                SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);

                destinationRectangle.x = sourceRectangle.x = 0;
                destinationRectangle.y = sourceRectangle.y = 0;

                destinationRectangle.h = sourceRectangle.h;
                destinationRectangle.w = sourceRectangle.w;

            }
            else {
                std::cout << "renderer init failed\n";
                return false;
            }
        }
        else {
            std::cout << "window init failed\n";
            return false;
        }
    }
    else {
        std::cout << "SDL init fail\n";
        return false;
    }
    std::cout << "init success\n";
    running = true;
    return true;
}

//
void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);
    //SDL_RenderCopy(renderer, texture, NULL, NULL);

    SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    c++;
    if (c % 50 == 0)
        destinationRectangle.x++;
}

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return Game::running;
}
Game::Game() {
    Game::window = NULL;
    Game::renderer = NULL;
    Game::running = true;
    Game::sourceRectangle.x = Game::sourceRectangle.y = Game::sourceRectangle.w = Game::sourceRectangle.h = 0;
    Game::destinationRectangle.x = Game::destinationRectangle.y = Game::destinationRectangle.w = Game::destinationRectangle.h = 0;
}

Game::~Game() {
}