#include <iostream>
#include "vec3.h"
#include <cmath>

namespace mat
{
	vec3::vec3() :x(0.0), y(0.0), z(0.0) {};
	vec3::vec3(float uX, float uY, float uZ) :x(uX), y(uY), z(uZ) {}

	vec3::~vec3(){};

	vec3::vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}
	vec3& vec3::operator=(const vec3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	vec3 vec3::operator*(const float s) const {
		return vec3(s * x, s * y, s * z);
	}

	float vec3::operator*(const vec3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	vec3 vec3::operator+(const vec3& v)const {
		return vec3(x + v.x, y + v.y, z + v.z);
	}

	void vec3::operator*=(const float s)
	{
		x *= s;
		y *= s;
		z *= s;
	}

	float vec3::dot(const vec3& v) const {
		return x * v.x + y * v.y + z * v.z;
	}

	vec3 vec3::cross(const vec3& v) const
	{
		return vec3(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x);
	}

	float vec3::magnitude()
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	void vec3::normalize()
	{
		float mag = std::sqrt(x * x + y * y + z * z);
		if (mag > 0.0f)// evita divisao por zero
		{
			float oneOverMag = 1.0f / mag;
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;
		}
	}
}
