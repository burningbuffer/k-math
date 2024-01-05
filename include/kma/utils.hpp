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

    std::ostream& operator<<(std::ostream& os, const kma::vec3& ivec)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.y << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.z << " ";
        std::cout << std::endl;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const kma::vec2& ivec)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << ivec.y << " ";
        std::cout << std::endl;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const kma::mat4& imat)
    {
		int c = 0;
		for (int i = 0; i < 16; i++)
		{
			if (c == 4)
			{
				std::cout << std::endl;
				c = 0;
			}

			std::cout
				<< std::setw(10)
				<< std::setprecision(6)
				<< std::fixed
				<< imat.matrixData[i] << " ";
			c++;
		}
		std::cout << std::endl;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const kma::quat& iquat)
    {
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.x << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.y << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.z << " ";
        std::cout << std::setw(10) << std::setprecision(6) << std::fixed << iquat.w << " ";
        std::cout << std::endl;
        return os;
    }

}