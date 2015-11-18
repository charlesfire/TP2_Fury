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
		//world->AddActor<Projectile>(PLAYER_BULLET_SPEED, atanf(spawnPosition.y/spawnPosition.x)*4, false, spawnPosition);
	}
} /* End of namespace Fury */
