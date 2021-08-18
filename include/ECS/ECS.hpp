#pragma once
#include <algorithm>
#include "GameObject.hpp"

class Component;
class Entity;

inline std::size_t generateNewUniqueId()
{
	static std::size_t id = 0;
	return id++;
}

template<class T> inline std::size_t getComponentTypeId()
{
	static std::size_t typeId = generateNewUniqueId();
	return typeId;
}

constexpr std::size_t maxComponents = 32;

class Component
{
public:
	bool getIsActive() { return isActive; }
	virtual void init() {};
	virtual void update() {};
	virtual ~Component() {};
	void setEntity(Entity *e) { entity = e; }

protected:
	Entity* entity;
	bool isActive = true;
};
