#include "Character.hpp"

Character::Character(SDL_Texture *texture, float speed, int xPos, int yPos) : Entity(texture, xPos, yPos), speed(speed)
{
	gravity = 2;
}

void Character::Update()
{
	Entity::Update();

	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_W])
	{
		position.y += speed * -1;
	}
	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_S])
	{
		position.y += speed * 1;
	}
	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_A])
	{
		position.x += speed * -1;
	}
	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_D])
	{
		position.x += speed * 1;
	}

	position.y += gravity;

}
