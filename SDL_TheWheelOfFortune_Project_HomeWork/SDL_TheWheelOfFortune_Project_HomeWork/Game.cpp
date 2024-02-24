﻿//Game.cpp
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
				TextureManager::Instance()->loadTexture("assets/spin2.png", "spin2", renderer);

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
bool Game::ttf_init() {
	if (TTF_Init() == -1) { // проверка дали инициализацията е успешна
		std::cout << "TTF_Init is false\n";
		return false;
	}

	TTF_Font* font = TTF_OpenFont("fonts/comic.ttf", 26); // отваря шрифт от файл с име и размер, връща указател към заредения шрифт
	if (font == NULL) { // проверка дали зареждането на шрифта е успешно
		std::cout << "Font is false\n";
		return false;
	}

	if (win) {
	
		//SDL_Surface* tempSurfaceText = NULL; // указател за съхранение на текста
		//tempSurfaceText = TTF_RenderText_Blended(font, "You win: ", { 0, 0, 255, 255 }); //за да се рендира текста
		//textTextureFont = SDL_CreateTextureFromSurface(renderer, tempSurfaceText); //създаване на текстура

	std::string winningsText = "You win: " + std::to_string(price);
	SDL_Surface* tempSurfaceText = TTF_RenderText_Blended(font, winningsText.c_str(), { 0, 0, 255, 255 });
	textTextureFont = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

		int tw, th; // променливи за съхранение на ширина и височина
		SDL_QueryTexture(textTextureFont, 0, 0, &tw, &th); //извличане  ширина и височина
		dRectFont = { 20, 20, tw,th };  // структора с парамеетри

		//SDL_FreeSurface(tempSurfaceText); //освобождава паметта
		TTF_CloseFont(font); //затваря текста
		return true; // Връщаме true, за да покажем, че инициализацията е успешна

		
	
	}
	else {
		win = false;
	}
	return false; // Връщаме false, ако spinning не е false
}

void Game::render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // задава цвета на прозореца
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, textTextureFont, NULL, &dRectFont);

		TextureManager::Instance()->drawRotation("wheel", 50, 100, 800, 800, renderer, rotationSpeed);
		// button "Spin"
		TextureManager::Instance()->drawTexture("spin", 620, 25, 150, 70, renderer);
		if (!spinButtonActive) {                    //Флаг покозващ дали бутонае активен
			TextureManager::Instance()->drawTexture("spin2", 620, 25, 150, 70, renderer);
		}
		// arrow
		TextureManager::Instance()->drawTexture("arrow", 400, 20, 100, 70, renderer);

		int ww, wh;
		SDL_GetWindowSize(window, &ww, &wh);           // присвоява ширината и височината на прозореца на ww и wh

		//удебелен правоъгълник около бутона
		SDL_Rect outlineRect = { 620, 25, 150, 70 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 1, 25 - 1, 152, 72 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 2, 25 - 2, 154, 74 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 620 - 3, 25 - 3, 156, 76 };
		SDL_RenderDrawRect(renderer, &outlineRect);

		SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {                         // проверява за събитие
		int msx, msy;

		switch (event.type) {                           //вид на събитието
		case SDL_QUIT: running = false; break;          //затваряне на прозореца

		case SDL_MOUSEBUTTONDOWN: {                     //натискане на бутон на мишката

			if (event.button.button == SDL_BUTTON_LEFT) {

				SDL_GetMouseState(&msx, &msy);
				mouseDownX = msx;                          // кординати на мишката
				mouseDownY = msy;                         
				std::cout << "Left mouse button is down\n";
				bool isButtonClicked = isClickableButton(clickableTexture, &clickableRect, mouseDownX, mouseDownY, msx, msy);
				if (isButtonClicked && spinButtonActive && win ) {  // ако бутона на мишката е натиснат и бутона "Spin" e активен 
					std::cout << "CLICKED SPIN\n";
					spinning = true;                       // Флаг показващ дали колелото се върти
					rotationSpeed = 10;                    // Скорост на въртене на колелото
					spinButtonActive = false;              //Флаг покозващ дали бутона е активен
				}
				if (rotationSpeed <= 0) {
					spinButtonActive = true;               //Флаг покозващ дали бутона е активен
					std::cout << "spinButtonActive TRUE\n";
				}
				if (isButtonClicked && spinButtonActive) {  //ако бутона е натиснат, колелото се завърта
					std::cout << "CLICKED SPIN\n";
					spinning = true;                        // Флаг показващ дали колелото се върти
					rotationSpeed = 10;                     //  Скорост на въртене на колелот

					spinButtonActive = false;               //Флаг покозващ дали бутона е активен
					win = false;
					ttf_init();

					if (isButtonClicked && spinButtonActive) {  // ако бутона на мишката е натиснат и бутона "Spin" e активен 
						spinButtonActive = false;           //Флаг покозващ дали бутона е активен
					}
				}
			}; break;
		default: break;
		}
		}

	}
}
std::pair<float, float> Game::getCircleCoordinates(double markerX, double markerY, double centerX, double centerY, double sideLength) {
	const double angleIncrement = 24 / 2 * M_PI ; // Ъгълът между върховете на окръжността

	//// Изчисляване на ъгъла на маркера спрямо центъра на окръжността
	//double angleToMarker = atan2(markerY - centerY, markerX - centerX);
	float angleToMarker = atan2(x, y) * (180 / M_PI);
	if (angleToMarker <= 0) {
		angleToMarker += 360; // Осигуряване, че ъгълът е в положителен диапазон [0, 2π)
	}

	// Изчисляване на индекса на върха, на който се намира маркера
	int vertexIndex = (angleToMarker / angleIncrement) +1;

	// Изчисляване на координатите на върха
	float angle = vertexIndex * angleIncrement;


	float x = centerX + sideLength * cos(angle - M_PI / 2);
	float y = centerY + sideLength * sin(angle - M_PI / 2);


	return std::make_pair(x, y);
}
int Game::getSectorValue(float x, float y) {
	if (x >= 0 && y <= 7.5) {
		return  0;  // BANKRUPT
	}
	else if (x >= 8 && y <= 22.5) {
		return  1500;
	}
	else if (x >= 23 && y <= 37.5) {
		return  200;
	}
	else if (x >= 38 && y <= 52.5) {
		return  850;
	}
	else if (x >= 53 && y <= 67.5) {
		return  400;
	}
	else if (x >= 68 && y <= 82.5) {
		return  100000;  // Jackpot
	}
	else if (x >= 83 && y <= 97.5) {
		return  150;
	}
	else if (x >= 98 && y <= 112.5) {
		return  500;
	}
	else if (x >= 113 && y <= 127.5) {
		return  900;
	}
	else if (x >= 128 && y <= 142.5) {
		return  350;
	}
	else if (x >= 143 && y <= 157.5) {
		return  0;// lose a turn 
	}
	else if (x >= 158 && y <= 172.5) {
		return 200;
	}
	else if (x >= 173 && y <= 187.5) {
		return  175;
	}
	else if (x >= 188 && y <= 202.5) {
		return  5000;
	}
	else if (x >= 203 && y <= 217.5) {
		return  0;// BANKRUPT
	}
	else if (x >= 218 && y <= 232.5) {
		return  250;
	}
	else if (x >= 233 && y <= 247.5) {
		return  600;
	}
	else if (x >= 248 && y <= 262.5) {
		return  5000;// SURPRISE
	}
	else if (x >= 263 && y <= 277.5) {
		return  800;
	}
	else if (x >= 278 && y <= 292.5) {
		return  550;
	}
	else if (x >= 293 && y <= 307.5) {
		return  1000;
	}
	else if (x >= 308 && y <= 322.5) {
		return  100;
	}
	else if (x >= 323 && y <= 337.5) {
		return  300;
	}
	else if (x >= 338 && y <= 352.5) {
		return  750;
	}
	else if (x >= 353 && y <= 360) {
		return 0;    //BANKRUPT
	}
	else {
		return -1;
	}
}



