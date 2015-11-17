#ifndef FURY_WORLD_HPP
#define FURY_WORLD_HPP

#include <set>
#include <type_traits>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace sf
{
    class RenderTarget;
}

namespace Fury
{
    class Actor;

    class World final : public sf::Drawable
    {
        public:
            World() = default;
            ~World() = default;

            template<class T, class ...Args>
            T* AddActor(Args... args)
            {
                static_assert(std::is_base_of<Actor, T>::value, "Only class derived from Actor could be added to a world.");
                T* temp = new T(this, args...);
                actors.insert(temp);
                return temp;
            }

            bool RemoveActor(Actor* actor);
			void Update();
            void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        private:
            std::set<Actor*> actors;
    };
}

#endif // FURY_WORLD_HPP
