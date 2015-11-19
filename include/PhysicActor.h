#ifndef FURY_PHYSICACTOR_H
#define FURY_PHYSICACTOR_H

#include "Actor.h"
#include "PhysicBody.h"

namespace Fury
{
    class World;

    class PhysicActor : public Actor, public PhysicBody
    {
		public:
			virtual void Update();
			virtual void draw(sf::RenderTarget& target, sf::RenderStates& state)const;
        protected:
            PhysicActor(World* world);
    };
}

#endif // FURY_PHYSICACTOR_H
