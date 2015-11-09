#include "Room.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Constants.h"
#include "Wall.h"
#include "World.hpp"
#include "mld.hpp"

namespace Fury
{
    Room::Room(World* world) : walls(), Actor(world)
    {
        Generate();
    }

    void Room::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        for (auto wall : walls)
            target.draw(*wall);
    }

    void Room::Generate()
    {
        for (unsigned int x(0); x < 6; x++)
        {
            for (unsigned int y(0); y < 4; y++)
            {
                Wall* temp = world->AddActor<Wall>(sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * x, (WALL_LENGTH - WALL_THICKNESS) * y));
                temp->SetSize(sf::Vector2f(WALL_THICKNESS, WALL_LENGTH));
                walls.push_back(temp);
            }
        }
    }
}
