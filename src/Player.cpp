#include "Player.h"
#include "constants.h"
#include "World.hpp"
#include "mld.hpp"

namespace Fury
{
	Player::Player() : PhysicActor(nullptr)
	{
		orientation = Direction::South;
		SetPosition(sf::Vector2f((float)WINDOW_WIDTH / 6, (float)WINDOW_HEIGHT / 2));
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

	void Player::draw(sf::RenderTarget& target, sf::RenderStates& state)
	{
		target.draw(sprite);
	}
}
