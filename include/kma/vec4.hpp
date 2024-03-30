#pragma once
#include <immintrin.h>
#include <xmmintrin.h>
#include <iomanip>

namespace kma
{
	struct vec4
	{

		union 
		{
			struct 
			{
				float x;
				float y;
				float z;
				float w;
			};
			__m128 v;

		};

		vec4() 
		{ 
			v = _mm_setzero_ps(); 
		}

		vec4(float uX, float uY, float uZ, float uW) 
		{ 
			v = _mm_set_ps(uW, uZ, uY, uX); 
		}

		vec4(__m128 iv) 
		{ 
			v = iv; 
		}

		vec4 operator+(const vec4& ivec)	const 
		{
			return vec4(_mm_add_ps(v, ivec.v));
		}

		vec4 operator-(const vec4& ivec)	const 
		{
			return vec4(_mm_sub_ps(v, ivec.v));
		}
		
		vec4 operator*(const vec4& ivec)    const 
		{
			return vec4(_mm_mul_ps(v, ivec.v));
		}
		
		vec4 operator*(const float s)		const 
		{
			return vec4(_mm_mul_ps(v, _mm_set1_ps(s)));
		}
		
		vec4 operator/(const vec4& ivec)	const
		{
			return vec4(_mm_div_ps(v, ivec.v));
		}
		
		vec4& operator=(const vec4& ivec) 
		{
			x = ivec.x;
			y = ivec.y;
			z = ivec.z;
			w = ivec.w;

			return *this;
		}

		vec4 Add(const vec4& a, const vec4& b) const 
		{
			return vec4(_mm_add_ps(a.v, b.v));
		}

		vec4 Sub(const vec4& a, const vec4& b) const 
		{
			return vec4(_mm_sub_ps(a.v, b.v));
		}

		vec4 Mul(const vec4& a, const vec4& b) const 
		{
			return vec4(_mm_mul_ps(a.v, b.v));
		}

		vec4 Mul(const vec4& a, const float s) const 
		{
			return vec4(_mm_mul_ps(a.v, _mm_set1_ps(s)));
		}

		vec4 Div(const vec4& a, const vec4& b) const 
		{
			return vec4(_mm_div_ps(a.v, b.v));
		}

		vec4 normalize()
		{
			__m128 s = _mm_mul_ps(v, v);
			__m128 res = _mm_hadd_ps(s, s);
			__m128 InverseSqrt = _mm_rsqrt_ps(_mm_hadd_ps(res, res));
			__m128 norm = _mm_mul_ps(v, InverseSqrt);
			return norm;
		}

	};

	float dot(vec4 a, vec4 b) 
	{
		__m128 m = _mm_mul_ps(a.v, b.v);
		__m128 h1 = _mm_hadd_ps(m, m);
		__m128 h2 = _mm_hadd_ps(h1, h1);
		return _mm_cvtss_f32(h2);
	}

	vec4 cross(vec4 a, vec4 b) 
	{
		__m128 x = a.v;
		__m128 y = b.v;
		__m128 tmp0 = _mm_shuffle_ps(x, x, _MM_SHUFFLE(3, 0, 2, 1));
		__m128 tmp1 = _mm_shuffle_ps(y, y, _MM_SHUFFLE(3, 1, 0, 2));
		__m128 tmp2 = _mm_shuffle_ps(x, x, _MM_SHUFFLE(3, 1, 0, 2));
		__m128 tmp3 = _mm_shuffle_ps(y, y, _MM_SHUFFLE(3, 0, 2, 1));
		return vec4(_mm_sub_ps(_mm_mul_ps(tmp0, tmp1), _mm_mul_ps(tmp2, tmp3)));
	}

	

}