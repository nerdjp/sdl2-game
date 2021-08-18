#include "ECS/Transform.hpp"

Transform::Transform(float x, float y) : transform(x, y) {};

Vector Transform::getTransform()
{
	return transform;
}
