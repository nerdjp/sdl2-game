#pragma once
#include <SDL2/SDL.h>
#include <functional>
#include <iostream>

enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus,
	KeyUpEvent, KeyDownEvent,
	MousePressed, MouseReleased, MouseMove, MouseScroll
};

struct Event
{
	EventType eventType;
	std::function<void()> func;
	Event(EventType type, std::function<void()> f) : eventType(type), func(f) {}

	bool operator==(const Event &other)
	{
		if(this->eventType == other.eventType)
			return true;
		else
			return false;
	}
};
