#include "Player.h"
#include "constants.h"

namespace Fury
{
	Player::Player()
	{
		
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
			//Ajouter la fonction de tir ici
		}
	}
}
