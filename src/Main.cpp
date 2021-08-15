#include <iostream>
#include "Engine.hpp"
#include "Character.hpp"
#include "Events.hpp"

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	
	unsigned int framestart;
	int frameTime;

	Character entity(Engine::getInstance()->getRenderer().loadTexture("res/gfx/image.png"), 10, 50, 50);
	Entity entity2(Engine::getInstance()->getRenderer().loadTexture("res/gfx/swapped.png"), 50, 50);
	Engine::getInstance()->AddToUpdate(&entity);
	Engine::getInstance()->AddToUpdate(&entity2);
	Engine::getInstance()->setIsRunning(true);
	while(Engine::getInstance()->getIsRunning())
	{
		framestart = SDL_GetTicks();

		Engine::getInstance()->Update();
		Engine::getInstance()->getRenderer().clear();
		Engine::getInstance()->getRenderer().render(entity.getSprite());
		Engine::getInstance()->getRenderer().render(entity2.getSprite());
		Engine::getInstance()->getRenderer().display();

		frameTime = SDL_GetTicks() - framestart;

		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	Engine::getInstance()->getRenderer().cleanUp();
	SDL_Quit();
	return 0;
}
