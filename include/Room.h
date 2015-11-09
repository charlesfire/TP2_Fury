#ifndef FURY_ROOM_H
#define FURY_ROOM_H

#include <array>
#include <vector>
#include <SFML/Graphics/RenderStates.hpp>
#include "Actor.h"

namespace Fury
{
    class Wall;

    class Room final : public Actor
    {
        public:
            Room(World* world);
            ~Room() = default;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
            void Generate();
        private:
            std::vector<Wall*> walls;
    };
} /* End of namespace Fury */

#endif // FURY_ROOM_H
