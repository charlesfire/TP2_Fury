#include "InGameState.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "World.hpp"
#include "mld.hpp"

namespace Fury
{
    InGameState::InGameState(Game* game) : State(game)
    {

    }

    bool InGameState::Init()
    {
        return true;
    }

    void InGameState::ManageInput(const sf::Window& window)
    {

    }

    void InGameState::Update()
    {

    }

    void InGameState::draw(sf::RenderTarget& target, sf::RenderStates states)const
    {
        target.draw(world);
    }
}
