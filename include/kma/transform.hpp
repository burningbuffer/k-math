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

		m128 c = set1_ps(cos(a));
		m128 s = set1_ps(sin(a));

		m128 axis = Axis.normalize().v;

		m128 OneMinusC = sub_ps(set1_ps(float(1)), c);

		m128 cos0 = set_ps(0, 0, 0, cos(a));
		m128 cos1 = set_ps(0, 0, cos(a), 0);
		m128 cos2 = set_ps(0, cos(a), 0, 0);

		m128 SxAxis = mul_ps(axis, s);

		m128 axisXXXX = shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(0, 0, 0, 0));
		m128 axisYYYY = shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(1, 1, 1, 1));
		m128 axisZZZZ = shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(2, 2, 2, 2));
		m128 axisWWWW = shuffle_ps(SxAxis, SxAxis, _MM_SHUFFLE(3, 3, 3, 3));

		m128 axis0Z00 = set_ps(0, 0, cvtss_f32(axisZZZZ), 0);
		m128 axis00Y0 = set_ps(0, cvtss_f32(axisYYYY), 0, 0);
		m128 axisZ000 = set_ps(0, 0, 0, cvtss_f32(axisZZZZ));
		m128 axis00X0 = set_ps(0, cvtss_f32(axisXXXX), 0, 0);
		m128 axisY000b = set_ps(0, 0, 0, cvtss_f32(axisYYYY));
		m128 axis0X00 = set_ps(0, 0, cvtss_f32(axisXXXX), 0);

		m128 vecX = shuffle_ps(axis, axis, _MM_SHUFFLE(0, 0, 0, 0));
		m128 vecY = shuffle_ps(axis, axis, _MM_SHUFFLE(1, 1, 1, 1));
		m128 vecZ = shuffle_ps(axis, axis, _MM_SHUFFLE(2, 2, 2, 2));

		m128 vec0 = add_ps(add_ps(sub_ps(mul_ps(mul_ps(vecX, axis), OneMinusC), axis0Z00), axis00Y0), cos0);
		m128 vec1 = add_ps(sub_ps(add_ps(mul_ps(mul_ps(vecY, axis), OneMinusC), axisZ000), axis00X0), cos1);
		m128 vec2 = add_ps(add_ps(sub_ps(mul_ps(mul_ps(vecZ, axis), OneMinusC), axisY000b), axis0X00), cos2);

		mat4 Rotate;
		Rotate.m[0] = vec0;
		Rotate.m[1] = vec1;
		Rotate.m[2] = vec2;
		Rotate.m[3] = set_ps(1.0f,0.0f,0.0f,0.0f);

		return  Rotate;
	}



}