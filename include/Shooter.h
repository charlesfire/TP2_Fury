#ifndef FURY_SHOOTER_H
#define FURY_SHOOTER_H

#include "Robot.h"


namespace Fury 
	{
		class Shooter : public Robot
		{
			public:
				Shooter(World * world, sf::Vector2f spawnPosition);
				virtual void Shoot(sf::Vector2f spawnPosition);
		};

	} /* End of namespace Fury */

#endif // FURY_SHOOTER_H
