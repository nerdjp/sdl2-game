#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "include/window.hpp"

int main(int argc, char* argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cerr << "SDL_Init FAILED TO INIT. SDL_ERROR: " << SDL_GetError() << std::endl;
	
	if(!IMG_Init(IMG_INIT_PNG))
		std::cerr << "SDL_Image FAILED TO INIT. SDL_ERROR " << SDL_GetError() << std::endl;

	//std::cout << "Hewwo Worwd" << std::endl;
	
	Window window("SDL Game", 1280, 720);

	SDL_Texture* image = window.loadTexture("res/gfx/image.png");
	bool game_running = true;
	SDL_Event event;
	while(game_running)
	{
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				game_running = false;
				break;

			default:
				break;
			}
		}
		window.clear();
		window.render(image);
		window.display();
		SDL_DestroyTexture(image);
		image = window.loadTexture("res/gfx/image.png");
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}
