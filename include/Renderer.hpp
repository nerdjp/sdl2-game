#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ECS/Sprite.hpp"

class Renderer
{
public:
	Renderer(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* filePath);
	void render(SDL_Texture* texture);
	void render(Sprite sprite);
	void display();
	void clear();
	void cleanUp();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
