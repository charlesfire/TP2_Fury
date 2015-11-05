#include "Player.h"
#include "constants.h"

namespace Fury
{
	Player::Player()
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
			switch (orientation)
			{
				//TODO: Tir selon la direction du joueur
				case Direction::East:
					break;
				case Direction::North:
					break;
				case Direction::NorthEast:
					break;
				case Direction::NorthWest:
					break;
				case Direction::South:
					break;
				case Direction::SouthEast:
					break;
				case Direction::SouthWest:
					break;
				case Direction::West:
			}
		}
	}

	void Player::SetWorld(World * world)
	{
		this->world = world;
	}
}
