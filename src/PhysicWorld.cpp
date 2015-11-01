#include "PhysicWorld.h"
#include <algorithm>
#include "Collision.h"
#include "PhysicBody.h"

namespace Fury
{
    PhysicWorld::PhysicWorld() : bodies(), isSleeping(true)
    {

    }

    PhysicWorld::~PhysicWorld()
    {
        bodies.clear();
    }

    void PhysicWorld::Update()
    {
        isSleeping = true;
        for (auto body : bodies)
        {
            if (!body->IsSleeping())
            {
                isSleeping = false;
                body->Move(body->GetVelocity());
            }
        }
        for (auto it = bodies.begin(); it != bodies.end(); it++)
        {
            for (auto it2 = it + 1; it2 != bodies.end(); it2++)
            {
                Collision::IsColliding(*it, *it2);
            }
        }
    }

    void PhysicWorld::AddBody(PhysicBody* body)
    {
        bodies.push_back(body);
    }

    void PhysicWorld::RemoveBody(const PhysicBody* body)
    {
        bodies.erase(std::remove(bodies.begin(), bodies.end(), body), bodies.end());
    }

    bool PhysicWorld::IsSleeping() const
    {
        return isSleeping;
    }
}
