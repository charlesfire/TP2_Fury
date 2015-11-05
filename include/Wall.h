#ifndef FURY_WALL_H
#define FURY_WALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "mld.hpp"
#include "Actor.h"
#include "RectangleShape.h"

namespace sf
{
    class RenderTarget;
}

namespace Fury
{
    class Wall final : public Actor
    {
        public:
            Wall(const sf::Vector2f& position = sf::Vector2f(0.f, 0.f), const sf::Vector2f& size = sf::Vector2f(0.f, 0.f));
            ~Wall() = default;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        private:
            RectangleShape hitBox;
            sf::RectangleShape visual;
    };
} /* End of namespace Fury */

#endif // FURY_WALL_H
