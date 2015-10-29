#ifndef FURY_INGAMESTATE_H
#define FURY_INGAMESTATE_H

#include "EventDispatcher.h"
#include "State.h"


namespace Fury {

class InGameState : public State
{


 private:
    EventDispatcher eventDispatcher;

};

} /* End of namespace Fury */

#endif // FURY_INGAMESTATE_H
