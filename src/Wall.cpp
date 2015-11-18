#include "Wall.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "mld.hpp"

namespace Fury
{
    Wall::Wall(World* world, const sf::Vector2f& position, const sf::Vector2f& size) : hitBox(size), visual(size), PhysicActor(world)
    {
        SetShape(hitBox);
        visual.setFillColor(sf::Color::Black);
        visual.setPosition(position);
    }

    void Wall::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        target.draw(visual);
    }

    void Wall::SetSize(const sf::Vector2f& size)
    {
        visual.setSize(size);
        hitBox.SetSize(size);
    }
	void Wall::Update()
	{

	}
} /* End of namespace Fury */
