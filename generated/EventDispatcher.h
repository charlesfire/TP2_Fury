#ifndef FURY_EVENTDISPATCHER_H
#define FURY_EVENTDISPATCHER_H

#include <vector>

#include "EventListener.h"


namespace Fury {

class EventDispatcher
{


 private:
    std::vector< EventListener* > listeners;

};

} /* End of namespace Fury */

#endif // FURY_EVENTDISPATCHER_H
