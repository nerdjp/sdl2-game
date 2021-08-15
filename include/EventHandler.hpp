#pragma once
#include <SDL2/SDL.h>
#include <functional>
#include <vector>
#include "Events.hpp"

class EventHandler
{
public:
	EventHandler();
	~EventHandler(){}
	void addEvent(Event event);
	void queryEvents();
	void handleEvent(Event event);
	void updateKeyboard();
	const Uint8* getKeyboardState();

private:
	SDL_Event event;
	std::vector<Event> eventList;
	const Uint8* keyboardState;
};
