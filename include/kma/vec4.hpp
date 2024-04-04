#pragma once
#include "mat4.hpp"
#include "kma_vec_common.hpp"

namespace kma
{
	struct vec4
	{
		KMA_INLINE vec4()
		{ 
			v = setzero_ps(); 
		}

		KMA_INLINE vec4(float uX, float uY, float uZ, float uW)
		{ 
			v = set_ps(uW, uZ, uY, uX); 
		}

		KMA_INLINE vec4(m128 iv)
		{ 
			v = iv; 
		}

		KMA_INLINE vec4 operator+(const vec4& ivec)	const
		{
			return vec4(add_ps(v, ivec.v));
		}

		KMA_INLINE vec4 operator-(const vec4& ivec)	const
		{
			return vec4(sub_ps(v, ivec.v));
		}
		
		KMA_INLINE vec4 operator*(const vec4& ivec) const
		{
			return vec4(mul_ps(v, ivec.v));
		}
		
		KMA_INLINE vec4 operator*(const float s) const
		{
			return vec4(mul_ps(v, set1_ps(s)));
		}
		
		KMA_INLINE vec4 operator/(const vec4& ivec)	const
		{
			return vec4(div_ps(v, ivec.v));
		}
		
		KMA_INLINE vec4& operator=(const vec4& ivec)
		{
			v = ivec.v;
			return *this;
		}

		KMA_INLINE vec4 operator*(const mat4& B)
		{
			m128 vX = shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
			m128 vY = shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
			m128 vZ = shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
			m128 vW = shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3));

			m128 r = mul_ps(vX, B.m[0]);
			r = add_ps(r, mul_ps(vY, B.m[1]));
			r = add_ps(r, mul_ps(vZ, B.m[2]));
			r = add_ps(r, mul_ps(vW, B.m[3]));

			return vec4(r);
		}

		KMA_INLINE vec4 Add(const vec4& a, const vec4& b) const
		{
			return vec4(add_ps(a.v, b.v));
		}

		KMA_INLINE vec4 Sub(const vec4& a, const vec4& b) const
		{
			return vec4(sub_ps(a.v, b.v));
		}

		KMA_INLINE vec4 Mul(const vec4& a, const vec4& b) const
		{
			return vec4(mul_ps(a.v, b.v));
		}

		KMA_INLINE vec4 Mul(const vec4& a, const float s) const
		{
			return vec4(mul_ps(a.v, _mm_set1_ps(s)));
		}

		KMA_INLINE vec4 Div(const vec4& a, const vec4& b) const
		{
			return vec4(div_ps(a.v, b.v));
		}

		KMA_INLINE vec4 normalize()
		{
			m128 s = mul_ps(v, v);
			m128 res = hadd_ps(s, s);
			m128 InverseSqrt = rsqrt_ps(hadd_ps(res, res));
			m128 norm = mul_ps(v, InverseSqrt);
			return norm;
		}

		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			m128 v;
		};

	};

	KMA_INLINE float dot(vec4 a, vec4 b)
	{
		m128 m = mul_ps(a.v, b.v);
		m128 h1 = hadd_ps(m, m);
		m128 h2 = hadd_ps(h1, h1);
		return cvtss_f32(h2);
	}

	KMA_INLINE vec4 cross(vec4 a, vec4 b)
	{
		m128 x = a.v;
		m128 y = b.v;
		m128 tmp0 = shuffle_ps(x, x, _MM_SHUFFLE(3, 0, 2, 1));
		m128 tmp1 = shuffle_ps(y, y, _MM_SHUFFLE(3, 1, 0, 2));
		m128 tmp2 = shuffle_ps(x, x, _MM_SHUFFLE(3, 1, 0, 2));
		m128 tmp3 = shuffle_ps(y, y, _MM_SHUFFLE(3, 0, 2, 1));
		return vec4(sub_ps(mul_ps(tmp0, tmp1), mul_ps(tmp2, tmp3)));
	}

	

}