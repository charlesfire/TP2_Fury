#include "Room.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Wall.h"
#include "mld.hpp"

namespace Fury
{
    Room::Room() : pillars(), walls()
    {

    }

    void Room::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        for (auto wall : walls)
            target.draw(wall);
    }

    void Room::Generate()
    {

    }
}
