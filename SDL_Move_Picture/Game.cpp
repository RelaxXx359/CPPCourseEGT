#include <iostream>
#include "Game.h"


int speed = 1;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	// Създаване на прозорец
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success!\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// Проверка за успешно създаване на прозореца
		if (window != 0) { // window init success
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);


			if (renderer != 0) {
				std::cout << "renderer create succes\n";
				// задаване на цвета на фона
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);


				// зарежда изображение
			   //TextureManager::Instance()->loadTexture("assets/bmp.bmp", "bmp", renderer);
			   //TextureManager::Instance()->loadTexture("assets/pikachu.png", "png", renderer);
			   //TextureManager::Instance()->loadTexture("assets/sprite_sheet.jpeg", "jpg", renderer);

				//зареждане на изобраце
				SDL_Surface* tempSurface = IMG_Load("assets/pikachu.png");
				//SDL_Surface* tempSurface = IMG_Load("assets/bmp.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
				SDL_FreeSurface(tempSurface);
				SDL_QueryTexture(texture, NULL, NULL, &imageRectangle.w, &imageRectangle.h);

				windowRectangle.x = imageRectangle.x = 0;
				windowRectangle.y = imageRectangle.y = 0;
				windowRectangle.h = imageRectangle.h;
				windowRectangle.w = imageRectangle.w;

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

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &imageRectangle, &windowRectangle);
	SDL_RenderPresent(renderer);

}
void Game::update() {
	int ww, wh; // Променливи за ширината и височината на прозореца
	SDL_GetWindowSize(window, &ww, &wh); // Вземане на размерите на прозореца

	// Центриране на обекта вертикално
	windowRectangle.y = (wh - windowRectangle.h) / 2;

	// Проверка дали е изминало определено време, за да преместим обекта
	if (SDL_GetTicks() % 40 == 0){
		windowRectangle.x += speed; // Преместване на обекта хоризонтално

		// Проверка дали обекта е достигнал дясната граница на прозореца
		if (windowRectangle.x >= (ww - windowRectangle.w)) {
			windowRectangle.x = ww - windowRectangle.w; // Коригиране на позицията на обекта
		 speed *= -1; // Промяна на посоката на движение
		}
		// Проверка дали обекта е достигнал лявата граница на прозореца
		if (windowRectangle.x <= 0) {
			windowRectangle.x = 0; // Коригиране на позицията на обекта
			speed *= -1; // Промяна на посоката на движение
			speed+=1; // Увеличаване на скоростта

		
		}
	}
}
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
void Game::clean() {

}
bool Game::isRunning() {
	return Game::running;
}
Game::Game() {
	window = NULL;
	renderer = NULL;
	running = true;
	currentFrame = 0; // Задаване на текущия кадър на 0

}
Game::~Game() {

}




