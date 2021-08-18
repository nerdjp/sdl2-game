#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Renderer.hpp"
#include "Entity.hpp"
#include "EventHandler.hpp"

class Engine
{
public:
	static Engine* getInstance();

	Renderer getRenderer() { return renderer; };
	bool getIsRunning() { return isRunning; };
	const Uint8* getKeyboardState();

	void update();
	Entity* addEntity();
	void setIsRunning(bool running);
	void addEvent(Event event);
	void close();
	void cleanUp();

private:
	Engine();
	Renderer renderer;
	EventHandler ev;
	static Engine* instance;
	std::vector<Entity*> entities;
	bool isRunning;
};
