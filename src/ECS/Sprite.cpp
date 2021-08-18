#include "ECS/Sprite.hpp"

Sprite::Sprite(SDL_Texture *texture) : sprite(texture)
{
	SDL_QueryTexture(texture, NULL, NULL, &spriteMask.w, &spriteMask.h);
	spriteMask.x = 0;
	spriteMask.y = 0;
}

void Sprite::init()
{
	if(entity == nullptr)
		std::cout << "It's null dumbass" << std::endl;
	position = entity->getComponent<Transform>();
}

void Sprite::update()
{
	/* position = entity->getComponent<Transform>(); */
}

AnimatedSprite::AnimatedSprite(SDL_Texture *texture, int spriteW, int spriteH, int nFrames) : Sprite(texture), nFrames(nFrames)
{
	spriteMask.w = spriteW;
	spriteMask.h = spriteH;
}

void Sprite::setPosition(Vector position)
{
	/* this->position = position; */
	/* std::cout << this->position.x << " " << this->position.y << std::endl; */
}

void AnimatedSprite::update()
{
	if(animate == true)
	{
		if(spriteMask.x <= spriteMask.w * nFrames)
		{
			spriteMask.x += spriteMask.w;
		}
		else
		{
			spriteMask.x = 0;
		}
	}

}
