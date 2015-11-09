#include "Room.h"
#include <chrono>
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

    void Room::Generate()
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 2);
        for (unsigned int x(1); x < 5; x++)
        {
            for (unsigned int y(1); y < 3; y++)
            {
                Wall* temp = world->AddActor<Wall>(sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * x, (WALL_LENGTH - WALL_THICKNESS) * y));
                if (distribution(generator) == 1)
                    temp->SetSize(sf::Vector2f(WALL_THICKNESS, WALL_LENGTH));
                else
                    temp->SetSize(sf::Vector2f(WALL_LENGTH, WALL_THICKNESS));
                walls.push_back(temp);
            }
        }

        for (unsigned int x(0); x < 5; x++)
        {
            Wall* temp = world->AddActor<Wall>(sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * x, 0));
            if (x < 3)
                temp->SetSize(sf::Vector2f(WALL_LENGTH, -WALL_THICKNESS));
            if (x > 3)
                temp->SetSize(sf::Vector2f(WALL_LENGTH, WALL_THICKNESS));
            walls.push_back(temp);
        }

        for (unsigned int x(0); x < 5; x++)
        {
            Wall* temp = world->AddActor<Wall>(sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * x, (WALL_LENGTH - WALL_THICKNESS) * 4));
            if (x < 2)
                temp->SetSize(sf::Vector2f(WALL_LENGTH, -WALL_THICKNESS));
            if (x > 2)
                temp->SetSize(sf::Vector2f(WALL_LENGTH, WALL_THICKNESS));
            walls.push_back(temp);
        }
    }
}
