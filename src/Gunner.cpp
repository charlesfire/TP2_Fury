#include "Gunner.h"
#include "mld.hpp"

namespace Fury
{
	Gunner::Gunner(World * world, sf::Vector2f spawnPosition) : Shooter(world,spawnPosition)
	{
		sprite.setColor(sf::Color::Blue);
	}

	void Gunner::Shoot(sf::Vector2f spawnPosition)
	{
		
	}
}
