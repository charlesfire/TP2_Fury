#ifndef FURY_ROOM_H
#define FURY_ROOM_H

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "mld.hpp"

namespace Fury
{
    class Wall;

    class Room final : public sf::Drawable
    {
        public:
            Room();
            ~Room() = default;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        private:
            std::vector<Wall> walls;
    };
} /* End of namespace Fury */

#endif // FURY_ROOM_H
