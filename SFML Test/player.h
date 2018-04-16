#pragma once
#ifndef Player_H
#define Player_H

#include "gameobject.h"
#include <SFML/Graphics.hpp>

class PlayerController : public Component
{
public:
	sf::Sprite sprite;

	Gameobject GetGameobject() override;
	void Start() override;
	void Draw(sf::RenderWindow &window) override;
	void EarlyUpdate() override;
	void Update() override;
	void LateUpdate() override;
};


#endif
