#include <iostream>
#include "../include/mat/vec4.hpp"

namespace mat
{

	vec4 ::vec4 () { v = _mm_setzero_ps(); }
	
	vec4 ::vec4 (float uX, float uY, float uZ, float uW){ v = _mm_set_ps(uX, uY, uZ, uW);}

	vec4 ::vec4 (__m128 iv){ v = iv;}

	vec4  vec4 ::operator+(const vec4 & ivec) const
	{
		return vec4 (_mm_add_ps(v, ivec.v));
	}

	vec4  vec4 ::operator-(const vec4 & ivec) const
	{
		return vec4 (_mm_sub_ps(v, ivec.v));
	}

	vec4  vec4 ::operator*(const vec4 & ivec) const 
	{
		return vec4 (_mm_mul_ps(v, ivec.v));
	}

	vec4  vec4 ::operator*(const float s) const
	{
		return vec4 (_mm_mul_ps(v, _mm_set1_ps(s)));
	}

	vec4  vec4 ::operator/(const vec4 & ivec) const
	{
		return vec4 (_mm_div_ps(v, ivec.v));
	}

	vec4  vec4 ::operator%(const vec4 & ivec) const
	{
		return vec4 (y * ivec.z - z * ivec.y,
			z * ivec.x - x * ivec.z,
			x * ivec.y - y * ivec.x,
			1);
	}

	vec4 & vec4 ::operator=(const vec4 & ivec)
	{
		x = ivec.x;
		y = ivec.y;
		z = ivec.z;
		w = ivec.w;

		return *this;
	}

	float vec4 ::magnitude() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	
	/*vec4  vec4 ::operator*(const mat::mat4& imat) 
	{
		__m128 m0 = _mm_load_ps(&imat.matrixData[0]);
		__m128 m1 = _mm_load_ps(&imat.matrixData[4]);
		__m128 m2 = _mm_load_ps(&imat.matrixData[8]);
		__m128 m3 = _mm_load_ps(&imat.matrixData[12]);

		_MM_TRANSPOSE4_PS(m0, m1, m2, m3);

		__m128 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
		__m128 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
		__m128 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
		__m128 w = _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3));

		__m128 r0 = _mm_mul_ps(m0, x);
		__m128 r1 = _mm_mul_ps(m1, y);
		__m128 r2 = _mm_mul_ps(m2, z);
		__m128 r3 = _mm_mul_ps(m3, w);

		__m128 r01 = _mm_add_ps(r0, r1);
		__m128 r23 = _mm_add_ps(r2, r3);
		__m128 r = _mm_add_ps(r01, r23);

		return vec4 (r);
	}*/

	vec4  vec4 ::normalize()
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

	void vec4 ::show()
	{
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << x << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << y << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << z << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << w << " ";
		std::cout << std::endl;

	}
}