//main.cpp
#include "Game.h"
#include <iostream>

Game* game = NULL;
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 900;


int main(int argc, char* argv[]) {

	game = new Game();
	game->init("My new window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE);
	//функция за зареждане на текста
	game->ttf_init();

	const int FPS = 30;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;



	while (game->isRunning()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
	}

	}
	game->clean();
	return 0;
}