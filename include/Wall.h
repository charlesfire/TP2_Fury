#ifndef FURY_WALL_H
#define FURY_WALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include "PhysicActor.h"
#include "RectangleShape.h"

namespace sf
{
    class RenderTarget;
}

namespace Fury
{
    class World;

    class Wall final : public PhysicActor
    {
        public:
            Wall(World* world, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f), const sf::Vector2f& size = sf::Vector2f(0.f, 0.f));
            ~Wall() = default;
            void draw(sf::RenderTarget& target, sf::RenderStates states)const;
            void SetSize(const sf::Vector2f& size);
        private:
            RectangleShape hitBox;
            sf::RectangleShape visual;
    };
} /* End of namespace Fury */

#endif // FURY_WALL_H
