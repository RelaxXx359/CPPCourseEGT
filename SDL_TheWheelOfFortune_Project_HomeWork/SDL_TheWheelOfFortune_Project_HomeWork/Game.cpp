//Game.cpp
#include "Game.h"
#include <iostream>


int speed = 1;

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

				// use the TextureManager to load textures:
				TextureManager::Instance()->loadTexture("assets/wheel.png", "wheel", renderer);
				TextureManager::Instance()->loadTexture("assets/spin.png", "spin", renderer);
				TextureManager::Instance()->loadTexture("assets/arrow2.png", "arrow", renderer);

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

		// animates the sprite sheet with the help of the update() function


	//SDL_RenderCopyEx(ren, textureMap[id], nullptr, &srcRect, angle, &center, SDL_FLIP_NONE);
	//SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);

		TextureManager::Instance()->drawRotation("wheel", 0, 100, 800, 800, renderer, frameFlip);
		//std::string id, int x, int y, int width, int height, SDL_Renderer* ren, int rotationSpeed

		// button "Spin"
		TextureManager::Instance()->drawTexture("spin", 620, 50, 150, 70, renderer);
		// arrow
		TextureManager::Instance()->drawTexture("arrow", 350, 20, 100, 70, renderer);




		int ww, wh;
		SDL_GetWindowSize(window, &ww, &wh); // assigns the window's width and height to ww and wh

		SDL_Rect outlineRect = { 620, 50, 150, 70 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 1, 50 - 1, 152, 72 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 2, 50 - 2, 154, 74 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 3, 50 - 3, 156, 76 };
		SDL_RenderDrawRect(renderer, &outlineRect);

		// NOTICE: the textures rendered later overlap the previosly rendered textures

		//SDL_RenderCopy(renderer, textTextureText, NULL, &dRectText);


		SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		int msx, msy;

		switch (event.type) {
		case SDL_QUIT: running = false; break;
		case SDL_MOUSEBUTTONDOWN: {

			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
			
				Game::mouseDownX = msx;
				Game::mouseDownY = msy;
				std::cout << "Left mouse button is down\n";
				anim_state = true;
				frameFlip = SDL_FLIP_HORIZONTAL;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				std::cout << "Right mouse button is down\n";
			}
		}; break;
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				Game::isClickableButton(mouseDownX, mouseDownY, msx, msy);
				std::cout << "Left mouse button is up\n";
				anim_state = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				std::cout << "Right mouse button is up\n";

			}
		}
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

}
bool Game::isClickableButton(int xDown, int yDown, int xUp, int yUp) {
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); // get window size

	// button coordinates
	int spinButtonX = 520;
	int spinButtonY = wh /2;
	// size button
	int spinButtonW = 150;
	int spinButtonH = 70;


	if ((xDown > spinButtonX && xDown < (spinButtonX + spinButtonW)) && (xUp > spinButtonX && xUp < (spinButtonX + spinButtonW)) &&
		(yDown > spinButtonY&& yDown < (spinButtonX + spinButtonH)) && (yUp > spinButtonY && yUp < (spinButtonY + spinButtonH))){
		std::cout << "Spin button" << std::endl;

			return true; // бутона е бил кликнат
		}
	return false;
}