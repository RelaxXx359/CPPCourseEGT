﻿//Game.h
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "SDL_ttf.h"
class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	//bool ttf_init();
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	void updateGame(bool toRun, int frames = 10, int speed = 100);

	// дали сме кликнали в разположението на текстурата
	bool isClickableTextureClicked(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	SDL_Texture* textTextureText;
	SDL_Rect dRectText;

	SDL_Rect clickableRect;
	int mouseDownX, mouseDownY; 


	int currentFrame;
	bool anim_state = false;
	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;
	int SpriteX = 0, SpriteY = 0;
};
