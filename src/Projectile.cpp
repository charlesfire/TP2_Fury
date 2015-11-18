#include "Projectile.h"
#include <cmath>
#include "Constants.h"
#include "Shape.h"
#include "TextureManager.hpp"
#include "World.hpp"

namespace Fury
{
	Projectile::Projectile(World * world, const float speed, const float _orientation, const bool isFromSniper, const sf::Vector2f position) : PhysicActor(world), hitCircle(5), sprite()
	{
		SetPosition(position);
		SetVelocity(sf::Vector2f((float)std::cos(M_PI * (_orientation/4) * speed), (float)std::sin(M_PI_4 * orientation * speed)));
		sprite.setTexture(TextureManager::GetInstance().GetTexture("Sprites/Balle.png"));
	}
	void Projectile::Update()
	{
		sprite.setPosition(GetPosition());
	}
	void Projectile::draw(sf::RenderTarget& target, sf::RenderStates state)const
	{
		target.draw(sprite);
	}
}
