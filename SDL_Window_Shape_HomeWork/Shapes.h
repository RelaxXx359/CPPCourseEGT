#pragma once
#include <iostream>
#include"Game.h"

class Shapes {
public:
	static void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);

	static void drawPentagon(SDL_Renderer* renderer, int centerX, int centerY, int sideLength);

	static void drawHexagon(SDL_Renderer* renderer, int centerX, int centerY, int sideLenght);

};