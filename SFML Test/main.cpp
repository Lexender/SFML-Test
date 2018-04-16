#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <string>
#include "textures.h"
#include "sprites.h"
#include "gameobject.h"
#include "player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(688, 400), "SFML works!");

	Textures::Initialize();
	Sprites::Initialize();

	typedef std::list<Gameobject*> GameobjectList;

	GameobjectList gameobjects;

	typedef std::list<Component*> ComponentList;

	ComponentList components;

	components.push_back(new PlayerController());

	Gameobject player;

	player.components.push_back(new PlayerController());

	gameobjects.push_back(&player);


	for (GameobjectList::const_iterator iter = gameobjects.begin(),
		endIter = gameobjects.end();
		iter != endIter;
		++iter)
	{
		Gameobject *object = *iter;

		for (Gameobject::ComponentList::const_iterator comp_iter = object->components.begin(),
			comp_endIter = object->components.end();
			comp_iter != comp_endIter;
			++comp_iter)
		{
			Component *component = *comp_iter;
			component->Start();
		}
	}


	int map[1075];

	for (size_t i = 0; i < sizeof(map)/sizeof(map[0]); i++)
	{
		map[i] = i;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (GameobjectList::const_iterator iter = gameobjects.begin(),
			endIter = gameobjects.end();
			iter != endIter;
			++iter)
		{
			Gameobject *object = *iter;

			for (Gameobject::ComponentList::const_iterator comp_iter = object->components.begin(),
				comp_endIter = object->components.end();
				comp_iter != comp_endIter;
				++comp_iter)
			{
				Component *component = *comp_iter;
				component->Update();
				component->Draw(window);
			}
		}
		
		window.display();
		
		sf::sleep(sf::milliseconds(30));
	}

	return 0;
}