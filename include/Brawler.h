#ifndef FURY_BRAWLER_H
#define FURY_BRAWLER_H

#include "Robot.h"
#include "PhysicActor.h"

namespace Fury 
{

	class Brawler : public Robot
	{
	public:
		Brawler(World * world, sf::Vector2f spawnPosition);
		~Brawler();
		void Move();
		void Shoot(sf::Vector2f spawnPosition);
	};

} /* End of namespace Fury */

#endif // FURY_BRAWLER_H
