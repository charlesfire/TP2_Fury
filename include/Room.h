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
            ~Room();
        private:
            void Generate();
			void Populate();
			virtual void Update();
            std::vector<Wall*> walls;
    };
} /* End of namespace Fury */

#endif // FURY_ROOM_H
