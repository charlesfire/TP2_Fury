#ifndef FURY_ACTOR_H
#define FURY_ACTOR_H

#include <SFML/Graphics/Drawable.hpp>
#include "PhysicBody.h"

namespace Fury 
{
	class Actor : public PhysicBody, public sf::Drawable
	{
	};

} /* End of namespace Fury */

#endif // FURY_ACTOR_H
