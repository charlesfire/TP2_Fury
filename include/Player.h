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
		void draw(sf::RenderTarget& target, sf::RenderStates state)const;
		sf::Time GetDelay()const;
		void Shoot();
		void SetWorld(World* world);
		void Update();
		int GetLife()const;
		void DropLife();
	private:
		Player();
		sf::Clock lastShotTime;
		sf::Sprite sprite;
		Direction orientation;
		RectangleShape hitBox;
		int nbLives;
	};

} /* End of namespace Fury */

#endif // FURY_PLAYER_H
