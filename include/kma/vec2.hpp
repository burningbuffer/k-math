#pragma once

namespace kma
{
	class vec2
	{
	public:

		struct {

			float x;

			float y;

		};

		///
		/// constructors
		/// 

		vec2();

		vec2(float uX, float uY);

		///
		/// overloaded operators
		///

		vec2 operator+(const vec2& ivec)	const;

		vec2 operator-(const vec2& ivec)	const;

		vec2 operator*(const vec2& ivec)    const;

		vec2 operator*(const float s)		const;

		vec2 operator/(const vec2& ivec)	const;

		vec2& operator=(const vec2& ivec);

		///
		/// procedural operations
		///

		vec2 Add(const vec2& a, const vec2& b) const;

		vec2 Sub(const vec2& a, const vec2& b) const;

		vec2 Mul(const vec2& a, const vec2& b) const;

		vec2 Mul(const vec2& a, const float s) const;

		vec2 Div(const vec2& a, const vec2& b) const;

		///
		///
		///

		vec2 normalize();
	};

	///
	///
	///

}