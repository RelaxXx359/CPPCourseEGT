//Game.h
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "SDL_ttf.h"
#include <vector>
#include <cmath>

class Game {
public:
	Game();
	~Game();

	// initializes  window
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	bool ttf_init();

	// visualization function
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();

	// дали сме кликнали в разположението на текстурата
	//bool isClickableTextureClicked(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);

	bool isClickableButton(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);
	bool getCircleCoordinates(double centerX, double centerY, double sideLength);


	//void winScreen(std::string, int);




	//float angleCodinati(std::string text, int x, int y);

private:

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	SDL_Texture* textTextureFont;
	SDL_Rect dRectFont; 

	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;
	int currentFrame;


	int CenterX, CenterY ;
	bool spinning = false; // Флаг показващ дали колелото се върти
	bool spinButtonActive = true; //Флаг покозващ дали бутона е активен

	bool win = false; // Флаг показващ дали да изпише текст "You win"

 	//int rotationAngle; // Текущ ъгъл на въртене на колелото
	float rotationSpeed; // Скорост на въртене на колелото
	//bool anim_state = false;

	SDL_Texture* clickableTexture;
	SDL_Rect clickableRect;
	int mouseDownX, mouseDownY;

	float price;
	double angleIncrement;



};

