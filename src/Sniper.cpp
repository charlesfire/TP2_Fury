#include "Sniper.h"
#include "mld.hpp"

namespace Fury
{
	Sniper::Sniper(World * world, sf::Vector2f spawnPosition) : Shooter(world,spawnPosition)
	{
		sprite.setColor(sf::Color::Green);
	}
	void Sniper::Shoot(sf::Vector2f spawnPosition)
	{
		
	}
} /* End of namespace Fury */
