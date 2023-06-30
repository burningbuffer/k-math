#include <iostream>
#include "vec4.h"
namespace gym
{

	vec4::vec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
		
	}
	
	vec4::vec4(float uX, float uY, float uZ, float uW)
	{
		x = uX;
		y = uY;
		z = uZ;
		w = uW;
	}
	
	
	vec4& vec4::operator=(const vec4& ivec)
	{
		x = ivec.x;
		y = ivec.y;
		z = ivec.z;
		w = ivec.w;

		return *this;
	}

	void vec4::operator+=(const vec4& ivec)
	{
		x += ivec.x;
		y += ivec.y;
		z += ivec.z;
		w += ivec.w;
	}

	vec4 vec4::operator+(const vec4& ivec)const
	{
		return vec4(x + ivec.x, y + ivec.y, z + ivec.z, w + ivec.w);
	}

	void vec4::operator-=(const vec4& ivec)
	{
		x -= ivec.x;
		y -= ivec.y;
		z -= ivec.z;
		w -= ivec.w;
	}

	vec4 vec4::operator-(const vec4& ivec)const
	{
		return vec4(x - ivec.x, y - ivec.y, z - ivec.z, w - ivec.w);
	}

	void vec4::operator*=(const vec4& ivec)
	{
		x *= ivec.x;
		y *= ivec.y;
		z *= ivec.z;
		w *= ivec.w;
	}

	vec4 vec4::operator*(const float s)const
	{
		return vec4(s * x, s * y, s * z, s * w);
	}

	vec4 vec4::operator*(const vec4& ivec)
	{
		return vec4( x * ivec.x, y * ivec.y, z * ivec.z, w * ivec.w);
	}
	
	void vec4::operator/=(const vec4& ivec)
	{
		x /= ivec.x;
		y /= ivec.y;
		z /= ivec.z;
		z /= ivec.w;
	}

	vec4 vec4::operator/(const vec4& ivec)const
	{
		return vec4(x / ivec.x, y / ivec.y, z / ivec.z, w / ivec.w);
	}

	vec4 vec4::cross(const vec4& ivec)const
	{
		return vec4(y * ivec.z - z * ivec.y,
					z * ivec.x - x * ivec.z,
					x * ivec.y - y * ivec.x,
					1);
	}

	void vec4::operator%=(const vec4& ivec)
	{
		*this = cross(ivec);
	}

	vec4 vec4::operator%(const vec4& ivec)const
	{
		return vec4(y * ivec.z - z * ivec.y,
					z * ivec.x - x * ivec.z,
					x * ivec.y - y * ivec.x,
					1);
	}
	
	vec4 vec4::operator*(const gym::mat4& m) 
	{
		vec4 nv;
		nv.x = x * m.matrixData[0] + y * m.matrixData[1] + z * m.matrixData[2] + w * m.matrixData[3];
		nv.y = x * m.matrixData[4] + y * m.matrixData[5] + z * m.matrixData[6] + w * m.matrixData[7];
		nv.z = x * m.matrixData[8] + y * m.matrixData[9] + z * m.matrixData[10] + w * m.matrixData[11];
		nv.w = x * m.matrixData[12] + y * m.matrixData[13] + z * m.matrixData[14] + w * m.matrixData[15];
		return nv;
	}
	
	float vec4::magnitude()
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	vec4 vec4::normalize()
	{
		float mag = std::sqrt(x * x + y * y + z * z);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;

		}
		return (*this);
	}

	vec4 vec4::normalizeQ()
	{
		float mag = std::sqrt(y * y + z * z + w * w);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;

		}
		return (*this);
	}

	void vec4::show()
	{
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << x << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << y << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << z << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << w << " ";
		std::cout << std::endl;

	}
}