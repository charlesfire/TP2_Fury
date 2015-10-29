#ifndef FURY_SINGLETON_H
#define FURY_SINGLETON_H

#include "NonCopyable.h"

namespace Fury
{
    template<class T>
    class Singleton : NonCopyable
    {
        public:
            T& GetInstance()const
            {
                static T instance;
                return instance;
            }
        protected:
            Singleton() = default;
    };
} /* End of namespace Fury */

#endif // FURY_SINGLETON_H
