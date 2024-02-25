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

	bool isClickableButton(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);
	std::pair<float, float> getCircleCoordinates(double markerX, double markerY, double centerX, double centerY, double sideLength);

	//float calculatePriceForVertex(double x, double y);

	int  getSectorValue(float x, float y);

	double getWheelAngle(double rotationSpeed, double time);


private:

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	SDL_Texture* textTextureFont;
	SDL_Rect dRectFont; 

	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;
	int currentFrame;


	int centerX, centerY, sideLength;
	bool spinning = false; // Флаг показващ дали колелото се върти
	bool spinButtonActive = true; //Флаг покозващ дали бутона е активен

	bool win = false; // Флаг показващ дали да изпише текст "You win"
	//bool nonwin = false;

	float rotationSpeed; // Скорост на въртене на колелото

	SDL_Texture* clickableTexture;
	SDL_Rect clickableRect;
	int mouseDownX, mouseDownY;

	float markerX, markerY;
	float x, y;
	int price;
	double time;
	double rotation;


};

