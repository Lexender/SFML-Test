#include <SFML/Graphics.hpp>
#include "textures.h"


sf::Texture Textures::tex1;
sf::Texture Textures::tex2;
sf::Texture Textures::tileset;

int Textures::Initialize()
{
	tex1.loadFromFile("Textures\\tex1.png");
	tex2.loadFromFile("Textures\\tex2.png");
	tileset.loadFromFile("Textures\\tileset.png");

	return 0;
}