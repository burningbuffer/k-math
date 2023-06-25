#include <iostream>
#include "vec4.h"
namespace gym
{

	vec4::vec4()
	{
		v[0] = 0.0f;
		v[1] = 0.0f;
		v[2] = 0.0f;
		v[3] = 0.0f;
		
	}
	
	vec4::vec4(float uX, float uY, float uZ, float uW)
	{
		v[0] = uX;
		v[1] = uY;
		v[2] = uZ;
		v[3] = uW;
	}
	
	
	vec4& vec4::operator=(const vec4& ivec)
	{
		v[0] = ivec.v[0];
		v[1] = ivec.v[1];
		v[2] = ivec.v[2];
		v[3] = ivec.v[3];

		return *this;
	}

	void vec4::operator+=(const vec4& ivec)
	{
		v[0] += ivec.v[0];
		v[1] += ivec.v[1];
		v[2] += ivec.v[2];
		v[3] += ivec.v[3];
	}

	vec4 vec4::operator+(const vec4& ivec)const
	{
		return vec4(v[0] + ivec.v[0], v[1] + ivec.v[1], v[2] + ivec.v[2], v[3] + ivec.v[3]);
	}

	void vec4::operator-=(const vec4& ivec)
	{
		v[0] -= ivec.v[0];
		v[1] -= ivec.v[1];
		v[2] -= ivec.v[2];
		v[3] -= ivec.v[3];
	}

	vec4 vec4::operator-(const vec4& ivec)const
	{
		return vec4(v[0] - ivec.v[0], v[1] - ivec.v[1], v[2] - ivec.v[2], v[3] - ivec.v[3]);
	}

	void vec4::operator*=(const vec4& ivec)
	{
		v[0] *= ivec.v[0];
		v[1] *= ivec.v[1];
		v[2] *= ivec.v[2];
		v[3] *= ivec.v[3];
	}

	vec4 vec4::operator*(const float s)const
	{
		return vec4(s * v[0], s * v[1], s * v[2], s * v[3]);
	}

	vec4 vec4::operator*(const vec4& ivec)
	{
		return vec4( v[0] * ivec.v[0], v[1] * ivec.v[1], v[2] * ivec.v[2], v[3] * ivec.v[3]);
	}
	
	void vec4::operator/=(const vec4& ivec)
	{
		v[0] /= ivec.v[0];
		v[1] /= ivec.v[1];
		v[2] /= ivec.v[2];
		v[2] /= ivec.v[3];
	}

	vec4 vec4::operator/(const vec4& ivec)const
	{
		return vec4(v[0] / ivec.v[0], v[1] / ivec.v[1], v[2] / ivec.v[2], v[3] / ivec.v[3]);
	}

	vec4 vec4::cross(const vec4& ivec)const
	{
		return vec4(v[1] * ivec.v[2] - v[2] * ivec.v[1],
					v[2] * ivec.v[0] - v[0] * ivec.v[2],
					v[0] * ivec.v[1] - v[1] * ivec.v[0],
					1);
	}

	void vec4::operator%=(const vec4& ivec)
	{
		*this = cross(ivec);
	}

	vec4 vec4::operator%(const vec4& ivec)const
	{
		return vec4(v[1] * ivec.v[2] - v[2] * ivec.v[1],
					v[2] * ivec.v[0] - v[0] * ivec.v[2],
					v[0] * ivec.v[1] - v[1] * ivec.v[0],
					1);
	}

	vec4 vec4::operator*(const gym::mat4& m) 
	{
		vec4 nv;
		nv.v[0] = v[0] * m.matrixData[0] + v[1] * m.matrixData[1] + v[2] * m.matrixData[2] + v[3] * m.matrixData[3];
		nv.v[1] = v[0] * m.matrixData[4] + v[1] * m.matrixData[5] + v[2] * m.matrixData[6] + v[3] * m.matrixData[7];
		nv.v[2] = v[0] * m.matrixData[8] + v[1] * m.matrixData[9] + v[2] * m.matrixData[10] + v[3] * m.matrixData[11];
		nv.v[3] = v[0] * m.matrixData[12] + v[1] * m.matrixData[13] + v[2] * m.matrixData[14] + v[3] * m.matrixData[15];
		return nv;
	}
	
	float vec4::magnitude()
	{
		return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}

	vec4 vec4::normalize()
	{
		float mag = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			v[0] = v[0] * oneOverMag;
			v[1] = v[1] * oneOverMag;
			v[2] = v[2] * oneOverMag;

		}
		return (*this);
	}

	vec4 vec4::normalizeQ()
	{
		float mag = std::sqrt(v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			v[0] = v[0] * oneOverMag;
			v[1] = v[1] * oneOverMag;
			v[2] = v[2] * oneOverMag;

		}
		return (*this);
	}

	void vec4::show()
	{
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << v[0] << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << v[1] << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << v[2] << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << v[3] << " ";
		std::cout << std::endl;

	}
}