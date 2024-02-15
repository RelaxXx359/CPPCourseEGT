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
				TextureManager::Instance()->loadTexture("assets/pikachu", "png", renderer);
				//TextureManager::Instance()->loadTexture("assets/bmp2.bmp", "png", renderer);




				SDL_Surface* tempSurface = IMG_Load("assets/pikachu.png");
				texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
				SDL_FreeSurface(tempSurface);
				SDL_QueryTexture(texture, NULL, NULL, &imageRectangle.w, &imageRectangle.h);

				windowRectangle.x = imageRectangle.x = 0;
				windowRectangle.y = imageRectangle.y = 0;
				windowRectangle.h = imageRectangle.h;
				windowRectangle.w = imageRectangle.w;

				TextureManager::Instance()->loadTexture("assets/sprite_sheet_mm_tp", "sprite_sheet", renderer);

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

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets the window bg color needs to sit before SDL_RenderClear()
	SDL_RenderClear(renderer);

	// animates the sprite sheet with the help of the update() function
	//TextureManager::Instance()->drawTexture("png", 100, 100, 204, 200, renderer);
	SDL_RenderCopy(renderer, texture, &imageRectangle, &windowRectangle);


	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;


		case SDL_MOUSEBUTTONDOWN: {
			int msx, msy;
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				downMouseX = msx;
				downMouseY = msy;

			}
		}break;
		case SDL_MOUSEBUTTONUP: {
			int msx, msy;
			//cout << "Mouse button up\n";
			if (event.button.button = SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				std::cout << msx << ":" << msy << std::endl;
				//dRectFont.x = msx - 100;
				//dRectFont.y = msy - 100;

			}
		}break;
		case SDL_KEYDOWN: {
			if (event.key.keysym.sym == SDLK_RIGHT) {
				//anim_state = true;
				dRectFont.x += 10;
				std::cout << "Right + 10\n";
				//frameFlip = SDL_FLIP_NONE;
			}
			if (event.key.keysym.sym == SDLK_LEFT) {
				//anim_state = true;
				dRectFont.x -= 10;
				std::cout << "Left -10\n";

				//frameFlip = SDL_FLIP_HORIZONTAL;
			}
			if (event.key.keysym.sym == SDLK_UP) {
				//anim_state = true;
				dRectFont.y -= 10;
				std::cout << "Up -10\n";

				//frameFlip = SDL_FLIP_NONE;
			}
			if (event.key.keysym.sym == SDLK_DOWN) {
				//anim_state = true;
				dRectFont.y += 10;
				std::cout << "Down +10\n";


				//frameFlip = SDL_FLIP_VERTICAL;
			}
		}; break;
		/*case SDL_KEYUP: {
			if (event.key.keysym.sym == SDLK_RIGHT || SDLK_UP || SDLK_DOWN || SDLK_LEFT) {
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

	//if (anim_state) {
	//	int numberOfFramesInSpriteSheet = 10;
	//	int animationSpeed = 50; // lower is faster, min = 1
	//	currentFrame = int(((SDL_GetTicks() / animationSpeed) % numberOfFramesInSpriteSheet));
	//}
	
	int ww, wh; // Променливи за ширината и височината на прозореца
	SDL_GetWindowSize(window, &ww, &wh); // Вземане на размерите на прозореца

	// Центриране на обекта вертикално
	windowRectangle.x = ww / 2.5;
	windowRectangle.y = wh / 3;




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