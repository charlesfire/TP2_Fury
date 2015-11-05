#ifndef FURY_PLAYER_H
#define FURY_PLAYER_H

#include "Actor.h"
#include "AnimatedSprite.h"
#include "Singleton.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>

namespace Fury 
{
	class Player final : public Actor, public Singleton<Player>
	{
		public:
			Player();
			~Player();
			void Shoot();
			sf::Time GetDelay()const;
		private:
			sf::Clock lastShotTime;
		    AnimatedSprite sprite;
			Direction orientation;
	};

} /* End of namespace Fury */

#endif // FURY_PLAYER_H
