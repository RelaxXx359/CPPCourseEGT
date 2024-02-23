#include "Shape.h"

void Shape::Circle(int centerX, int centerY, int sideLength) {

	SDL_Point points[24];
	const double angleIncrement = 2 * M_PI / 24;    //Ъгълът между върховете на колелото

	// Изчисляване на координатите на върховете на колелото
	for (size_t i = 0; i < 24; i++)
	{
		points[i].x = centerX + sideLength * cos(i * angleIncrement - M_PI / 2);
		points[i].y = centerY + sideLength * sin(i * angleIncrement - M_PI / 2);
	}
}