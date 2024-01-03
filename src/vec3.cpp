#include "../include/kma/vec3.hpp"
#include <cmath>

namespace kma
{
	///
	/// constructors
	///

	vec3::vec3() :x(0.0), y(0.0), z(0.0) {};

	vec3::vec3(float uX, float uY, float uZ) :x(uX), y(uY), z(uZ) {}
	
	///
	/// overloaded operators
	///

	vec3 vec3::operator+(const vec3& ivec) const
	{
		return vec3(x + ivec.x, y + ivec.y, z + ivec.z);
	}
	vec3 vec3::operator-(const vec3& ivec) const
	{
		return vec3(x - ivec.x, y - ivec.y, z - ivec.z);
	}
	vec3 vec3::operator*(const vec3& ivec) const
	{
		return vec3(x * ivec.x , y * ivec.y , z * ivec.z);
	}
	vec3 vec3::operator*(const float s) const
	{
		return vec3(s * x, s * y, s * z);
	}
	vec3 vec3::operator/(const vec3& ivec) const
	{
		return vec3(x / ivec.x, y / ivec.y, z / ivec.z);
	}
	vec3& vec3::operator=(const vec3& ivec)
	{
		x = ivec.x;
		y = ivec.y;
		z = ivec.z;

		return *this;
	}

	///
	/// procedural operations
	///

	vec3 vec3::Add(const vec3& a, const vec3& b) const
	{
		return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	vec3 vec3::Sub(const vec3& a, const vec3& b) const
	{
		return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
	}
	vec3 vec3::Mul(const vec3& a, const vec3& b) const
	{
		return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
	}
	vec3 vec3::Mul(const vec3& a, const float s) const
	{
		return vec3(a.x * s, a.y * s, a.z * s);
	}
	vec3 vec3::Div(const vec3& a, const vec3& b) const
	{
		return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
	}

	///
	///
	///

	vec3 vec3::normalize()
	{
		float mag = std::sqrt(x * x + y * y + z * z);
		if (mag > 0.0f)
		{
			x = x * 1.0f / mag;
			y = y * 1.0f / mag;
			z = z * 1.0f / mag;
		}
		return *this;
	}

	///
	///
	///
	
	float dot(vec3 a, vec3 b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	vec3 cross(vec3 a, vec3 b)
	{
		return vec3(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	}
}