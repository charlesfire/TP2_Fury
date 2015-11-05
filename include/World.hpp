#ifndef FURY_WORLD_HPP
#define FURY_WORLD_HPP

#include <vector>

namespace Fury
{
    class Actor;

    class World final
    {
        public:
            World() = default;
            ~World() = default;
            template<class T, class ...Args>
            T* AddActor(Args... args)
            {
                T* temp = new T(args...);
                actors.push_back(temp);
                return temp;
            }
        private:
            std::vector<Actor*> actors;
    };
}

#endif // FURY_WORLD_HPP
