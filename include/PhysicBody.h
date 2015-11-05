#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <SFML/System/Vector2.hpp>

namespace Fury
{
    class Shape;

    class PhysicBody
    {
        public:
            PhysicBody(const Shape* const shape = nullptr, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f));
            virtual ~PhysicBody() = default;
            void Impulse(const sf::Vector2f& impulse);
            bool IsSleeping()const;
            bool IsStatic()const;
            void Move(const sf::Vector2f& offset);
            void SetIsStatic(const bool isStatic);
            void SetPosition(const sf::Vector2f& position);
            void SetVelocity(const sf::Vector2f& velocity);
            const sf::Vector2f& GetPosition()const;
            const sf::Vector2f& GetVelocity()const;
            const Shape* GetShape()const;
        protected:
            sf::Vector2f position;
            const Shape* shape;
        private:
            bool isSleeping;
            bool isStatic;
            sf::Vector2f velocity;
    };
}

#endif // PHYSICBODY_H
