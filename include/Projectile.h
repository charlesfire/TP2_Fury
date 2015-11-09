#ifndef FURY_PROJECTILE_H
#define FURY_PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "CircleShape.h"
#include "PhysicActor.h"

namespace Fury
{
	class World;

	class Projectile : public PhysicActor
	{
	public:
		Projectile(World * world, const sf::Vector2f& speed);
		~Projectile() = default;
		void Update();
		void draw(sf::RenderTarget& target, sf::RenderStates state)const;
	private:
		sf::Sprite sprite;
		CircleShape hitCircle;
	};

} /* End of namespace Fury */

#endif // FURY_PROJECTILE_H
