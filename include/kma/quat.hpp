#pragma once
#include "kma_vec_common.hpp"
#include "vec4.hpp"

namespace kma
{
	class quat
	{

	public:

		KMA_INLINE quat(float uS, vec4& uV)
		{
			q = set_ps(uV.z, uV.y, uV.x, uS);
		}

		KMA_INLINE quat(m128 iq)
		{
			q = iq;
		}

		KMA_INLINE quat(const quat& value)
		{
			q = value.q;
		}

		KMA_INLINE quat(vec4 iv)
		{
			q = iv.v;
		}

		/// Agner Fog Vector Class Quaternion Multiplication
		quat operator*(const quat& iq)const
		{
			m128 a = q;
			m128 b = iq.q;
			m128 a1123 = shuffle_ps(a, a, 0xE5);
			m128 a2231 = shuffle_ps(a, a, 0x7A);
			m128 b1000 = shuffle_ps(b, b, 0x01);
			m128 b2312 = shuffle_ps(b, b, 0x9E);
			m128 t1 = mul_ps(a1123, b1000);
			m128 t2 = mul_ps(a2231, b2312);
			m128 t12 = add_ps(t1, t2);
			const m128i mask = set_epi32(0, 0, 0, 0x80000000);
			m128 t12m = xor_ps(t12, castsi128_ps(mask)); 
			m128 a3312 = shuffle_ps(a, a, 0x9F);
			m128 b3231 = shuffle_ps(b, b, 0x7B);
			m128 a0000 = shuffle_ps(a, a, 0x00);
			m128 t3 = mul_ps(a3312, b3231);
			m128 t0 = mul_ps(a0000, b);
			m128 t03 = sub_ps(t0, t3);
			m128 rotatedVector = add_ps(t03, t12m);
			return quat(rotatedVector);
		}

		quat& operator=(const quat& value)
		{
			q = value.q;
			return (*this);
		}

		quat inverse()
		{
			m128 abs = norm();
			abs = mul_ps(abs, abs);
			m128 one = set1_ps(1);
			m128 oneOver = div_ps(one, abs);
			quat conjugateValue = conjugate();
			m128 az = conjugateValue.q;
			m128 at = mul_ps(az, oneOver);
			return quat(at);
		}

		m128 conjugate()
		{
			const m128i mask = set_epi32(0x80000000, 0x80000000, 0x80000000, 0);
			return xor_ps(q, castsi128_ps(mask));
		}

		m128 norm()
		{
			m128 s = mul_ps(q, q);
			m128 res = hadd_ps(s, s);
			return sqrt_ps(hadd_ps(res, res));
		}

		m128 normalize()
		{
			m128 s = mul_ps(q, q);
			m128 res = hadd_ps(s, s);
			m128 InverseSqrt = rsqrt_ps(hadd_ps(res, res));
			return mul_ps(q, InverseSqrt);
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
			m128 q;
		};

	};

}