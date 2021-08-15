#include "EventHandler.hpp"

EventHandler::EventHandler()
{
	updateKeyboard();
}

void EventHandler::addEvent(Event event)
{
	eventList.push_back(event);
}

void EventHandler::queryEvents()
{
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			handleEvent(Event(EventType::WindowClose, NULL));
			break;
		case SDL_KEYDOWN:
			updateKeyboard();
			handleEvent(Event(EventType::KeyDownEvent, NULL));
			break;
		case SDL_KEYUP:
			updateKeyboard();
			handleEvent(Event(EventType::KeyUpEvent, NULL));
			break;
		default:
			break;
		}
	}
}

void EventHandler::handleEvent(Event event)
{
	for(Event ev : eventList)
	{
		if(ev == event)
		{
			ev.func();
		}
	}
}

void EventHandler::updateKeyboard()
{
	keyboardState = SDL_GetKeyboardState(nullptr);
}

const Uint8* EventHandler::getKeyboardState()
{
	return keyboardState;
}
