#ifndef FURY_COLLISION_H
#define FURY_COLLISION_H

#include <SFML/System/Vector2.hpp>

namespace Fury
{
    class CircleShape;
    class PhysicBody;
    class RectangleShape;
    class Shape;

    class Collision final
    {
        public:
            static bool IsColliding(PhysicBody* first, PhysicBody* second, sf::Vector2f& minDisplacement);
            static sf::Vector2f Normalize(const sf::Vector2f& vec);
        private:
            static bool CircleToCircle(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement);
            static bool AABBToCircle(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement);
            static bool CircleToAABB(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement);
            static bool AABBToAABB(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement);
            static bool IsColliding(const CircleShape* circle, const sf::Vector2f& position1, const RectangleShape* rectangle, const sf::Vector2f& position2);
    };

} /* End of namespace Fury */

#endif // FURY_COLLISION_H
