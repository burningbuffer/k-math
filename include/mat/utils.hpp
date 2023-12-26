#include <iostream>
#include <corecrt_math_defines.h>



namespace mat
{
    inline float radians(double iAngle)
    {
        return (float)(iAngle * M_PI / 180);
    }

    std::ostream& operator<<(std::ostream& os, const mat::vec4 & ivec)
    {
        std::cout << "(" << ivec.x << " " << ivec.y << " " << ivec.z << " " << ivec.w << ")";
        return os;
    }


}