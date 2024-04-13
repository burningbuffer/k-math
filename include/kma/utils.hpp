#pragma once
#include <iostream>
#include <iomanip>

#define KMA_PI    3.141592653589793238f
#define KMA_INLINE __forceinline

namespace kma
{
    KMA_INLINE float radians(double iAngle)
    {
        return (float)(iAngle * KMA_PI / 180);
    }
    
    KMA_INLINE std::ostream& operator<<(std::ostream& os, const kma::vec4 & ivec)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.y << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.z << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.w << " ";
        std::cout << std::endl;
        return os;
    }

    KMA_INLINE std::ostream& operator<<(std::ostream& os, const kma::vec3& ivec)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.y << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.z << " ";
        std::cout << std::endl;
        return os;
    }

    KMA_INLINE std::ostream& operator<<(std::ostream& os, const kma::vec2& ivec)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.y << " ";
        std::cout << std::endl;
        return os;
    }

    KMA_INLINE std::ostream& operator<<(std::ostream& os, const kma::mat4& imat)
    {
		int c = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {


                std::cout
                    << std::setw(10)
                    << std::setprecision(6)
                    << std::fixed
                    << imat.matrix[i][j] << " ";
                c++;
            }

            std::cout << std::endl;
        }
        return os;
    }

    KMA_INLINE std::ostream& operator<<(std::ostream& os, const kma::quat& iquat)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.y << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.z << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.w << " ";
        std::cout << std::endl;
        return os;
    }

}