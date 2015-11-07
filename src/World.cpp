#include "World.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Actor.h"
#include "mld.hpp"

namespace Fury
{
    void World::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        for (auto actor : actors)
            target.draw(*actor, states);
    }
}
