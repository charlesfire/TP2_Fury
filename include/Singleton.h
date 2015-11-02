#ifndef FURY_SINGLETON_H
#define FURY_SINGLETON_H

#include "NonCopyable.h"

namespace Fury
{
    template<class T>
    class Singleton : private NonCopyable
    {
        public:
            static T& GetInstance()
            {
                static T instance;
                return instance;
            }
        protected:
            Singleton() = default;
    };
} /* End of namespace Fury */

#endif // FURY_SINGLETON_H
