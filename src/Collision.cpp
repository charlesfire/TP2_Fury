#include "Collision.h"
#include <cassert>
#include <cmath>
#include <functional>
#include "CircleShape.h"
#include "PhysicBody.h"
#include "RectangleShape.h"
#include "Shape.h"

namespace Fury
{
    bool Collision::IsColliding(PhysicBody* first, PhysicBody* second, sf::Vector2f& minDisplacement)
    {
        static const std::function<bool(PhysicBody*, const Shape*, PhysicBody*, const Shape*, sf::Vector2f&)> mapper[Shape::COUNT][Shape::COUNT] =
        {
            {&CircleToCircle, &AABBToCircle},
            {&CircleToAABB, &AABBToAABB}
        };

        const Shape* firstShape = first->GetShape();
        const Shape* secondShape = second->GetShape();

        assert(firstShape != nullptr);
        assert(secondShape != nullptr);

        return mapper[firstShape->GetType()][secondShape->GetType()](first, firstShape, second, secondShape, minDisplacement);
    }

    sf::Vector2f Collision::Normalize(const sf::Vector2f& vec)
    {
        float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);

        if (length == 0.0f)
            return sf::Vector2f(0.0f, 0.0f);
        return vec/length;
    }

    bool Collision::CircleToCircle(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement)
    {
        const CircleShape* circle1 = static_cast<const CircleShape*>(first->GetShape());
        const CircleShape* circle2 = static_cast<const CircleShape*>(second->GetShape());
        const float radius1 = circle1->GetRadius();
        const float radius2 = circle2->GetRadius();

        sf::Vector2f currentDist = second->GetPosition() - first->GetPosition();

        if (!((currentDist.x) * (currentDist.x) + (currentDist.y) * (currentDist.y) <= (radius1 + radius2) * (radius1 + radius2)))
            return false;

        sf::Vector2f norm = Normalize(currentDist);
        sf::Vector2f expectedDist = norm * (radius1 + radius2);
        minDisplacement = norm - expectedDist;

        return true;
    }

    bool Collision::AABBToCircle(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement)
    {
        return AABBToCircle(second, secondShape, first, firstShape, minDisplacement);
    }

    bool Collision::CircleToAABB(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement)
    {
        const CircleShape* circle = static_cast<const CircleShape*>(firstShape);
        const RectangleShape* aabb = static_cast<const RectangleShape*>(secondShape);
        sf::Vector2f position1 = first->GetPosition();
        sf::Vector2f position2 = second->GetPosition();
        sf::Vector2f boxHalfSize = aabb->GetHalfSize();

        if (!IsColliding(circle, position1, aabb, position2))
            return false;

        //TODO : set minDisplacement
        /*
        sf::Vector2f nearestPoint =  position1 - position2;
        nearestPoint.x = std::min(std::max(nearestPoint.x, -boxHalfSize.x), boxHalfSize.x);
        nearestPoint.y = std::min(std::max(nearestPoint.y, -boxHalfSize.y), boxHalfSize.y);
        nearestPoint += position2;

        float smallestX = std::min(nearestPoint.x - (position2.x - boxHalfSize.x), (position2.x + boxHalfSize.x) - nearestPoint.x);
        float smallestY = std::min(nearestPoint.y - (position2.y - boxHalfSize.y), (position2.y + boxHalfSize.y) - nearestPoint.y);
        if (smallestX < smallestY)
        {
            if (velocity1.x < 0.f)
                firstShape->SetPosition(sf::Vector2f(nearestPoint.x + circle->GetRadius(), position1.y));
            else
                firstShape->SetPosition(sf::Vector2f(nearestPoint.x - circle->GetRadius(), position1.y));
        }
        else
        {
            if (velocity1.y < 0.f)
                firstShape->SetPosition(sf::Vector2f(position1.x, nearestPoint.y + circle->GetRadius()));
            else
                firstShape->SetPosition(sf::Vector2f(position1.x, nearestPoint.y - circle->GetRadius()));
        }*/

        return true;
    }

    bool Collision::AABBToAABB(PhysicBody* first, const Shape* firstShape, PhysicBody* second, const Shape* secondShape, sf::Vector2f& minDisplacement)
    {
        const RectangleShape* aabb1 = static_cast<const RectangleShape*>(first->GetShape());
        const RectangleShape* aabb2 = static_cast<const RectangleShape*>(second->GetShape());
        sf::Vector2f position1 = first->GetPosition();
        sf::Vector2f position2 = second->GetPosition();
        sf::Vector2f min1 = position1 - aabb1->GetHalfSize();
        sf::Vector2f min2 = position2 - aabb2->GetHalfSize();
        sf::Vector2f max1 = position1 + aabb1->GetHalfSize();
        sf::Vector2f max2 = position2 + aabb2->GetHalfSize();

        if(!(max1.x < min2.x || max2.y < min2.y || min1.x > max2.x || min1.y > max2.y))
            return false;

        minDisplacement.y = (max1.x - min2.x < max2.x - min1.x)? max1.x - min2.x : max2.x - min1.x;
        minDisplacement.y = (max1.y - min2.y < max2.y - min1.y)? max1.y - min2.y : max2.y - min1.y;

        if (std::abs(minDisplacement.x) > std::abs(minDisplacement.y))
            minDisplacement.x = 0.f;
        else
            minDisplacement.y = 0.f;

        return true;
    }

    bool Collision::IsColliding(const CircleShape* circle, const sf::Vector2f& position1, const RectangleShape* rectangle, const sf::Vector2f& position2)
    {
        sf::Vector2f nearestPoint =  position1 - position2;
        sf::Vector2f boxHalfSize = rectangle->GetHalfSize();
        nearestPoint.x = std::min(std::max(nearestPoint.x, -boxHalfSize.x), boxHalfSize.x);
        nearestPoint.y = std::min(std::max(nearestPoint.y, -boxHalfSize.y), boxHalfSize.y);
        nearestPoint += position2;
        return ((position1.x - nearestPoint.x) * (position1.x - nearestPoint.x) +
               (position1.y - nearestPoint.y) * (position1.y - nearestPoint.y) <=
               (circle->GetRadius() * circle->GetRadius()));
    }
}
