#ifndef FURY_ROBOT_H
#define FURY_ROBOT_H

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "PhysicActor.h"


namespace Fury 
{

	class Robot : public PhysicActor
	{
		public: 
			sf::Time GetDelay()const;
			void draw(sf::RenderTarget& target, sf::RenderStates& state);
			void Update();
			Robot(World * world, sf::Vector2f spawnPosition);
			void SetSpeed(const int nbRobots);
			void ResetTimer();
			int GetDelay();
			virtual void Shoot(sf::Vector2f orientation) = 0;
			~Robot();
		protected:
			sf::Sprite sprite;
			sf::Clock lastShotTime;
	};

} /* End of namespace Fury */

#endif // FURY_ROBOT_H
