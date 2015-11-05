#include "Room.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Wall.h"

namespace Fury
{
    Room::Room()
    {

    }


    void Room::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        for (auto wall : walls)
            target.draw(wall);
    }
}
