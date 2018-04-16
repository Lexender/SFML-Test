#pragma once

#ifndef Gameobject_H
#define Gameobject_H

#include <SFML/Graphics.hpp>
#include <list>

class Component;


class Gameobject
{
public:
	
	std::string name;
	typedef std::list<Component*> ComponentList;
	ComponentList components;

};

class Component
{
public:

	virtual Gameobject GetGameobject() = 0;
	virtual void Start() = 0;
	virtual void EarlyUpdate() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Draw(sf::RenderWindow &window) = 0;
};



#endif
