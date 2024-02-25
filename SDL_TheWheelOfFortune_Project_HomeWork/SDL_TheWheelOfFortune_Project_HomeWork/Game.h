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
	
	//  Функцията init се използва за инициализиране на прозореца
	  // title Заглавие на прозореца
	  // xpos X-координата на началната позиция на прозореца
	  // ypos Y-координата на началната позиция на прозореца
	  // width Ширина на прозореца
	  // height Височина на прозореца
	  // flags Флагове за настройки на прозореца 
	 
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	// Функцията ttf_init се използва за инициализиране на библиотеката с шрифтове 
	bool ttf_init();

	 
	void render();     // визуализиране на графиката
	void update();    // актуализиране на състоянието на програмата
	void handleEvents();  //обработване на входана мишката
	void clean();       //почистване преди изход от програмата
	bool isRunning();   // докато програмата  работи 

	
	//  Функцията isClickableButton проверява дали даден бутон е бил кликнат, 
	// като сравнява координатите на натискане и освобождаване на мишката
	// t Указател към текстурата на бутона
	// r Указател към SDL_Rect, определящ границите на бутона
	// xDown X-координата на натискането на мишката
	// yDown Y-координата на натискането на мишката
	//  xUp X-координата на освобождаването на мишката
	//  yUp Y-координата на освобождаването на мишката


	bool isClickableButton(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);


	
	// Функцията getCircleCoordinates изчислява координатите на центъра на окръжност
	// markerX X-координата на маркера
	// markerY Y-координата на маркера
	// centerX X-координата на центъра на правоъгълника
	// centerY Y-координата на центъра на правоъгълника
	//  sideLength Дължина на страната на правоъгълника

	std::pair<float, float> getCircleCoordinates(double markerX, double markerY, double centerX, double centerY, double sideLength);

	//Проверява currentSector за текъщата съма в сектора
	int currentSector(int angleToMarker);

private:

	SDL_Window* window = NULL;  //деклариране на  променлива window като указател към SDL_Window
	SDL_Renderer* renderer = NULL;  //декларира променливата renderer като указател към SDL_Renderer
	bool running;  // определя състоянието на приложението

	SDL_Texture* textTextureFont;  //декларира променливата textTextureFont като указател към SDL_Texture
	SDL_Rect dRectFont;    //декларира променливата dRectFont като указател към SDL_Rect

	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;  //декларира променливата frameFlip като указател към SDL_RendererFlip

	bool spinning = false; // Флаг показващ дали колелото се върти
	bool spinButtonActive = true; //Флаг покозващ дали бутона е активен
	bool win = false; // Флаг показващ дали да изпише текст "You win.."

	float rotationSpeed; // Скорост на въртене на колелото

	SDL_Texture* clickableTexture; //декларира променливата clickableTexture като указател към SDL_Texture
	SDL_Rect clickableRect;     //декларира променливата clickableRect като указател към SDL_Rect
	int mouseDownX, mouseDownY;  //  координати на мишката

	int price; // променлива за цената в секора
};

