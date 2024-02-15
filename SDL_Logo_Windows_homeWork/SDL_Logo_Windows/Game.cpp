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
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);




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

enum Quadrant { jpg1 = 0, jpg2 = 1, jpg3 = 10, jpg4 = 11, UNDEFINED = 100 };

Quadrant mouseDownIn = UNDEFINED; // indicates which quadrant the L or R mouse button was pressed down
Quadrant mouseDownOut = UNDEFINED; // indicates which quadrant the L mouse was released up

// Texture positions for the moustache texture
int texPosX, texPosY = 0;

// texture dimensions;  down-scaling not implemented - must be the size of the image or higher
int w = 100; int h = 60;


void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0xFF);
	SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0xFF);
	SDL_RenderDrawLine(renderer, ww / 2, 0, ww / 2, wh);

	//SDL_RenderCopy(renderer, texture, &imageRectangle, &windowRectangle);
	//TextureManager::Instance()->drawOneFrameTexture("jpg", 0, 130, 130, 130, 2, currentFrame, renderer);
	TextureManager::Instance()->drawTexture("jpg1", 0, 0, 400, 300, renderer);
	TextureManager::Instance()->drawTexture("jpg2", 401, 0, 400, 300, renderer);
	TextureManager::Instance()->drawTexture("jpg3", 0, 301, 400, 300, renderer);
	TextureManager::Instance()->drawTexture("jpg4", 401, 301, 400, 300, renderer);

	//int angle = 0; // texture's rotation angle
	//switch (mouseDownIn) { //chek where Right mouse clicked
	//case jpg1: {angle = 350; } break;
	//case jpg2: {angle = 100; } break;
	//case jpg3: {angle = 5; } break;
	//case jpg4: {angle = 45; } break;
	//default: break;
	//}

	// let's use references to global variables to update this texture position
	int& tPosX = texPosX;
	int& tPosY = texPosY;

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	

	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		int mouseX, mouseY, ww, wh;
		SDL_GetWindowSize(window, &ww, &wh); //get window's width and height

		switch (event.type) {
		case SDL_QUIT: running = false; break;


		case SDL_MOUSEBUTTONDOWN: {
			SDL_GetMouseState(&mouseX, &mouseY);
			if (event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT) {
				if (mouseX > ww / 2) {
					if (mouseY > wh / 2) {
						mouseDownIn = jpg1; // Bottom-right quadrant
					}
					else {
						mouseDownIn = jpg2; // Top-right quadrant
					}
				}
				else {
					if (mouseY > wh / 2) {
						mouseDownIn = jpg3; // Bottom-left quadrant
					}
					else {
						mouseDownIn = jpg4; // Top-left quadrant
					}
				}
			}

		}; break;
		case SDL_MOUSEBUTTONUP: {
			/*Get quadrant on mouse up - to ensure the mouse stayed in the same quadrant*/
			SDL_GetMouseState(&mouseX, &mouseY);// get mouse position
			if (event.button.button == SDL_BUTTON_LEFT) {
				std::cout << "button left\n";
				switch (((mouseX > ww / 2) + (mouseY > wh / 2) * 10)) {
				case 0: {
					mouseDownOut = jpg1;
					if (mouseDownIn == mouseDownOut) {
						TextureManager::Instance()->changeTexture("jpg1"); //toggle visibility
					}
				}; break;
				case 1: {
					mouseDownOut = jpg2;
					if (mouseDownIn == mouseDownOut) {
						TextureManager::Instance()->changeTexture("jpg2"); //toggle visibility
					}
				} break;
				case 10: {
					mouseDownOut = jpg3;
					if (mouseDownIn == mouseDownOut) {
						TextureManager::Instance()->changeTexture("jpg3"); //toggle visibility
					}
				} break;
				case 11: {
					mouseDownOut = jpg4;
					if (mouseDownIn == mouseDownOut) {
						TextureManager::Instance()->changeTexture("jpg4"); //toggle visibility
					}
				} break;
				default: break;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				std::cout << "button right\n";

				// update global variables using references
				int& tPosX = texPosX; int& tPosY = texPosY;
				tPosX = mouseX - w / 2;
				tPosY = mouseY - h / 2;
			}
		}; break;
		case SDL_KEYDOWN: {
			// update global variables using references
			int& tPosX = texPosX; int& tPosY = texPosY;
			if (event.key.keysym.sym == SDLK_UP)
				tPosY -= 5;
			if (event.key.keysym.sym == SDLK_DOWN)
				tPosY += 5;
			if (event.key.keysym.sym == SDLK_LEFT)
				tPosX -= 5;
			if (event.key.keysym.sym == SDLK_RIGHT)
				tPosX += 5;
		} break;
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
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 0; //frames start form 0
	Game::currentRow = 1; //rows start from 1
}