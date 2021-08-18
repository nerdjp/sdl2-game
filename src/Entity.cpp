#include "Entity.hpp"

void Entity::update()
{
	for (Component* c : components) c->update();
}

Entity::~Entity()
{
	for (Component* c: components) delete c;
}
