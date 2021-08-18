#pragma once
#include <vector>
#include <array>
#include <bitset>
#include <iostream>
#include "ECS/ECS.hpp"

class Entity
{
public:
	virtual void update();

	template <class T, class... TArgs> void addComponent(TArgs&&... args)
	{
		T* comp(new T(std::forward<TArgs>(args)...));
		comp->setEntity(this);
		components.emplace_back(comp);
		componentArray[getComponentTypeId<T>()] = comp;
		componentBitSet[getComponentTypeId<T>()] = true;
		comp->init();

	}

	template <class T> T* getComponent() const
	{
		if(!componentBitSet[getComponentTypeId<T>()])
		{
			std::cerr << "Tring to get a unexistent component" << std::endl;
			return nullptr;
		}
		Component* ptr(componentArray[getComponentTypeId<T>()]);
		return static_cast<T*>(ptr);
	}

	bool getIsActive();

	virtual ~Entity();

private:
	std::array<Component*, maxComponents> componentArray;
	std::bitset<maxComponents> componentBitSet;
	std::vector<Component*> components;
	bool active = true;
};
