#ifndef FURY_NONCOPYABLE_H
#define FURY_NONCOPYABLE_H

namespace Fury
{
    class NonCopyable
    {
        protected:
            NonCopyable() = default;
        private:
            NonCopyable(const NonCopyable& other) = delete;
            NonCopyable& operator=(const NonCopyable& other) = delete;
    };
}

#endif // FURY_NONCOPYABLE_H
