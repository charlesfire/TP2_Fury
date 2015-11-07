#include "Room.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Wall.h"
#include "World.hpp"
#include "mld.hpp"

namespace Fury
{
    Room::Room(World* world) : pillars(), walls(), Actor(world)
    {
        pillars.push_back(world->AddActor<Wall>(sf::Vector2f(0, 0), sf::Vector2f(15.f, 15.f)));
    }

    void Room::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        for (auto pillar : pillars)
            target.draw(*pillar);
        for (auto wall : walls)
            target.draw(*wall);
    }

    void Room::Generate()
    {

    }
}
