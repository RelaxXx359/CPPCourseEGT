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
				TextureManager::Instance()->loadTexture("assets/wheel.png", "sprite_sheet", renderer);

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
//bool Game::ttf_init() {
//	if (TTF_Init() == -1) {
//		return false;
//	}
//	TTF_Font* font1 = TTF_OpenFont("fonts/Arcade.ttf.ttf", 48);
//	if (font1 == NULL) {
//		return false;
//	}
//
//	SDL_Surface* tempSurfaceText = NULL;
//	tempSurfaceText = TTF_RenderText_Blended(font1, "Spin", { 0,0,255,255 });
//	textTextureText = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);
//
//	int tw, th;
//	SDL_QueryTexture(textTextureText, 0, 0, &tw, &th);
//	dRectText = { 10,10,tw,th };
//
//	SDL_FreeSurface(tempSurfaceText);
//	TTF_CloseFont(font1);
//	return true;
//}

//bool Game::isClickableTextureClicked(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp) {
//	int tw, th;
//	SDL_QueryTexture(t, 0, 0, &tw, &th);
//
//	if ((xDown > r->x && xDown < (r->x + tw)) && (xUp > r->x && xUp < (r->x + tw)) &&
//		(yDown > r->y && yDown < (r->y + th)) && (yUp > r->y && yUp < (r->y + th))) {
//		return true;
//	}
//	return false;
//}

void Game::render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets the window bg color needs to sit before SDL_RenderClear()
	SDL_RenderClear(renderer);

	//int ww, wh;
	//SDL_GetWindowSize(window, &ww, &wh); // assigns the window's width and height to ww and wh
	//SDL_Rect fillRect = {ww / 4, wh / 4, ww / 2, wh / 2};
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(renderer, &fillRect);

	//SDL_Rect outlineRect = { ww / 6, wh / 6, ww * 2 / 3, wh * 2 / 3 };
	//SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	//SDL_RenderDrawRect(renderer, &outlineRect);

	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	//SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF); // renders dashed line
	//for (int i = 0; i < wh; i += 4) {
	//	SDL_RenderDrawPoint(renderer, ww / 2, i);
	//}

	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	//Shapes::drawCircle(renderer, ww / 4, wh / 4, wh / 4 );

	
	



		// animates the sprite sheet with the help of the update() function
		TextureManager::Instance()->drawOneFrameFromTexture("sprite_sheet", 0, 100, 770, 770, 1, currentFrame, renderer, frameFlip);


		int ww, wh;
		SDL_GetWindowSize(window, &ww, &wh); // assigns the window's width and height to ww and wh

		SDL_Rect outlineRect = { 720, 50, 150, 70 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 720 - 1, 50 - 1, 152, 72 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 720 - 2, 50 - 2, 154, 74 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 720 - 3, 50 - 3, 156, 76 };
		SDL_RenderDrawRect(renderer, &outlineRect);

		// NOTICE: the textures rendered later overlap the previosly rendered textures

		SDL_RenderCopy(renderer, textTextureText, NULL, &dRectText);

		SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;
		case SDL_MOUSEBUTTONDOWN: {
			//if (event.button.button == SDL_BUTTON_LEFT) {
			//	std::cout << "button left\n";
			//	anim_state = true;
			//	//frameFlip = SDL_FLIP_NONE;
			//}
			int msx , msy;
			std::cout << "mouse button Down\n";

			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				anim_state = true;
				std::cout << msx << ":" << msy << std::endl;
			}
		}; break;
		case SDL_MOUSEBUTTONUP: {
			std::cout << "mouse button UP\n";

			if (event.button.button == SDL_BUTTON_LEFT) {
				anim_state = false;
			}
	
		}; break;
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