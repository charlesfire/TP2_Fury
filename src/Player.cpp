#include "Player.h"
#include "constants.h"
#include "World.hpp"
#include "mld.hpp"

namespace Fury
{
	Player::Player() : Actor(nullptr)
	{
		orientation = Direction::South;
	}

	sf::Time Player::GetDelay()const
	{
		return lastShotTime.getElapsedTime();
	}

	void Player::Shoot()
	{
		if (lastShotTime.getElapsedTime().asMilliseconds() > PLAYER_SHOT_DELAY)
		{
			lastShotTime.restart();
			world->AddActor<Projectile>(PLAYER_BULLET_SPEED, orientation);
		}
	}

	void Player::SetWorld(World * world)
	{
		this->world = world;
	}
}
