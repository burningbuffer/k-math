#pragma once

namespace kma
{
	class vec3
	{
	public:

		struct {

			float x;

			float y;

			float z;

		};

		///
		/// constructors
		/// 
		
		vec3();

		vec3(float uX, float uY, float uZ);

		///
		/// overloaded operators
		///

		vec3 operator+(const vec3& ivec)	const;

		vec3 operator-(const vec3& ivec)	const;

		vec3 operator*(const vec3& ivec)    const;

		vec3 operator*(const float s)		const;

		vec3 operator/(const vec3& ivec)	const;

		vec3& operator=(const vec3& ivec);

		///
		/// procedural operations
		///

		vec3 Add(const vec3& a, const vec3& b) const;

		vec3 Sub(const vec3& a, const vec3& b) const;

		vec3 Mul(const vec3& a, const vec3& b) const;

		vec3 Mul(const vec3& a, const float s) const;

		vec3 Div(const vec3& a, const vec3& b) const;

		///
		///
		///

		vec3 normalize();
	};

	///
	///
	///

	float dot(vec3 a, vec3 b);

	vec3 cross(vec3 a, vec3 b);

}