#include "Wall.h"
#include <SFML/Graphics/RenderTarget.hpp>

namespace Fury
{
    Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size) : hitBox(size), visual(size)
    {
        SetShape(hitBox);
    }

    void Wall::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        target.draw(visual);
    }
} /* End of namespace Fury */
