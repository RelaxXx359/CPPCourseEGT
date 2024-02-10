#include "Shapes.h"
void Shapes::drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) { // Midpoint Circle Algorithm
	const int diameter = radius * 2;
	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;
	while (x >= y) {
		SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
		if (error <= 0) {
			y++;
			error += ty;
			ty += 2;
		}
		if (error > 0) {
			x--;
			tx += 2;
			error += tx - diameter;
		}
	}
}

void Shapes::drawPentagon(SDL_Renderer* renderer, int centerX, int centerY, int sideLength) {
	SDL_Point points[5];
	const double angleIncrement = 2 * M_PI / 5; // Ъгълът между върховете на петоъгълника

	for (size_t i = 0; i < 5; ++i)
	{
		// Изчисляване на координатите на върховете на петоъгълника
		points[i].x = centerX + sideLength * cos(i * angleIncrement - M_PI / 2);
		points[i].y = centerY + sideLength * sin(i * angleIncrement - M_PI / 2);
	}

	// Рисуване на линии между върховете за формиране на петоъгълника
	for (size_t i = 0; i < 5; ++i) 
	{
		SDL_RenderDrawLine(renderer, points[i].x, points[i].y, points[(i + 1) % 5].x, points[(i + 1) % 5].y);
	}

 }



void Shapes::drawHexagon(SDL_Renderer* renderer, int centerX, int centerY, int sideLength) {

	SDL_Point points[6];
	const double angleIncrement = 2 * M_PI / 6;    //Ъгълът между върховете на шестоъгълник

	// Изчисляване на координатите на върховете на петоъгълник
	for (size_t i = 0; i < 6; i++)
	{
		points[i].x = centerX + sideLength * cos(i * angleIncrement - M_PI / 2);
		points[i].y = centerY + sideLength * sin(i * angleIncrement - M_PI / 2);
	}

	// Рисуване на линии между върховете за формиране на шестоъгълник
	for (size_t i = 0; i < 6; i++)
	{
		SDL_RenderDrawLine(renderer, points[i].x, points[i].y, points[(i + 1) % 6].x, points[(i + 1) % 6].y);
	}
}