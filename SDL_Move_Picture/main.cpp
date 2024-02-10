#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
using namespace std;

Game* game = NULL;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGTH = 600;

const int FPS = 30;
void limitFPS(Uint32 startingTick) {
	if ((1000 / FPS) > SDL_GetTicks() - startingTick)
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startingTick));
}
int main(int argc, char* argv[]) {

	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL;*/
	//window = SDL_CreateWindow("My picture",


	game = new Game();
	game->init("My picture",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGTH,
		SDL_WINDOW_RESIZABLE);

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	SDL_Event event;
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
		limitFPS(SDL_GetTicks());
	}
	Uint32 startingTick;


	//SDL_DestroyWindow(window);
	//SDL_Quit();




	return 0;
}