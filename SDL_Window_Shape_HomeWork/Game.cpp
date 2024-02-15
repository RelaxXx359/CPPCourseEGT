
#include "Game.h"
#include <iostream>
#include "Shapes.h"

//метод се извиква за инициализиране на играта
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

    // Създаване на прозорец
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        // Проверка за успешно създаване на прозореца
        if (window != 0) //window init success
        {
            std::cout << "window creation success\n";

            // Създаване на изображение
            renderer = SDL_CreateRenderer(window, -1, 0);

            // Проверка за успешно създаване на рендерера
            if (renderer != 0) //renderer init success
            {
                std::cout << "renderer creation success\n";
                // Задаване на цвета на фона

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
 

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

//изображение
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

    //празен правоъгълник с подадена дебелина на линиите
    // направих го с четири триъгълника с еднакъв цвят и различни параметри 
    SDL_GetWindowSize(window, &ww, &wh);
    SDL_Rect fillRect1 = { 10,  10, 20 , 100 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect1);

    SDL_GetWindowSize(window, &ww, &wh);
    SDL_Rect fillRect2 = { 10,10, 150 , 20 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect2);

    SDL_GetWindowSize(window, &ww, &wh);
    SDL_Rect fillRect3 = { 10, 100, 150 , 20 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect3);

    SDL_GetWindowSize(window, &ww, &wh);
    SDL_Rect fillRect4 = { 150, 10, 20 , 110 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect4);





    // мъничка точка в горен десен ъгъл
    SDL_Point p ={10,20};
    SDL_RenderDrawPoint(renderer, p.x, p.y);



    // направихме header и cpp за да илюстрираме кръг
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    Shapes::drawCircle(renderer, ww / 2, wh / 2, 250);

    // илюстрирах петоъгълник в черно
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 250);
    Shapes::drawPentagon(renderer, ww / 2, wh / 2, 100);


    // илюстрирах шестоъгълник в сиво
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 250);
    Shapes::drawHexagon(renderer, ww / 2, wh / 2, 200);





    SDL_RenderPresent(renderer);
}


// обработка на интерфейс
void Game::handleEvents() {
    SDL_Event event;  // Създаване на обект за събитие

    // Проверка за наличие на събития в опашката
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:  // Ако събитието е затваряне на прозореца
            running = false;  // Установяване на флага running на false
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
    SDL_DestroyRenderer(renderer); // Унищожаване на изображението
    SDL_DestroyWindow(window); // Унищожаване на прозореца
    SDL_Quit(); // Затваряне на SDL

    // Обикновено тук се освобождават и други ресурси, ако са заделени

}

bool Game::isRunning() {
    return Game::running;
}

// конструктор на клас Game
Game::Game() {
    window = nullptr; // Инициализация на указателя към прозореца
    renderer = nullptr; // Инициализация на указателя към рендерера
    running = true; // Задаване на флага running на true (играта започва да работи)
    currentFrame = 0; // Задаване на текущия кадър на 0
}
// диструктор на класа
Game::~Game() {
}