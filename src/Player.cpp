#include "Player.h"
#include "constants.h"
#include "World.hpp"
#include "mld.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace Fury
{
	Player::Player() : PhysicActor(nullptr)
	{
		orientation = Direction::South;
	}

	sf::Time Player::GetDelay()const
	{
		return lastShotTime.getElapsedTime();
	}

	void Player::Shoot()
	{
		if (lastShotTime.getElapsedTime().asMilliseconds() > PLAYER_SHOT_DELAY)
		{
			lastShotTime.restart();
			world->AddActor<Projectile>(PLAYER_BULLET_SPEED, orientation);
		}
	}

	void Player::SetWorld(World * world)
	{
		this->world = world;
	}

	void Player::Update()
	{
		sprite.setPosition(GetPosition());
	}

	void Player::Draw(sf::RenderTarget& target, sf::RenderStates state)
	{
		target.draw(sprite);
	}
}
