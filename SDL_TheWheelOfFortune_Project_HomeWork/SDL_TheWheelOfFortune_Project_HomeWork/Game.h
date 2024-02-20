//Game.h
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "SDL_ttf.h"
class Game {
public:
	Game();
	~Game();

	// initializes  window
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	//bool ttf_init();
	// visualization function
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	//void updateGame(bool toRun, int frames = 10, int speed = 1000);

	// дали сме кликнали в разположението на текстурата
	//bool isClickableTextureClicked(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);

	bool isClickableButton(int xDown, int yDown, int xUp, int yUp);

private:

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	/*SDL_Texture* textTextureText;
	SDL_Rect dRectText;

	SDL_Rect clickableRect;*/
	int mouseDownX, mouseDownY; 

	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;
	//int currentFrame;


	bool anim_state = false;
	int SpriteX = 0, SpriteY = 0;




};

