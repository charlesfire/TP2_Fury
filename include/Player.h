#ifndef FURY_PLAYER_H
#define FURY_PLAYER_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "Direction.h"
#include "PhysicActor.h"
#include "Projectile.h"
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
			void Update();
			void Draw(sf::RenderTarget& target, sf::RenderStates state);
		private:
			Player();
			sf::Clock lastShotTime;
		    sf::Sprite sprite;
			Direction orientation;
			RectangleShape hitBox;
	};

} /* End of namespace Fury */

#endif // FURY_PLAYER_H
