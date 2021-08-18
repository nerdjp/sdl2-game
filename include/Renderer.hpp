#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include "ECS/Sprite.hpp"

class Renderer
{
public:
	Renderer(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* filePath);
	void render(SDL_Texture* texture);
	void render(Entity& entity);
	void display();
	void clear();
	void cleanUp();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
