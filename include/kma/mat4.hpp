#pragma once
#include "vec4.hpp"
#include <cmath>

namespace kma
{
	class mat4
	{

	public:

		union
		{
			float matrixData[16];
			__m128 matrixSSE[4];
		};
		

		/// 
		/// constructors
		/// 
		
		mat4();

		mat4(
			float m11, float m12, float m13, float m14, 
			float m21, float m22, float m23, float m24, 
			float m31, float m32, float m33, float m34, 
			float m41, float m42, float m43, float m44);

		/// 
		/// overloaded operators
		/// 
		
		mat4 operator=(const mat4& value);

		mat4 operator+(const mat4& value);

		mat4 operator*(const mat4& value);

	};
}


