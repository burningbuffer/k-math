#pragma once
#include "vec4.hpp"
#include <cmath>

namespace kma
{

	class mat4
	{
	public:

		float matrixData[16] = { 0.0 };

		mat4();

		mat4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15);

		mat4 operator=(const mat4& value);

		mat4 operator+(const mat4& value);

		mat4 operator*(const mat4& value);

	};
}


