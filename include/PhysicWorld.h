#ifndef PHYSICWORLD_H
#define PHYSICWORLD_H

#include <vector>

namespace Fury
{
    class PhysicBody;

    class PhysicWorld
    {
        public:
            PhysicWorld();
            virtual ~PhysicWorld();
            void Update();
            void AddBody(PhysicBody* body);
            void RemoveBody(const PhysicBody* body);
            bool IsSleeping()const;
        private:
            std::vector<PhysicBody*> bodies;
            bool isSleeping;
    };
}

#endif // PHYSICWORLD_H
