#ifndef FURY_PLAYER_H
#define FURY_PLAYER_H

#include "Actor.h"
#include "AnimatedSprite.h"
#include "Singleton.h"


namespace Fury {

class Player : public Actor, public Singleton
{


 private:
    AnimatedSprite sprite;

};

} /* End of namespace Fury */

#endif // FURY_PLAYER_H
