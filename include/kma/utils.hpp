#pragma once
#include <iostream>

#define KMA_PI    3.141592654f

namespace kma
{
    inline float radians(double iAngle)
    {
        return (float)(iAngle * KMA_PI / 180);
    }

    std::ostream& operator<<(std::ostream& os, const kma::vec4 & ivec)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.y << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.z << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.w << " ";
        std::cout << std::endl;
        return os;
    }


}