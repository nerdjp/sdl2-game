#include "include/window.hpp"
#include <iostream>

Window::Window(const char* p_title, int p_width, int p_height)
	: m_window(NULL), m_renderer(NULL)
{
	m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if(m_window == NULL)
	{
		std::cerr << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Window::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(m_renderer, p_filePath);

	if(texture == NULL)
		std::cerr << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void Window::render(SDL_Texture* p_texture)
{
	SDL_RenderCopy(m_renderer, p_texture, NULL, NULL);
}

void Window::display()
{
	SDL_RenderPresent(m_renderer);
}

void Window::clear()
{
	SDL_RenderClear(m_renderer);
}

void Window::cleanUp()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}
