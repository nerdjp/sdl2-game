#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

public:
	Window(const char* p_title, int p_width, int p_height);
	SDL_Texture* loadTexture(const char* p_filePath);
	void render(SDL_Texture* p_texture);
	void display();
	void clear();
	void cleanUp();

};
