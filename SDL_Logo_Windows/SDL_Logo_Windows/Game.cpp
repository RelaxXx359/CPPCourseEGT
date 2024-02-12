#include "Game.h"
#include <iostream>
#include "TextureManager.h"
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
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x66, 255);




				TextureManager::Instance()->loadTexture("assets/picture1.jpg", "jpg1", renderer);
				TextureManager::Instance()->loadTexture("assets/picture2.jpg", "jpg2", renderer);
				TextureManager::Instance()->loadTexture("assets/picture3.jpg", "jpg3", renderer);
				TextureManager::Instance()->loadTexture("assets/picture4.jpg", "jpg4", renderer);

			  
				//зареждане на изображение
				//SDL_Surface* tempSurface =IMG_Load("assets/picture1.jpg");
				//SDL_Surface* tempSurface = IMG_Load("assets/picture2.jpg");

				//texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
				//SDL_FreeSurface(tempSurface);
				//SDL_QueryTexture(texture, NULL, NULL, &imageRectangle.w, &imageRectangle.h);

				//windowRectangle.x = imageRectangle.x = 0;
				//windowRectangle.y = imageRectangle.y = 0;
				//windowRectangle.h = imageRectangle.h;
				//windowRectangle.w = imageRectangle.w;
				//

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

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x66, 255);

	SDL_RenderClear(renderer);
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
	SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
	SDL_RenderDrawLine(renderer,ww /2,  0, ww / 2 , wh);

	//SDL_RenderCopy(renderer, texture, &imageRectangle, &windowRectangle);
	//TextureManager::Instance()->drawOneFrameTexture("jpg", 0, 130, 130, 130, 2, currentFrame, renderer);
	TextureManager::Instance()->drawTexture("jpg1", -1, -1, 400, 300, renderer, SDL_FLIP_HORIZONTAL);
	TextureManager::Instance()->drawTexture("jpg2", 401, -1, 400, 300, renderer, SDL_FLIP_HORIZONTAL);
	TextureManager::Instance()->drawTexture("jpg3", -1, 300, 400, 300, renderer, SDL_FLIP_HORIZONTAL);
	TextureManager::Instance()->drawTexture("jpg4", 400, 300, 400, 300, renderer, SDL_FLIP_HORIZONTAL);




	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;
		case SDL_MOUSEBUTTONDOWN: {
			std::cout << "mouse button down\n";
			if (event.button.button == SDL_BUTTON_LEFT) {
				std::cout << "button left\n";


			}

		}; break;
		default: break;

		}

	}
}

void Game::update() {

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
}

Game::~Game() {
	delete window;
	delete renderer;
}