#include <iostream>
#include "Engine.hpp"
#include "Events.hpp"
#include "Entity.hpp"
#include "ECS/Controller.hpp"

	int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	
	unsigned int framestart;
	int frameTime;

	Entity *entity = Engine::getInstance()->addEntity();
	entity->addComponent<Transform>();
	entity->addComponent<Sprite>(Engine::getInstance()->getRenderer().loadTexture("res/gfx/image.png"));
	entity->addComponent<Controller>(10);
	Engine::getInstance()->setIsRunning(true);
	while(Engine::getInstance()->getIsRunning())
	{
		framestart = SDL_GetTicks();

		Engine::getInstance()->update();
		Engine::getInstance()->getRenderer().clear();
		Engine::getInstance()->getRenderer().render(*entity);
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
