#ifndef FURY_SNIPER_H
#define FURY_SNIPER_H

#include "Shooter.h"


namespace Fury 
{
	class Sniper : public Shooter
	{
		public:
			Sniper(World * world, sf::Vector2f spawnPosition);
			void Shoot(sf::Vector2f spawnPosition);
	};

} /* End of namespace Fury */

#endif // FURY_SNIPER_H
