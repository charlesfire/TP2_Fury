#include "InGameState.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "Maze.h"
#include "Player.h"
#include "World.hpp"
#include "mld.hpp"

namespace Fury
{
    InGameState::InGameState(Game* game) : State(game)
    {

    }

    bool InGameState::Init()
    {
        world.AddActor<Room>();
        return true;
    }

    void InGameState::ManageInput(const sf::Window& window)
    {

    }

    void InGameState::Update()
    {
		world.Update();
    }

    void InGameState::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        target.draw(world);
    }
}
