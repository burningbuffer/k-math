#pragma once
#include <immintrin.h>
#include <xmmintrin.h>
#include <smmintrin.h>

#define KMA_INLINE __forceinline

#define setzero_ps _mm_setzero_ps
#define set_ps _mm_set_ps
#define add_ps _mm_add_ps
#define sub_ps _mm_sub_ps
#define mul_ps _mm_mul_ps
#define div_ps _mm_div_ps
#define hadd_ps _mm_hadd_ps
#define rsqrt_ps _mm_rsqrt_ps
#define cvtss_f32 _mm_cvtss_f32
#define shuffle_ps _mm_shuffle_ps
#define set1_ps _mm_set1_ps

namespace kma
{
	typedef __m128 m128;

}