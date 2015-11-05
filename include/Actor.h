#ifndef FURY_ACTOR_H
#define FURY_ACTOR_H

#include <SFML/Graphics/Drawable.hpp>
#include "PhysicBody.h"

namespace Fury
{
    class World;

	class Actor : public PhysicBody, public sf::Drawable
	{
        public:
            Actor(World* world);
        protected:
            World* world;
	};

} /* End of namespace Fury */

#endif // FURY_ACTOR_H
