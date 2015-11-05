#ifndef FURY_WORLD_HPP
#define FURY_WORLD_HPP

#include <type_traits>
#include <vector>
#include "mld.hpp"

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
                static_assert(std::is_base_of<Actor, T>::value, "Only class derived from Actor could be added to a world.");
                T* temp = new T(args...);
                actors.push_back(temp);
                return temp;
            }
        private:
            std::vector<Actor*> actors;
    };
}

#endif // FURY_WORLD_HPP
