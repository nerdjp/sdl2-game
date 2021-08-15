#pragma once
#include "Engine.hpp"
#include "Entity.hpp"
#include <iostream>

class Character : public Entity
{
public:
	Character(SDL_Texture *texture, float speed, int xPos = -1, int yPos = -1);
	Vector getVelocity() { return velocity; };
	virtual void Update() override;

private:
	Vector velocity;
	float gravity;
	float speed;
};
