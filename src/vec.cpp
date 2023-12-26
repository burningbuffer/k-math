#include "../include/mat/vec.hpp"

namespace mat
{
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