#ifndef FURY_GUNNER_H
#define FURY_GUNNER_H

#include "Shooter.h"


namespace Fury 
{
	class Gunner final : public Shooter
	{
		public:
			Gunner(World * world, sf::Vector2f spawnPosition);
			void Shoot(sf::Vector2f spawnPosition);
	};

} /* End of namespace Fury */

#endif // FURY_GUNNER_H
