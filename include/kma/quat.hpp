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
			q = _mm_set_ps(uV.z(), uV.y(), uV.x(), uS);
		}

		KMA_INLINE quat(__m128 iq)
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

		KMA_INLINE float x() const
		{
			return _mm_cvtss_f32(q);
		}

		KMA_INLINE float y() const
		{
			return _mm_cvtss_f32(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 1, 1, 1)));
		}

		KMA_INLINE float z() const
		{
			return _mm_cvtss_f32(_mm_shuffle_ps(q, q, _MM_SHUFFLE(2, 2, 2, 2)));
		}

		KMA_INLINE float w() const
		{
			return _mm_cvtss_f32(_mm_shuffle_ps(q, q, _MM_SHUFFLE(3, 3, 3, 3)));
		}

		KMA_INLINE void setX(float x)
		{
			q = _mm_insert_ps(q, _mm_set_ss(x), 0x00);
		}

		KMA_INLINE void setY(float y)
		{
			q = _mm_insert_ps(q, _mm_set_ss(y), 0x10);
		}
		KMA_INLINE void setZ(float z)
		{
			q = _mm_insert_ps(q, _mm_set_ss(z), 0x20);
		}
		KMA_INLINE void setW(float w)
		{
			q = _mm_insert_ps(q, _mm_set_ss(w), 0x30);
		}

		/// Agner Fog Vector Class Quaternion Multiplication
		quat operator*(const quat& iq)const
		{
			__m128 a = q;
			__m128 b = iq.q;
			__m128 a1123 = _mm_shuffle_ps(a, a, 0xE5);
			__m128 a2231 = _mm_shuffle_ps(a, a, 0x7A);
			__m128 b1000 = _mm_shuffle_ps(b, b, 0x01);
			__m128 b2312 = _mm_shuffle_ps(b, b, 0x9E);
			__m128 t1 = _mm_mul_ps(a1123, b1000);
			__m128 t2 = _mm_mul_ps(a2231, b2312);
			__m128 t12 = _mm_add_ps(t1, t2);
			const __m128i mask = _mm_set_epi32(0, 0, 0, 0x80000000);
			__m128 t12m = _mm_xor_ps(t12, _mm_castsi128_ps(mask)); // flip sign bits
			__m128 a3312 = _mm_shuffle_ps(a, a, 0x9F);
			__m128 b3231 = _mm_shuffle_ps(b, b, 0x7B);
			__m128 a0000 = _mm_shuffle_ps(a, a, 0x00);
			__m128 t3 = _mm_mul_ps(a3312, b3231);
			__m128 t0 = _mm_mul_ps(a0000, b);
			__m128 t03 = _mm_sub_ps(t0, t3);
			__m128 rotatedVector = _mm_add_ps(t03, t12m);
			return quat(rotatedVector);
		}

		quat& operator=(const quat& value)
		{
			q = value.q;
			return (*this);
		}

		quat inverse()
		{
			__m128 abs = norm();
			abs = _mm_mul_ps(abs, abs);
			__m128 one = _mm_set1_ps(1);
			__m128 oneOver = _mm_div_ps(one, abs);
			quat conjugateValue = conjugate();
			__m128 az = conjugateValue.q;
			__m128 at = _mm_mul_ps(az, oneOver);
			return quat(at);
		}

		__m128 conjugate()
		{
			const __m128i mask = _mm_set_epi32(0x80000000, 0x80000000, 0x80000000, 0);
			return _mm_xor_ps(q, _mm_castsi128_ps(mask));
		}

		__m128 norm()
		{
			__m128 s = _mm_mul_ps(q, q);
			__m128 res = _mm_hadd_ps(s, s);
			return _mm_sqrt_ps(_mm_hadd_ps(res, res));
		}

		__m128 normalize()
		{
			__m128 s = _mm_mul_ps(q, q);
			__m128 res = _mm_hadd_ps(s, s);
			__m128 InverseSqrt = _mm_rsqrt_ps(_mm_hadd_ps(res, res));
			return _mm_mul_ps(q, InverseSqrt);
		}

		__m128 q;

	};

}