void Game::update() {	
	if (spinning){
		spinButtonActive = false;

		if (SDL_GetTicks() % 30 == 0) {
			rotationSpeed -= 2;
		}
		if (rotationSpeed <= 0) {
			rotationSpeed = 0;
			spinButtonActive = true;
			spinning = false;


			double markerX = 400;  // Примерни координати на маркера
			double markerY = 20;
			double centerX = 900/2;  // Примерни координати на центъра на окръжността
			double centerY = 850/2;
			double sideLength = 800/2; // Примерна дължина на страна на окръжността

			auto result = Game::getCircleCoordinates(markerX, markerY, centerX, centerY, sideLength);
			std::cout << "Coordinates of the marker on the circle: (" << result.first << ", " << result.second << ")\n";
			std::cout <<markerX<< ":" << markerY<< ":" << centerX << ":" << centerY << ":" << sideLength << std::endl;

			int sectorValue = Game::getSectorValue(result.first, result.second);
			if (sectorValue != -1) {
				std::cout << "Sector value: " << sectorValue << std::endl;
			}
			else {
				std::cout << "Invalid sector!" << std::endl;
			}

			std::cout << "You win: " << price << std::endl;
			win = true;
			ttf_init();

			std::cout << x << ":" << y << std::endl;

 		}
	}
}

bool Game::isClickableButton(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp) {

	// координати на бутона
	int spinButtonX = 620;
	int spinButtonY = 25;
	// размер на бутон "Spin"
	int spinButtonW = 150;
	int spinButtonH = 70;


	// проверява парамети на бутона	
	if ((xDown > spinButtonX && xDown < (spinButtonX + spinButtonW)) &&// ako xDown > 620 && xDown < 620 + 150
		(yDown > spinButtonY && yDown < (spinButtonY + spinButtonH))) { // ako yDown > 50 && yDown < 620 + 70
		std::cout << "Spin button clicked" << std::endl;
		return true; // button clicked
	}
	return false;
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
	markerX = markerY = 23;

}
Game::~Game() {

}












