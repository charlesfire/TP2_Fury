#include "Robot.h"
#include "mld.hpp"

namespace Fury
{
	Robot::Robot(World * world, sf::Vector2f spawnPosition) : PhysicActor(world)
	{
		SetPosition(spawnPosition);
	}

	void Robot::draw(sf::RenderTarget& target, sf::RenderStates& state)
	{
		target.draw(sprite);
	}

	void Robot::Update()
	{
		sprite.setPosition(GetPosition());
	}

	Robot::~Robot()
	{

	}
}
