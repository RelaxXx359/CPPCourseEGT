//main.cpp
#include "Game.h"
#include <iostream>

Game* game = NULL;  // декларира променливата game като указател към Game 

// ширина и височина на прозореца
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 900;


int main(int argc, char* argv[]) {

	game = new Game();

	// инициализация на играта
	game->init("My new window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE);
	//функция за зареждане на текста
	game->ttf_init();  


	// регулиране на скоростта на визуализация 
	const int FPS = 30;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	while (game->isRunning()) {  // безкраен цикъл, докато играта е активна
		frameStart = SDL_GetTicks();  // продължителност на кадъра
		game->handleEvents();  // функция за движеение на мишката
		game->update();  // функция за актутализиране на играта
		game->render();  // функция за визоализация

		// изминато време от началото до момента
		frameTime = SDL_GetTicks() - frameStart;

		//проверява дали времето за забавяне между кадрите (frameDelay) е по-голямо от времето,
		//  което е изминало от началото на текущия кадър	
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
	}

	}
	game->clean();  	// почистване на ресурсите

	return 0;
}