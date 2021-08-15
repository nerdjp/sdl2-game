#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "GameObject.hpp"
#include "ECS/ECS.hpp"
#include "ECS/Sprite.hpp"
#include "Math.hpp"

class Entity : public GameObject
{
public:
	Entity(SDL_Texture *texture, int xPos = -1, int yPos = -1);
	Sprite sprite;
	int getX();
	int getY();
	Vector getPosition() { return position; }
	/* std::vector<Component*> getComponent() { return components; } */
	Sprite getSprite() { return sprite; };
	virtual void Update() override;

protected:
	Vector position;
	/* std::vector<Component*> components; */

};
