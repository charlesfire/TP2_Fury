#ifndef EVENT_HPP
#define EVENT_HPP

namespace Fury
{
    class Event
    {
        public:
            virtual ~Event() = default;
        protected:
            Event() = default;
    };
}

#endif // EVENT_HPP
