#include "Player.h"
#include "constants.h"
#include <windows.h>

namespace Fury
{
	Player::Player()
	{
		lastShotTime = GetTickCount();
	}
	int Player::GetDelay()
	{
		return GetTickCount() - lastShotTime;
	}
	void Player::Shoot()
	{
		if (GetDelay() > 250)
		{
			lastShotTime = GetTickCount();
			//Ajouter la fonction de tir ici
		}
	}
}
