#ifndef FURY_ACTOR_H
#define FURY_ACTOR_H

#include <SFML/Graphics/Drawable.hpp>

namespace Fury
{
    class World;

	class Actor : public sf::Drawable
	{
        public:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {}
			virtual void Update();
        protected:
            Actor(World* world);

            World* world;
	};

} /* End of namespace Fury */

#endif // FURY_ACTOR_H
