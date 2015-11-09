#include "Projectile.h"
#include "Shape.h"
#include "TextureManager.hpp"
#include "World.hpp"

namespace Fury
{
	Projectile::Projectile(World * world, const float speed, const Direction _orientation) : hitCircle(5), sprite(), PhysicActor(world)
	{
		SetVelocity(sf::Vector2f((float)cos(M_PI_4*orientation*speed), (float)sin(M_PI_4*orientation*speed)));
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
