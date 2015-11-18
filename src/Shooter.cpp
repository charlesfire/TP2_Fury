#include "Shooter.h"
#include "mld.hpp"

namespace Fury
{
	Shooter::Shooter(World * world, sf::Vector2f spawnPosition) : Robot(world, spawnPosition)
	{
		sprite.setColor(sf::Color::Cyan);
	}
}
