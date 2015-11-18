#include "Ghost.h"
#include "mld.hpp"

namespace Fury
{
	Ghost::Ghost(World * world, sf::Vector2f spawnPosition) : Brawler(world,spawnPosition)
	{
		sprite.setColor(sf::Color::Red);
	}
}
