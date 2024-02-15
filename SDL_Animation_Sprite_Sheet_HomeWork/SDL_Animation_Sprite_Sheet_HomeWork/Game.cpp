//Game.cpp
#include "Game.h"
#include <iostream>

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

				// use the TextureManager to load textures
				TextureManager::Instance()->loadTexture("assets/bmp2.bmp", "bmp", renderer);
				TextureManager::Instance()->loadTexture("assets/SpriteEntity.png", "sprite_sheet", renderer);

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
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets the window bg color needs to sit before SDL_RenderClear()
	SDL_RenderClear(renderer);
	
	
	// animates the sprite sheet with the help of the update() function
	TextureManager::Instance()->drawOneFrameFromTexture("sprite_sheet", 200, 150, 90, 130, 1, currentFrame, renderer, frameFlip);


	

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: {
				if (event.key.keysym.sym == SDLK_RIGHT) {
					anim_state = true;
					frameFlip = SDL_FLIP_NONE;
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					anim_state = true;
					frameFlip = SDL_FLIP_HORIZONTAL;
				}
			}; break;
		/*	case SDL_KEYUP: {
				if (event.key.keysym.sym == SDLK_RIGHT) {
					anim_state = false;
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					anim_state = false;
				}
			}; break;*/
			default: break;
		}
	}
}

void Game::update() {
	
	//Logs the different stages of 'currentFrame' formula,
	//if you have trouble understanding how it works try uncommenting the couts and study the output 
	//std::cout << "SDL_TICKS           :" << SDL_GetTicks() << "\n";
	//std::cout << "SDL_TICKS / 100     :" << int(SDL_GetTicks() / 100) << "\n";
	//std::cout << "SDL_TICKS / 100 % 10:" << int(((SDL_GetTicks() / 100) % 10)) << "\n\n";
	
	
	if (anim_state) {
		int numberOfFramesInSpriteSheet = 10;
		int animationSpeed = 100; // lower is faster, min = 1
		currentFrame = int(((SDL_GetTicks() / animationSpeed) % numberOfFramesInSpriteSheet));
	}

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