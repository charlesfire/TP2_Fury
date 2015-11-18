#ifndef FURY_SHIELDBOT_H
#define FURY_SHIELDBOT_H

#include "Brawler.h"


namespace Fury 
{

	class Shieldbot : public Brawler
	{
		public:
			Shieldbot(World * world, sf::Vector2f spawnPosition);
			float GetShieldStrength()const;
			void PowerDown();
		private:
			float shieldPower;
	};

} /* End of namespace Fury */

#endif // FURY_SHIELDBOT_H
