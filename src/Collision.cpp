#include "Collision.h"
#include <cmath>

namespace Fury
{
    bool Collision::IsColliding(PhysicBody* first, PhysicBody* second)
    {
        return true;
    }

    sf::Vector2f Collision::Normalize(const sf::Vector2f& vec)
    {
        float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);

        if (length == 0.0f)
            return sf::Vector2f(0.0f, 0.0f);
        return vec/length;
    }
}
