#ifndef FURY_INGAMESTATE_H
#define FURY_INGAMESTATE_H

#include "EventDispatcher.h"
#include "State.h"

namespace Fury
{
    class Game;

    class InGameState final : public State
    {
        public:
            InGameState(Game* game);
            bool Init();
            void ManageInput(const sf::Window& window);
            void Update();
            void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        private:
            EventDispatcher eventDispatcher;
    };
} /* End of namespace Fury */

#endif // FURY_INGAMESTATE_H
