#ifndef FURY_PLAYER_H
#define FURY_PLAYER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "Direction.h"
#include "Projectile.h"
#include "PhysicActor.h"
#include "RectangleShape.h"
#include "Singleton.h"

namespace Fury
{
	class World;

	class Player final : public PhysicActor, public Singleton<Player>
	{
		public:
			~Player() = default;
			void Shoot();
			void SetWorld(World* world);
			sf::Time GetDelay()const;
		private:
			Player();
			sf::Clock lastShotTime;
		    sf::Sprite sprite;
			Direction orientation;
			RectangleShape hitBox;
	};

} /* End of namespace Fury */

#endif // FURY_PLAYER_H
