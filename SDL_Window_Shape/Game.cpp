
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

                // зарежда картинка
                //TextureManager::Instance()->loadTexture("assets/bmp.bmp", "bmp", renderer);
                //TextureManager::Instance()->loadTexture("assets/pikachu.png", "png", renderer);
                TextureManager::Instance()->loadTexture("assets/sprite_sheet.jpeg", "jpg", renderer);


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
        std::cout << "SDL init failed\n";
        return false;
    }
    std::cout << "init success\n";
    running = true;
    return true;
}

//
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //  пълен червен триъгълник
    int ww, wh;
    SDL_GetWindowSize(window, &ww, &wh);
    SDL_Rect fillRect = { ww / 4, wh / 4, ww / 2, wh / 2 };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);

    // празен триъгълник в центъра в зелено
    SDL_Rect outlineRect = { ww / 6, wh / 6, ww * 2 / 3, wh * 2 / 3 };
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderDrawRect(renderer, &outlineRect);

    //  линия посредада на прозореца
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

    // черна прекъсната линия
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
    for (size_t i = 0; i < wh; i+=4){
        SDL_RenderDrawPoint(renderer, ww / 2, i);
    }

    // мъничка точка в горен десен ъгъл
    SDL_Point p ={10,20};
    SDL_RenderDrawPoint(renderer, p.x, p.y);



    // направихме header и cpp за да илюстрираме кръг
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    Shapes::drawCircle(renderer, ww / 2, wh / 2, 250);


  /*  TextureManager::Instance()->drawOneFrameFromeTexture("jpg", 0, 0, 130, 130, 1, currentFrame, renderer);
    TextureManager::Instance()->drawOneFrameFromeTexture("jpg", 0, 130, 130, 130, 2, currentFrame, renderer);*/


    //TextureManager::Instance()->drawTexture("png", 0, 0, 204, 200, renderer);
    //TextureManager::Instance()->drawTexture("png", 200, 200, 204, 200, renderer, SDL_FLIP_HORIZONTAL);



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

    //std::cout << "SDL_TICKS           :" << SDL_GetTicks() << "\n";
    //std::cout << "SDL_TICKS / 100     :" << int(SDL_GetTicks() / 100) << "\n";
    //std::cout << "SDL_TICKS / 100 % 10: " << int(((SDL_GetTicks() / 100) % 10)) << "\n\n";

    //
    //currentFrame = int(((SDL_GetTicks() / 200) % 5));  // % 10 for 10 frames

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
    Game::currentFrame = 0;
}

Game::~Game() {
}