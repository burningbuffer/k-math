#include "../include/kma/vec2.hpp"
#include <cmath>

namespace kma
{
	///
	/// constructors
	///

	vec2::vec2() :x(0.0), y(0.0) {};

	vec2::vec2(float uX, float uY) :x(uX), y(uY) {}

	///
	/// overloaded operators
	///

	vec2 vec2::operator+(const vec2& ivec) const
	{
		return vec2(x + ivec.x, y + ivec.y);
	}
	vec2 vec2::operator-(const vec2& ivec) const
	{
		return vec2(x - ivec.x, y - ivec.y);
	}
	vec2 vec2::operator*(const vec2& ivec) const
	{
		return vec2(x * ivec.x, y * ivec.y);
	}
	vec2 vec2::operator*(const float s) const
	{
		return vec2(s * x, s * y);
	}
	vec2 vec2::operator/(const vec2& ivec) const
	{
		return vec2(x / ivec.x, y / ivec.y);
	}
	vec2& vec2::operator=(const vec2& ivec)
	{
		x = ivec.x;
		y = ivec.y;

		return *this;
	}

	///
	/// procedural operations
	///

	vec2 vec2::Add(const vec2& a, const vec2& b) const
	{
		return vec2(a.x + b.x, a.y + b.y);
	}
	vec2 vec2::Sub(const vec2& a, const vec2& b) const
	{
		return vec2(a.x - b.x, a.y - b.y);
	}
	vec2 vec2::Mul(const vec2& a, const vec2& b) const
	{
		return vec2(a.x * b.x, a.y * b.y);
	}
	vec2 vec2::Mul(const vec2& a, const float s) const
	{
		return vec2(a.x * s, a.y * s);
	}
	vec2 vec2::Div(const vec2& a, const vec2& b) const
	{
		return vec2(a.x / b.x, a.y / b.y);
	}

	///
	///
	///

	vec2 vec2::normalize()
	{
		float mag = std::sqrt(x * x + y * y);
		if (mag > 0.0f)
		{
			x = x * 1.0f / mag;
			y = y * 1.0f / mag;
		}
		return *this;
	}

	///
	///
	///
	
}