#include "Shieldbot.h"
#include "mld.hpp"

namespace Fury
{
	Shieldbot::Shieldbot(World * world, sf::Vector2f spawnPosition) : Brawler(world,spawnPosition)
	{
		sprite.setColor(sf::Color::Magenta);
		shieldPower = 100;
	}
	void Shieldbot::PowerDown()
	{
		shieldPower *= 0.5f;
	}
}
