#include "ECS/Controller.hpp"

Controller::Controller(float speed) : speed(speed)
{}

void Controller::init()
{
	eTransform = entity->getComponent<Transform>();
}

void Controller::update()
{

	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_W])
	{
		entity->getComponent<Transform>()->setPositionY(entity->getComponent<Transform>()->getTransform().y + speed * -1);
	}
	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_S])
	{
		entity->getComponent<Transform>()->setPositionY(entity->getComponent<Transform>()->getTransform().y + speed * 1);
	}
	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_A])
	{
		entity->getComponent<Transform>()->setPositionX(entity->getComponent<Transform>()->getTransform().x + speed * -1);
	}
	if(Engine::getInstance()->getKeyboardState()[SDL_SCANCODE_D])
	{
		entity->getComponent<Transform>()->setPositionX(entity->getComponent<Transform>()->getTransform().x + speed * 1);
	}
	/* position.y += gravity; */
}
