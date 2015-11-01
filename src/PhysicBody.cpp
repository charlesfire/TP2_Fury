#include "PhysicBody.h"
#include <stdexcept>

namespace Fury
{
    PhysicBody::PhysicBody(const Shape* const shape, const sf::Vector2f& position) : shape(shape), position(position), isSleeping(true)
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

    void PhysicBody::Move(const sf::Vector2f& offset)
    {
        position += offset;
    }

    void PhysicBody::SetPosition(const sf::Vector2f& position)
    {
        this->position = position;
    }

    void PhysicBody::SetVelocity(const sf::Vector2f& velocity)
    {
        this->velocity = velocity;
        isSleeping = (velocity.x == 0.f && velocity.y == 0.f);
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
