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
		if (lastShotTime.getElapsedTime().asMilliseconds > 250)
		{
			lastShotTime.restart();
			//Ajouter la fonction de tir ici
		}
	}
}
