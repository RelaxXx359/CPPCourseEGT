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
				TextureManager::Instance()->loadTexture("assets/Confetti.png", "confetti", renderer);


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
		SDL_Surface* tempSurfaceText = NULL; // указател за съхранение на текста
		tempSurfaceText = TTF_RenderText_Blended(font, "You win: ", { 0, 0, 255, 255 }); //за да се рендира текста
		textTextureFont = SDL_CreateTextureFromSurface(renderer, tempSurfaceText); //създаване на текстура


		int tw, th; // променливи за съхранение на ширина и височина
		SDL_QueryTexture(textTextureFont, 0, 0, &tw, &th); //извличане  ширина и височина
		dRectFont = { 20, 20, tw,th };  // структора с парамеетри


		//SDL_FreeSurface(tempSurfaceText); //освобождава паметта
		TTF_CloseFont(font); //затваря текста
		return true; // Връщаме true, за да покажем, че инициализацията е успешна

		
	
	}
	return false; // Връщаме false, ако spinning не е false
}

void Game::render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // задава цвета на прозореца
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, textTextureFont, NULL, &dRectFont);

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
				mouseDownX = msx;
				mouseDownY = msy;
				std::cout << "Left mouse button is down\n";
				bool isButtonClicked = isClickableButton(clickableTexture, &clickableRect, mouseDownX, mouseDownY, msx, msy);
				if (isButtonClicked && spinButtonActive) {  //ако бутона е натиснат, колелото се завърта
					std::cout << "CLICKED SPIN\n";
					spinning = true;
					rotationSpeed = 10;
					spinButtonActive = false;
				}
				if (rotationSpeed <= 0) {
					
					spinButtonActive = true;
				}
				if (isButtonClicked && spinButtonActive) {  //ако бутона е натиснат, колелото се завърта
					std::cout << "CLICKED SPIN\n";
					spinning = true;
					rotationSpeed = 10;
					spinButtonActive = false;
				}
				
			
			}; break;

		default: break;
		}
		}

	}
}


void Game::update() {	
	if (spinning){

		if (SDL_GetTicks() % 40 == 0) {
			rotationSpeed -= 4;
		}
		if (rotationSpeed <= 0) {
			rotationSpeed = 0;
			win = true;
			ttf_init();
			float getCircleCoordinates(double centerX, double centerY, double sideLength);
			std::cout << "You win: " << price << std::endl;
			spinning = false;
		}
		if (rotationSpeed > 1) {
			win = false;

		}


		
			//int getPrice = getCurrentSector();
			//std::cout << "sector index: " << getPrice << std::endl;
			//winScreen("You win", winning);
			// покажи "You win" и спечелената сума на екрана
			//std::cout << getCircleCoordinates << std::endl;
		
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
bool Game::isClickableButton(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp) {
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); //вземете размера на прозореца

	// координати на бутона
	int spinButtonX = 620;
	int spinButtonY = 50;
	// размер на бутон "Spin"
	int spinButtonW = 150;
	int spinButtonH = 70;

	
	// проверява парамети на бутона	
	if ((xDown > spinButtonX && xDown < (spinButtonX + spinButtonW)) &&// ako xDown > 620 && xDown < 620 + 150
		(yDown > spinButtonY && yDown < (spinButtonY + spinButtonH))){ // ako yDown > 50 && yDown < 620 + 70
		std::cout << "Spin button clicked" << std::endl;
			return true; // button clicked
		}
	return false;
}



//
//void Game::winScreen(std::string massage, int winnings) {
//	
//	// Изобразете съобщението за печалба
//	renderText(massage, winnings);
//
//	// Изобразете спечелената сума
//	std::string winningsText = "Winnings: " + std::to_string(price);
//	renderText(winningsText, xPos, xPos + 50);
//
//}


bool Game::getCircleCoordinates(double centerX, double centerY, double sideLength) {
	float x = 0;
	float y = 0;


	const double  angleIncrement = 2 * M_PI / 24; // Ъгълът между върховете на окръжността

	for (size_t i = 1; i <= 24; ++i)
	{
		// Изчисляване на координатите на върховете на окръжността
		x = centerX + sideLength * cos(i * angleIncrement - M_PI / 2);
		y = centerY + sideLength * sin(i * angleIncrement - M_PI / 2);

		if (i == 1) {
			price = 1;
		}
		else if (i == 2) {
			price += 200;
		}
		else if (i == 3) {
			price += 200;
		}
		else if (i == 4) {
			price += 200;
		}
		else if (i == 5) {
			price += 200;
		}
		else if (i == 6) {
			price += 200;
		}
		else if (i == 7) {
			price += 200;
		}
		else if (i == 8) {
			price += 200;
		}
		else if (i == 9) {
			price += 200;
		}
		else if (i == 10) {
			price += 200;
		}
		else if (i == 11) {
			price += 200;
		}
		else if (i == 12) {
			price += 200;
		}
		else if (i == 13) {
			price += 200;
		}
		else if (i == 14) {
			price += 200;
		}
		else if (i == 15) {
			price += 200;
		}
		else if (i == 16) {
			price += 200;
		}
		else if (i == 17) {
			price += 200;
		}
		else if (i == 18) {
			price += 200;
		}
		else if (i == 19) {
			price += 200;
		}
		else if (i == 20) {
			price += 200;
		}
		else if (i == 21) {
			price += 200;
		}
		else if (i == 22) {
			price += 200;
		}
		else if (i == 23) {
			price += 200;
		}
		else if (i == 24) {
			price += 200;
		}

	}return price = 100;
}





