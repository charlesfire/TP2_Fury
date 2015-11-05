#include "PhysicBody.h"
#include <stdexcept>

namespace Fury
{
    PhysicBody::PhysicBody(const Shape* const shape, const sf::Vector2f& position) : position(position), shape(shape), isSleeping(true), isStatic(false)
    {

    }

    void PhysicBody::Impulse(const sf::Vector2f& impulse)
    {
        velocity += impulse;
        isSleeping = false;
    }

    bool PhysicBody::IsSleeping() const
    {
        return isSleeping;
    }

    bool PhysicBody::IsStatic() const
    {
        return isStatic;
    }

    void PhysicBody::Move(const sf::Vector2f& offset)
    {
        position += offset;
    }

    void PhysicBody::SetIsStatic(const bool isStatic)
    {
        this->isStatic = isStatic;
        if (isStatic)
            velocity = sf::Vector2f(0, 0);
    }

    void PhysicBody::SetPosition(const sf::Vector2f& position)
    {
        this->position = position;
    }

    void PhysicBody::SetVelocity(const sf::Vector2f& velocity)
    {
        if (!isStatic)
        {
            this->velocity = velocity;
            isSleeping = (velocity.x == 0.f && velocity.y == 0.f);
        }
    }

    const sf::Vector2f& PhysicBody::GetPosition() const
    {
        return position;
    }

    const sf::Vector2f& PhysicBody::GetVelocity()const
    {
        return velocity;
    }

    const Shape* PhysicBody::GetShape() const
    {
        return shape;
    }
}
