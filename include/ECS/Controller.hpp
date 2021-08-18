#pragma once
#include "ECS/ECS.hpp"
#include "Engine.hpp"
#include "Math.hpp"
#include <iostream>

 class Controller : public Component 
 { 
 public: 
	Controller(float speed);
	virtual void init() override;
 	virtual void update() override; 

 private: 
	Transform* eTransform;
 	Vector velocity; 
 	float speed; 
 }; 
