#pragma once
#include <immintrin.h>
#include <xmmintrin.h>
#include <iomanip>

namespace kma
{
	class vec4
	{

	public:

		union {

			struct {

				float x;

				float y;

				float z;

				float w;

			};

			__m128 v;

		};

		///
		/// constructors
		///

		vec4();

		vec4(float uX, float uY, float uZ, float uW);

		vec4(__m128 iv);

		///
		/// overloaded operators
		///

		vec4 operator+(const vec4& ivec)	const;

		vec4 operator-(const vec4& ivec)	const;

		vec4 operator*(const vec4& ivec)    const;

		vec4 operator*(const float s)		const;

		vec4 operator/(const vec4& ivec)	const;

		vec4& operator=(const vec4& ivec);

		///
		/// procedural operations
		///

		vec4 Add(const vec4& a, const vec4& b) const;

		vec4 Sub(const vec4& a, const vec4& b) const;

		vec4 Mul(const vec4& a, const vec4& b) const;

		vec4 Mul(const vec4& a, const float s) const;

		vec4 Div(const vec4& a, const vec4& b) const;

		///
		///
		///

		vec4 normalize();

	};
	
	///
	///
	///

	float dot(vec4 a, vec4 b);

	vec4 cross(vec4 a, vec4 b);

	

}