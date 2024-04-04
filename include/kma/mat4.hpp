#pragma once
#include "kma_vec_common.hpp"
#include "vec4.hpp"
#include <cmath>

namespace kma
{
	struct mat4
	{

		mat4()
		{
			m[0] = { 1.0f,0.0f,0.0f,0.0f };
			m[1] = { 0.0f,1.0f,0.0f,0.0f };
			m[2] = { 0.0f,0.0f,1.0f,0.0f };
			m[3] = { 0.0f,0.0f,0.0f,1.0f };
		};

		mat4(float m11, float m12, float m13, float m14,
			 float m21, float m22, float m23, float m24,
			 float m31, float m32, float m33, float m34,
			 float m41, float m42, float m43, float m44)

		{
			m[0] = { m11,m12,m13,m14 };
			m[1] = { m21,m22,m23,m24 };
			m[2] = { m31,m32,m33,m34 };
			m[3] = { m41,m42,m43,m44 };

		}

		mat4 operator=(const mat4& imat) 
		{
			mat4 newMatrix;

			newMatrix.m[0] = imat.m[0];
			newMatrix.m[1] = imat.m[1];
			newMatrix.m[2] = imat.m[2];
			newMatrix.m[3] = imat.m[3];

			return newMatrix;
		}

		m128 mul128matrix(m128& A, const mat4& B)
		{
			m128 vX = shuffle_ps(A, A, _MM_SHUFFLE(0, 0, 0, 0));
			m128 vY = shuffle_ps(A, A, _MM_SHUFFLE(1, 1, 1, 1));
			m128 vZ = shuffle_ps(A, A, _MM_SHUFFLE(2, 2, 2, 2));
			m128 vW = shuffle_ps(A, A, _MM_SHUFFLE(3, 3, 3, 3));
			m128 r = mul_ps(vX, B.m[0]);
			r = add_ps(r, mul_ps(vY, B.m[1]));
			r = add_ps(r, mul_ps(vZ, B.m[2]));
			r = add_ps(r, mul_ps(vW, B.m[3]));
			return r;
		}

		mat4 operator*(const mat4& B)
		{
			mat4 newMatrix;

			newMatrix.m[0] = mul128matrix(m[0], B);
			newMatrix.m[1] = mul128matrix(m[1], B);
			newMatrix.m[2] = mul128matrix(m[2], B);
			newMatrix.m[3] = mul128matrix(m[3], B);

			return newMatrix;
		}

		union {
			float matrix[4][4];
			m128 m[4];
		};
		

	};
}


