#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.h"

namespace Fury
{
    class CircleShape final : public Shape
    {
        public:
            CircleShape() = default;
            CircleShape(const float radius);
            virtual ~CircleShape() = default;
            float GetRadius()const;
            virtual Type GetType()const;
        private:
            float radius;
    };
}

#endif // CIRCLESHAPE_H
