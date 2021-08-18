#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ECS/ECS.hpp"
#include "Entity.hpp"
#include "ECS/Transform.hpp"
#include "Math.hpp"

class Sprite : public Component
{
public:
	Sprite(SDL_Texture *texture);
	SDL_Texture* getSprite() { return sprite; }
	SDL_Rect getSpriteMask() { return spriteMask; }
	const Transform* getPosition() const { return position; }
	virtual void init() override;
	virtual void update() override;

protected:
	SDL_Texture* sprite;
	SDL_Rect spriteMask;
	const Transform* position;

};

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(SDL_Texture *texture, int spriteW, int spriteH, int nFrames);
	virtual void update() override;

private:
	bool animate = false;
	int nFrames;

};
