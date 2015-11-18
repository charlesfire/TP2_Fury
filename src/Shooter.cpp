#include "Projectile.h"
#include "Direction.h"
#include "Shooter.h"
#include "mld.hpp"

namespace Fury
{
	Shooter::Shooter(World * world, sf::Vector2f spawnPosition) : Robot(world, spawnPosition)
	{
		sprite.setColor(sf::Color::Cyan);
		
	}
	void Shooter::Shoot(sf::Vector2f spawnPosition)
	{
		//world->AddActor<Projectile>(PLAYER_BULLET_SPEED, atanf(spawnPosition.y/spawnPosition.x)*4, false, spawnPosition);
	}
}
