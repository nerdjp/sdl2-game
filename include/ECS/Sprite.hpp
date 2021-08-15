#pragma once
#include <iostream>
#include "ECS/ECS.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite : public Component
{
public:
	Sprite(SDL_Texture *texture);
	SDL_Texture* getSprite() { return sprite; }
	SDL_Rect getSpriteMask() { return spriteMask; }
	void setPosition(Vector position);
	Vector getPosition() { return position; }

protected:
	SDL_Texture* sprite;
	SDL_Rect spriteMask;
	Vector position;

};

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(SDL_Texture *texture, int spriteW, int spriteH, int nFrames);
	/* virtual void Update() override; */

private:
	bool animate = false;
	int nFrames;

};
