#ifndef FURY_ROOM_H
#define FURY_ROOM_H

#include <array>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "Wall.h"

namespace Fury
{
    class Room final : public sf::Drawable
    {
        public:
            Room();
            ~Room() = default;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
            void Generate();
        private:
            std::vector<Wall> pillars;
            std::vector<Wall> walls;
    };
} /* End of namespace Fury */

#endif // FURY_ROOM_H
