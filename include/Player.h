#ifndef FURY_PLAYER_H
#define FURY_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "AnimatedSprite.h"
#include "Direction.h"
#include "Projectile.h"
#include "RectangleShape.h"
#include "Singleton.h"

namespace Fury 
{
	class World;

	class Player final : public Actor, public Singleton<Player>
	{
		public:
			~Player() = default;
			void Shoot();
			void SetWorld(World* world);
			sf::Time GetDelay()const;
		private:
			Player();
			sf::Clock lastShotTime;
		    AnimatedSprite sprite;
			Direction orientation;
			RectangleShape hitBox;
	};

} /* End of namespace Fury */

#endif // FURY_PLAYER_H
