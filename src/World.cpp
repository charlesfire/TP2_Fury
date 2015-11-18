#include "World.hpp"
#include <algorithm>
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

    bool World::RemoveActor(Actor* actor)
    {
        if (actors.find(actor) != actors.end())
        {
            actors.erase(actor);
            delete actor;
        }
        return false;
    }
	void World::Update()
	{
		for (auto actor : actors)
			actor->Update();
	}
}
