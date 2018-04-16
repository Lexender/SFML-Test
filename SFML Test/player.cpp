#include "player.h"
#include "sprites.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

sf::Sprite sprite;
sf::Vector2f pos;

Gameobject PlayerController::GetGameobject()
{
	return Gameobject();
}

void PlayerController::Start()
{
	sprite = Sprites::tiles[10];
	pos.x = 200.f;
	pos.y = 200.f;
}

void PlayerController::Draw(sf::RenderWindow &window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}

void PlayerController::EarlyUpdate()
{
}

void PlayerController::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pos.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pos.x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		pos.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		pos.y += 1;
}

void PlayerController::LateUpdate()
{
}


