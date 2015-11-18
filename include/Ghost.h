#ifndef FURY_JUGGERNAUT_H
#define FURY_JUGGERNAUT_H

#include "Brawler.h"


namespace Fury 
{

	class Ghost : public Brawler
	{
		Ghost(World * world, sf::Vector2f spawnPosition);
	};

} /* End of namespace Fury */

#endif // FURY_JUGGERNAUT_H
