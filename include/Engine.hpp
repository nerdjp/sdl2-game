#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Renderer.hpp"
#include "GameObject.hpp"
#include "EventHandler.hpp"

class Engine
{
public:
	Renderer getRenderer() { return renderer; };
	static Engine* getInstance();
	void Update();
	void AddToUpdate(GameObject* go);
	bool getIsRunning() { return isRunning; };
	void setIsRunning(bool running);
	void addEvent(Event event);
	void close();
	const Uint8* getKeyboardState();

private:
	Engine();
	Renderer renderer;
	EventHandler ev;
	static Engine* instance;
	std::vector<GameObject*> gameObjects;
	bool isRunning;
};
