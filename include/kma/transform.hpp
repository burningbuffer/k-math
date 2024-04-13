#include "vec4.hpp"
#include "mat4.hpp"
#include "utils.hpp"
#include <iostream>

namespace kma
{
	KMA_INLINE mat4 scale(vec4 scaleVector)
	{
		mat4 identity{};
		identity.matrix[0][0] = scaleVector.x;
		identity.matrix[1][1] = scaleVector.y;
		identity.matrix[2][2] = scaleVector.z;
		return identity;
	}

	KMA_INLINE mat4 translate(vec4 translateVector)
	{
		mat4 identity{};
		identity.matrix[3][0] = translateVector.x;
		identity.matrix[3][1] = translateVector.y;
		identity.matrix[3][2] = translateVector.z;
		return identity;
	}

	KMA_INLINE mat4 rotate(float Angle, vec4& Axis)
	{
		const float a = -Angle;

		__m128 c = _mm_set1_ps(cos(a));
		__m128 s = _mm_set1_ps(sin(a));

		__m128 axis = Axis.normalize().v;

		__m128 OneMinusC = _mm_sub_ps(_mm_set1_ps(float(1)), c);

		__m128 cos0 = _mm_set_ps(0, 0, 0, cos(a));
		__m128 cos1 = _mm_set_ps(0, 0, cos(a), 0);
		__m128 cos2 = _mm_set_ps(0, cos(a), 0, 0);

		__m128 SxAxis = _mm_mul_ps(axis, s);

		__m128 axisXXXX = _mm_shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(0, 0, 0, 0));
		__m128 axisYYYY = _mm_shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(1, 1, 1, 1));
		__m128 axisZZZZ = _mm_shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(2, 2, 2, 2));
		__m128 axisWWWW = _mm_shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(3, 3, 3, 3));

		__m128 axis0Z00 = _mm_set_ps(0, 0, _mm_cvtss_f32(axisZZZZ), 0);
		__m128 axis00Y0 = _mm_set_ps(0, _mm_cvtss_f32(axisYYYY), 0, 0);
		__m128 axisZ000 = _mm_set_ps(0, 0, 0, _mm_cvtss_f32(axisZZZZ));
		__m128 axis00X0 = _mm_set_ps(0, _mm_cvtss_f32(axisXXXX), 0, 0);
		__m128 axisY000b = _mm_set_ps(0, 0, 0, _mm_cvtss_f32(axisYYYY));
		__m128 axis0X00 = _mm_set_ps(0, 0, _mm_cvtss_f32(axisXXXX), 0);

		__m128 vecX = _mm_shuffle_ps(axis, axis, _MM_SHUFFLE(0, 0, 0, 0));
		__m128 vecY = _mm_shuffle_ps(axis, axis, _MM_SHUFFLE(1, 1, 1, 1));
		__m128 vecZ = _mm_shuffle_ps(axis, axis, _MM_SHUFFLE(2, 2, 2, 2));

		__m128 vec0 = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_mul_ps(vecX, axis), OneMinusC), axis0Z00), axis00Y0), cos0);
		__m128 vec1 = _mm_add_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(vecY, axis), OneMinusC), axisZ000), axis00X0), cos1);
		__m128 vec2 = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_mul_ps(vecZ, axis), OneMinusC), axisY000b), axis0X00), cos2);

		mat4 Rotate;
		Rotate.m[0] = vec0;
		Rotate.m[1] = vec1;
		Rotate.m[2] = vec2;
		Rotate.m[3] = _mm_set_ps(1.0f,0.0f,0.0f,0.0f);

		return  Rotate;
	}



}