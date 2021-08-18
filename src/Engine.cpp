#include "Engine.hpp"

Engine* Engine::instance;

Engine::Engine() : renderer("SDL2 Game", 1280, 720)
{
	ev.addEvent(Event(EventType::WindowClose, std::bind(&Engine::close, this)));
}

Engine* Engine::getInstance()
{
	if(instance == nullptr)
	{
		instance = new Engine();
	}
	return instance;
}

void Engine::setIsRunning(bool running)
{
	isRunning = running;
}

void Engine::update()
{
	for(Entity *e : entities)
	{
		e->update();
	}
	ev.queryEvents();
}

Entity* Engine::addEntity()
{
	Entity *e = new Entity();
	entities.push_back(e);
	return e;
}

void Engine::addEvent(Event event)
{
	ev.addEvent(event);
}

void Engine::close()
{
	isRunning = false;
}

const Uint8* Engine::getKeyboardState()
{
	return ev.getKeyboardState();
}

void Engine::cleanUp()
{
	for (Entity* e : entities) delete e;
	renderer.cleanUp();
}
