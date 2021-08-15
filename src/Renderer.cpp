#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(const char* title, int width, int height)
	: window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		std::cerr << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Renderer::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if(texture == NULL)
		std::cerr << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void Renderer::render(SDL_Texture* texture)
{
	SDL_Rect dst;
	dst.x = 10;
	dst.y = 10;
	dst.w = 10;
	dst.h = 10;
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void Renderer::render(Sprite sprite)
{
	SDL_Rect src = sprite.getSpriteMask();
	SDL_Rect dst;
	dst.x = sprite.getPosition().x;
	dst.y = sprite.getPosition().y;
	dst.w = sprite.getSpriteMask().w;
	dst.h = sprite.getSpriteMask().h;
	SDL_RenderCopy(renderer, sprite.getSprite(), &src, &dst);
}

void Renderer::display()
{
	SDL_RenderPresent(renderer);
}

void Renderer::clear()
{
	SDL_RenderClear(renderer);
}

void Renderer::cleanUp()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
