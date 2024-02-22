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

	if (win){
		std::cout << "spinning is false\n";

		SDL_Surface* tempSurfaceText = NULL; // указател за съхранение на текста
		tempSurfaceText = TTF_RenderText_Blended(font, "You win: ", { 0, 0, 255, 255 }); //за да се рендира текста
		textTextureFont = SDL_CreateTextureFromSurface(renderer, tempSurfaceText); //създаване на текстура


		int tw, th; // променливи за съхранение на ширина и височина

		SDL_QueryTexture(textTextureFont, 0, 0, &tw, &th); //извличане  ширина и височина
		dRectFont = { 20, 20, tw,th };  // структора с парамеетри
		std::cout << "dRect " << tw << ":" << th << std::endl;


		SDL_FreeSurface(tempSurfaceText); //освобождава паметта
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
				if (isButtonClicked) {  //ако бутона е натиснат, колелото се завърта
					std::cout << "CLICKED SPIN\n";
					spinning = true;
				}
				else {
					std::cout << "NOT CLICKED SPIN\n";  // не е натиснат бутона
				}

				std::cout <<"mouseDownX " << mouseDownX << " : " <<"mouseDownY " << mouseDownY << std::endl;
				std::cout <<"msx " << msx << "  :" << "msy " << msy << std::endl;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				std::cout << "Right mouse button is down\n";
			}
		/*case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				std::cout << "Left mouse button is up\n";
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				std::cout << "Right mouse button is up\n";

			}
		}*/
		}; break;

		default: break;
		}
	}
}



void Game::update() {	
		if (SDL_GetTicks() % 30 == 0) {
			rotationSpeed -= 1;
			std::cout << "rotaionspeed -= 2\n";
		}
		if (rotationSpeed <= 0) {
			rotationSpeed = 0;
			bool getPrice = getCurrentSector();
			std::cout << "sector index: " << getPrice << std::endl;
			spinning = false;
			ttf_init();
			win = true;
			// покажи "You win" и спечелената сума на екрана
			//winScreen("You win", winnings);
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
int Game::getCurrentSector() const {
	std::vector<std::string> sectors;


	double fmod(double x, double y);

	//  броя на секторите
	int numSectors = sectors.size();

	// pроверка дали има сектори, за да избегнем грешка при делене на нула
	if (numSectors == 0)
		return -1; // върнете някаква стойност за грешка

	// изчисляваме ъгъла на всяка секторна част, като разделяме 360 градуса на броя сектори.
	float sectorAngle = 360.0f / numSectors;

	// изчисляваме текущия ъгъл на завъртане, като вземаме остатъка при деление на rotationAngle на 360.
	float currentAngle = rotationAngle % 360;
	// Изчисляване на текущия ъгъл на завъртане
	//float currentAngle = fmod(rotationAngle, 360.0f);

	// ако текущият ъгъл е отрицателен, преобразуваме го в положителен.
	if (currentAngle < 0) {
		currentAngle += 360; // за отрицателни ъгли
	}

	// изчисляваме индекса на сектора, към който принадлежи текущия ъгъл.

	int sectorIndex = static_cast<int>(currentAngle / sectorAngle);
	return sectorIndex;
}



//void Game::winScreen(std::string massage, int winnings) {
//	int xPos = 0;
//	int yPos = 0; 
//	// Изобразете съобщението за печалба
//	ttf_init(massage, xPos, yPos);
//
//	// Изобразете спечелената сума
//	std::string winningsText = "Winnings: " + std::to_string(winnings);
//	ttf_init(winningsText, xPos, xPos + 50);
//
//}




