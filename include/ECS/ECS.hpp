#pragma once
#include "GameObject.hpp"

class Component : public GameObject
{
	public:
		bool getIsActive() { return isActive; }

	protected:
		bool isActive = true;
};
