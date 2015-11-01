#ifndef FURY_COLLISION_H
#define FURY_COLLISION_H

#include <functional>
#include <SFML/System/Vector2.hpp>
#include "Shape.h"

namespace Fury
{
    class PhysicBody;

    class Collision final
    {
        public:
            static bool IsColliding(PhysicBody* first, PhysicBody* second);
            static sf::Vector2f Normalize(const sf::Vector2f& vec);
        private:
            static const std::function<bool(PhysicBody*, PhysicBody*)> mapper[Shape::COUNT][Shape::COUNT];
    };

} /* End of namespace Fury */

#endif // FURY_COLLISION_H
