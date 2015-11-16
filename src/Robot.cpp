#include "Robot.h"
#include "mld.hpp"

namespace Fury
{
	static float speed;

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

	void Robot::SetSpeed(const int nbRobots)
	{
		speed = ROBOT_MAX_SPEED / (float)nbRobots;
	}

	Robot::~Robot()
	{

	}
}
