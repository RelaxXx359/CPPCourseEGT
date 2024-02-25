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

				// TextureManager за зареждане на текстури:
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

	TTF_Font* font = TTF_OpenFont("fonts/comicbd.ttf", 36); // отваря шрифт от файл с име и размер, връща указател към заредения шрифт
	if (font == NULL) { // проверка дали зареждането на шрифта е успешно
		std::cout << "Font is false\n";
		return false;
	}
	    // изобразяване на текстура с печалба и определен цвят 
	
		std::string winningsText = "You win: " + std::to_string(price);
		SDL_Surface* tempSurfaceText = TTF_RenderText_Blended(font, winningsText.c_str(), { 255, 127, 39, 255 });
		textTextureFont = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

		int tw, th; // променливи за съхранение на ширина и височина
		SDL_QueryTexture(textTextureFont, 0, 0, &tw, &th); //извличане  ширина и височина
		dRectFont = { 20, 20, tw,th };  // парамеетри за позициониране на текстурата

		//SDL_FreeSurface(tempSurfaceText); //освобождава паметта
		TTF_CloseFont(font); //затваря текста
		return true; // Връщаме true, за да покажем, че инициализацията е успешна
	
	return false; // Връщаме false, ако spinning не е false
}

void Game::render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // задава цвета на прозореца
	SDL_RenderClear(renderer);
	if (win) {           // когато колелото спре да се вътри, изписва You win: "price"
		SDL_RenderCopy(renderer, textTextureFont, NULL, &dRectFont);
	}
		TextureManager::Instance()->drawRotation("wheel", 50, 100, 800, 800, renderer, rotationSpeed);
		// button "Spin"
		TextureManager::Instance()->drawTexture("spin", 670, 20, 150, 70, renderer);
		if (!spinButtonActive) {                    //Флаг покозващ дали бутонае активен
			TextureManager::Instance()->drawTexture("spin2", 670, 20, 150, 70, renderer);
		}
		// arrow
		TextureManager::Instance()->drawTexture("arrow", 400, 20, 100, 70, renderer);

		int ww, wh;
		SDL_GetWindowSize(window, &ww, &wh);           // присвоява ширината и височината на прозореца на ww и wh

		//удебелен правоъгълник около бутона, като създаваме правоъгълници с един пиксел
		//  по ширина и височина повече или по малко
		SDL_Rect outlineRect = { 670, 20, 150, 70 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 670 - 1, 20 - 1, 152, 72 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 670 - 2, 20 - 2, 154, 74 };
		SDL_RenderDrawRect(renderer, &outlineRect);
		outlineRect = { 670 - 3, 20 - 3, 156, 76 };
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

				// функция която проверява дали кординатите на мишката се намират в рамките на бутона
				bool isButtonClicked = isClickableButton(clickableTexture, &clickableRect, mouseDownX, mouseDownY, msx, msy);

				if (isButtonClicked && spinButtonActive) { // ако бутона на мишката е натиснат и бутона "Spin" e активен 
					spinning = true;                       // Флаг показващ дали колелото се върти
					rotationSpeed = 10;                    // Скорост на въртене на колелото
					spinButtonActive = false;              //Флаг покозващ дали бутона е активен
				}
				if (rotationSpeed <= 0) {
			
					if (isButtonClicked && spinButtonActive) {  //ако бутона е натиснат, колелото се завърта
						ttf_init();
						spinning = true;                        // Флаг показващ дали колелото се върти
						rotationSpeed = 10;                     //  Скорост на въртене на колелот
						spinButtonActive = false;               //Флаг покозващ дали бутона е активен

						if (isButtonClicked && spinButtonActive) {  // ако бутона на мишката е натиснат и бутона "Spin" e активен 
							spinButtonActive = false;           //Флаг покозващ дали бутона е активен
						}
					}
				}; break;
			}
		default: break;
		}
		}
	}
}
std::pair<float, float> Game::getCircleCoordinates(double markerX, double markerY, double centerX, double centerY, double sideLength) {
	const double angleIncrement =  2 * M_PI / 24; // Ъгълът между върховете на окръжността

	// изчисляване на ъгъла на маркера спрямо центъра на окръжността
	float angleToMarker = atan2(x, y) * (180 / M_PI);
	if (angleToMarker <= 0) {
		angleToMarker += 360; // ako ъгъла е отрицателно число
	}

	// Изчисляване на индекса на върха, на който се намира маркера
	int sectorIndex = static_cast<int>(angleToMarker / angleIncrement) +1;

	// Изчисляване на координатите на сектора
	float sectorAngle = sectorIndex * angleIncrement;

	float x = centerX + sideLength * cos(sectorAngle);
	float y = centerY + sideLength * sin(sectorAngle);

	return std::make_pair(x, y);
}
double Game::calculateSectorSum(double angleToMarker) {
	// Определяне на номера на сектора в зависимост от ъгъла на маркера
	int sectorNumber = static_cast<int>((angleToMarker / (2 * M_PI / 24))) ;

	// проверка каква е сумата на sectorNumer
	switch (sectorNumber) {
	case 1:
		return  0;      // BANKRUPT

	case 2:
		return  1500;

	case 3:
		return  200;

	case 4:
		return  850;

	case 5:
		return  400;

	case 6:
		return  100000;    // Jackpot

	case 7:
		return  150;

	case 8:
		return  500;

	case 9:
		return  900;

	case 10:
		return  350;

	case 11:
		return  0;      // lose a turn 

	case 12:
		return 200;

	case 13:
		return  175;

	case 14:
		return  5000;

	case 15:
		return  0;         // BANKRUPT

	case 16:
		return  250;

	case 17:
		return  600;

	case 18:
		return  5000;      // SURPRISE

	case 19:
		return  800;

	case 20:
		return  550;

	case 21:
		return  1000;

	case 22:
		return  100;

	case 23:
		return  300;

	case 24:
		return  750;

	defalt:
		return -1;
	}
}


void Game::update() {
	if (spinning) {
		spinButtonActive = false;
		if (SDL_GetTicks() % 30 == 0) {
			rotationSpeed -= 2;
		}
		if (rotationSpeed <= 0) {
			rotationSpeed = 0;
		
			spinButtonActive = true;
			spinning = false;

			win = true;  // показване на текста You win..

			double markerX = 400;  //  координати на маркера
			double markerY = 20;
			double centerX = 900 / 2;  //  координати на центъра на окръжността
			double centerY = 850 / 2;
			double sideLength = 800 / 2; //  дължина на страна на окръжността

			auto result = Game::getCircleCoordinates(markerX, markerY, centerX, centerY, sideLength);
			std::cout << "Coordinates of the marker on the circle: (" << result.first << ", " << result.second << ")\n";
			std::cout << markerX << ":" << markerY << ":" << centerX << ":" << centerY << ":" << sideLength << std::endl;
			
		}
		else {
			win = false;   // скриване на текста You win..
		}
	}
}
bool Game::isClickableButton(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp) {

	// координати на бутона
	int spinButtonX = 670;
	int spinButtonY = 20;

	// размер на бутон "Spin"
	int spinButtonW = 150;
	int spinButtonH = 70;


	// проверява парамети на бутона	
	if ((xDown > spinButtonX && xDown < (spinButtonX + spinButtonW)) &&// ako xDown > 620 && xDown < 620 + 150
		(yDown > spinButtonY && yDown < (spinButtonY + spinButtonH))) { // ako yDown > 50 && yDown < 620 + 70
		return true; // button clicked
	}
	return false;
}

void Game::clean() {
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













