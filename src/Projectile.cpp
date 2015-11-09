#include "Projectile.h"
#include "Shape.h"
#include "TextureManager.hpp"
#include "World.hpp"

namespace Fury
{
	Projectile::Projectile(World * world, const sf::Vector2f& speed) : hitCircle(5), sprite()
	{
		SetVelocity(speed);
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
