#include "Projectile.h"
#include "Shape.h"
#include "TextureManager.hpp"
//using namespace sf;

namespace Fury
{
	Projectile::Projectile(const sf::Vector2f& speed) : hitCircle(5), sprite(), PhysicBody((Shape*)(&hitCircle))
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
