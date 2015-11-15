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
        for (unsigned int x(1); x < NB_HORIZONTAL_WALL; x++)
        {
            for (unsigned int y(1); y < NB_VERTICAL_WALL; y++)
            {
                Wall* temp = world->AddActor<Wall>(sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * x, (WALL_LENGTH - WALL_THICKNESS) * y));
                if (distribution(generator) == 1)
                    temp->SetSize(sf::Vector2f(WALL_THICKNESS, WALL_LENGTH));
                else
                    temp->SetSize(sf::Vector2f(WALL_LENGTH, WALL_THICKNESS));
                walls.push_back(temp);
            }
        }

        for (unsigned int x(0); x < NB_HORIZONTAL_WALL; x++)
        {
            Wall* temp = nullptr;
            if (x != NB_HORIZONTAL_WALL/2)
            {
                sf::Vector2f position((WALL_LENGTH - WALL_THICKNESS) * x, 0);
                walls.push_back(world->AddActor<Wall>(position, sf::Vector2f(WALL_LENGTH, WALL_THICKNESS)));
                position = sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * x, (WALL_LENGTH - WALL_THICKNESS) * NB_VERTICAL_WALL);
                walls.push_back(world->AddActor<Wall>(position, sf::Vector2f(WALL_LENGTH, WALL_THICKNESS)));
            }
        }

        for (unsigned int y(0); y < NB_VERTICAL_WALL; y++)
        {
            Wall* temp = nullptr;
            if (y != NB_VERTICAL_WALL/2)
            {
                sf::Vector2f position(0, (WALL_LENGTH - WALL_THICKNESS) * y);
                walls.push_back(world->AddActor<Wall>(position, sf::Vector2f(WALL_THICKNESS, WALL_LENGTH)));
                position = sf::Vector2f((WALL_LENGTH - WALL_THICKNESS) * NB_HORIZONTAL_WALL, (WALL_LENGTH - WALL_THICKNESS) * y);
                walls.push_back(world->AddActor<Wall>(position, sf::Vector2f(WALL_THICKNESS, WALL_LENGTH)));
            }
        }
    }
}
