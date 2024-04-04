#pragma once
#include "kma_vec_common.hpp"

namespace kma
{
	struct vec3
	{
		
		KMA_INLINE vec3()
		{
			v = setzero_ps();
		}

		KMA_INLINE vec3(float uX, float uY, float uZ)
		{
			v = set_ps(0, uZ, uY, uX);
		}

		KMA_INLINE vec3(m128 iv)
		{
			v = iv;
		}

		KMA_INLINE vec3 operator+(const vec3& ivec)	const
		{
			return vec3(add_ps(v, ivec.v));
		}

		KMA_INLINE vec3 operator-(const vec3& ivec)	const
		{
			return vec3(sub_ps(v, ivec.v));
		}

		KMA_INLINE vec3 operator*(const vec3& ivec) const
		{
			return vec3(mul_ps(v, ivec.v));
		}

		KMA_INLINE vec3 operator*(const float s) const
		{
			return vec3(mul_ps(v, set1_ps(s)));
		}

		KMA_INLINE vec3 operator/(const vec3& ivec)	const
		{
			return vec3(div_ps(v, ivec.v));
		}

		KMA_INLINE vec3& operator=(const vec3& ivec)
		{
			v = ivec.v;
			return *this;
		}

		KMA_INLINE vec3 Add(const vec3& a, const vec3& b) const
		{
			return vec3(add_ps(a.v, b.v));
		}

		KMA_INLINE vec3 Sub(const vec3& a, const vec3& b) const
		{
			return vec3(sub_ps(a.v, b.v));
		}

		KMA_INLINE vec3 Mul(const vec3& a, const vec3& b) const
		{
			return vec3(mul_ps(a.v, b.v));
		}

		KMA_INLINE vec3 Mul(const vec3& a, const float s) const
		{
			return vec3(mul_ps(a.v, set1_ps(s)));
		}

		KMA_INLINE vec3 Div(const vec3& a, const vec3& b) const
		{
			return vec3(div_ps(a.v, b.v));
		}

		KMA_INLINE vec3 normalize()
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

	KMA_INLINE float dot(vec3 a, vec3 b)
	{
		m128 m = mul_ps(a.v, b.v);
		m128 h1 = hadd_ps(m, m);
		m128 h2 = hadd_ps(h1, h1);
		return cvtss_f32(h2);
	}

	KMA_INLINE vec3 cross(vec3 a, vec3 b) {
		m128 x = a.v;
		m128 y = b.v;
		m128 tmp0 = shuffle_ps(x, x, _MM_SHUFFLE(3, 0, 2, 1));
		m128 tmp1 = shuffle_ps(y, y, _MM_SHUFFLE(3, 1, 0, 2));
		m128 tmp2 = shuffle_ps(x, x, _MM_SHUFFLE(3, 1, 0, 2));
		m128 tmp3 = shuffle_ps(y, y, _MM_SHUFFLE(3, 0, 2, 1));
		return vec3(sub_ps(mul_ps(tmp0, tmp1), mul_ps(tmp2, tmp3)));
	}

	/// temporary ///
	KMA_INLINE vec3 RotateOnX(vec3 v, float Angle) {
		vec3 rotated
		{
			v.x,
				v.y * cos(Angle) - v.z * sin(Angle),
				v.y * sin(Angle) + v.z * cos(Angle)
		};
		return rotated;
	}

	KMA_INLINE vec3 RotateOnY(vec3 v, float Angle) {
		vec3 rotated
		{
			v.x * cos(Angle) - v.z * sin(Angle),
				v.y,
				v.x * sin(Angle) + v.z * cos(Angle)
		};
		return rotated;
	}

	KMA_INLINE vec3 RotateOnZ(vec3 v, float Angle)
	{
		vec3 rotated
		{
			v.x * cos(Angle) - v.y * sin(Angle),
				v.x * sin(Angle) + v.y * cos(Angle),
				v.z
		};
		return rotated;
	}
	/// ////
}