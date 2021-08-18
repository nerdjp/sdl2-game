#pragma once
#include "ECS/ECS.hpp"
#include "Math.hpp"

class Transform : public Component
{
public:
	Transform(float x = 0, float y = 0);
	void setPositionX(float x) { transform.x = x; }
	void setPositionY(float y) { transform.y = y; } 
	Vector getTransform();

private:
	Vector transform;
};
