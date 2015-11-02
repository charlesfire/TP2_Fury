#ifndef FURY_PROJECTILE_H
#define FURY_PROJECTILE_H
#include "PhysicBody.h"
#include "CircleShape.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace Fury 
{
	class Projectile : public PhysicBody, public sf::Drawable
	{
		public:
			Projectile(const sf::Vector2f& speed);
			~Projectile() = default;
			void Update();
			void draw(sf::RenderTarget& target, sf::RenderStates state)const;
		private:
			sf::Sprite sprite;
			CircleShape hitCircle;
	};

} /* End of namespace Fury */

#endif // FURY_PROJECTILE_H
