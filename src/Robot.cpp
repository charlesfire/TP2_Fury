#include "Robot.h"
#include "mld.hpp"
#include "TextureManager.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace Fury
{
	static float speed;
	static sf::Clock spawnDelay;
	static sf::Texture robTexture;

	Robot::Robot(World * world, sf::Vector2f spawnPosition) : PhysicActor(world)
	{
		SetPosition(spawnPosition);
		sprite.setTexture(TextureManager::GetInstance().GetTexture("Sprites/RobotImmobile.png"));
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

	void Robot::ResetTimer()
	{
		spawnDelay.restart();
	}

	static int GetDelay()
	{
		return spawnDelay.getElapsedTime().asMilliseconds();
	}

	Robot::~Robot()
	{

	}
}
