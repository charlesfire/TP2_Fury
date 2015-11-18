#include "Brawler.h"
#include "mld.hpp"
#include <iostream>

namespace Fury
{
	Brawler::Brawler(World * world, sf::Vector2f spawnPosition) : Robot(world,spawnPosition)
	{
		sprite.setColor(sf::Color::Yellow);
	}

	Brawler::~Brawler()
	{

	}
}
