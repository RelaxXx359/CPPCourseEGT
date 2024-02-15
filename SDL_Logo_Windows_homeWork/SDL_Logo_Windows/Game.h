#pragma once
#include <SDL.h>
#include <SDL_image.h>
class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;


	SDL_Texture* texture = NULL;
	SDL_Rect imageRectangle;
	SDL_Rect windowRectangle;

	int currentFrame;
	int currentRow;
};