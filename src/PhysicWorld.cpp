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
            if (!body->IsSleeping() && !body->IsStatic())
            {
                isSleeping = false;
                body->Move(body->GetVelocity());
            }
        }
        for (auto it = bodies.begin(); it != bodies.end(); it++)
        {
            if (!(*it)->IsSleeping() && !(*it)->IsStatic())
            {
                for (auto it2 = it + 1; it2 != bodies.end(); it2++)
                {
                    sf::Vector2f minDisplacement;
                    if (Collision::IsColliding(*it, *it2, minDisplacement))
                    {
                        if ((*it2)->IsStatic())
                            (*it)->Move(minDisplacement);
                        else
                        {
                            (*it)->Move(-minDisplacement / 2.f);
                            (*it2)->Move(-minDisplacement / 2.f);
                        }
                    }
                }
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
