#include "Entity.hpp"

Entity::Entity(SDL_Texture *texture, int xPos, int yPos)
	: position(xPos, yPos), sprite(texture)
{}

void Entity::Update()
{
	sprite.setPosition(position);
}
