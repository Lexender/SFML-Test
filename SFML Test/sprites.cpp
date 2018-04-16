#include <SFML/Graphics.hpp>
#include "textures.h"
#include "sprites.h"

sf::Sprite Sprites::spr1;
sf::Sprite Sprites::spr2;
sf::Sprite Sprites::tiles[1075];

int Sprites::Initialize()
{
	spr1.setTexture(Textures::tex1);
	spr1.setTextureRect(sf::IntRect(500, 500, 250, 150));
	spr2.setTexture(Textures::tex2);

	int length = sizeof(tiles) / sizeof(tiles[0]);
	int size = 16;
	int border = 2;

	int texHeight = 452;
	int texWidth = 776;

	int columns = (texWidth - border) / (size+border);
	int width = (texHeight - border) / (size+border);
	

	for (int i = 0; i < length; i++)
	{

		int column = i % columns;
		int row = i / columns;

		tiles[i].setTexture(Textures::tileset);
		tiles[i].setTextureRect(sf::IntRect(column * (size + border) + border , row * (size + border) + border, size, size));
	}

	return 0;
}
