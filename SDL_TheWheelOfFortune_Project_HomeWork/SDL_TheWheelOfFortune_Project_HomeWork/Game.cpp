//Game.cpp
#include "Game.h"
#include <iostream>



bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //прозорец инициализиране 
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //рендеринг инициализиране
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				// използвайте TextureManager за зареждане на текстури:
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

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // задава цвета на прозореца
	SDL_RenderClear(renderer);

		TextureManager::Instance()->drawRotation("wheel", 0, 100, 800, 800, renderer, rotationSpeed);
		// button "Spin"
		TextureManager::Instance()->drawTexture("spin", 620, 50, 150, 70, renderer);
		// arrow
		TextureManager::Instance()->drawTexture("arrow", 350, 20, 100, 70, renderer);

		int ww, wh;
		SDL_GetWindowSize(window, &ww, &wh); // присвоява ширината и височината на прозореца на ww и wh

		//удебелен правоъгълник около бутона
		SDL_Rect outlineRect = { 620, 50, 150, 70 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 1, 50 - 1, 152, 72 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 2, 50 - 2, 154, 74 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 3, 50 - 3, 156, 76 };
		SDL_RenderDrawRect(renderer, &outlineRect);




		SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) { // проверява за събитие
		int msx, msy;

		switch (event.type) {  //вид на събитието
		case SDL_QUIT: running = false; break; //затваряне на прозореца
		case SDL_MOUSEBUTTONDOWN: {   //натискане на бутон на мишката
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				std::cout << "Left mouse button is down\n";
				spinning = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				std::cout << "Right mouse button is down\n";
			}
		}; break;

		default: break;
		}
	}
}

void Game::update() {
	if (spinning) {
		rotationSpeed = 10;
		if (SDL_GetTicks() % 30 == 0) {
			rotationSpeed -= 1;
			std::cout << "rotaionspeed -= 2\n";
		}
		if (rotationSpeed <= 0) {
			rotationSpeed = 0;
			std::cout << "rotaionspeed = 0\n";

		}
	}
	
}



void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
bool Game::isRunning() {
	return running;
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
	SDL_GetWindowSize(window, &ww, &wh); //вземете размера на прозореца

	// координати на бутона
	int spinButtonX = 520;
	int spinButtonY = wh /2;
	// размер на бутон "Spin"
	int spinButtonW = 150;
	int spinButtonH = 70;


	if ((xDown > spinButtonX && xDown < (spinButtonX + spinButtonW)) && (xUp > spinButtonX && xUp < (spinButtonX + spinButtonW)) &&
		(yDown > spinButtonY&& yDown < (spinButtonX + spinButtonH)) && (yUp > spinButtonY && yUp < (spinButtonY + spinButtonH))){
		std::cout << "Spin button" << std::endl;
			return true; // button clicked
		}
	return false;
}
//int Game::getCurrentSector() const {
//
//	//  броя на секторите
//	int numSectors = sectors.size();
//
//	// Изчисляваме ъгъла на всяка секторна част, като разделяме 360 градуса на броя сектори.
//	float sectorAngle = 360.0f / numSectors;
//
//	// Изчисляваме текущия ъгъл на завъртане, като вземаме остатъка при деление на rotationAngle на 360.
//	float currentAngle = rotationAngle % 360;
//
//	// Ако текущият ъгъл е отрицателен, преобразуваме го в положителен.
//	if (currentAngle < 0) {
//		currentAngle += 360; // за отрицателни ъгли
//	}
//
//	// Изчисляваме индекса на сектора, към който принадлежи текущия ъгъл.
//
//	int sectorIndex = static_cast<int>(currentAngle / sectorAngle);
//	return sectorIndex;
//}


