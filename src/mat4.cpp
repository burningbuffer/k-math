#include <iostream>
#include "../include/kma/mat4.hpp"

namespace kma
{
	/// 
	/// constructors
	/// 
	/// default constructor is a identity matrix
	mat4::mat4()
	{
		for (int i = 0; i != 16; i++)
		{
			if (i % 5 == 0)
			{
				matrixData[i] = 1.0f;
				continue;
			}
			matrixData[i] = 0.0f;
		}
	}

	mat4::mat4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44)

	{
		matrixData[0] = m11;
		matrixData[1] = m12;
		matrixData[2] = m13;
		matrixData[3] = m14;

		matrixData[4] = m21;
		matrixData[5] = m22;
		matrixData[6] = m23;
		matrixData[7] = m24;

		matrixData[8] = m31;
		matrixData[9] = m32;
		matrixData[10] = m33;
		matrixData[11] = m34;

		matrixData[12] = m41;
		matrixData[13] = m42;
		matrixData[14] = m43;
		matrixData[15] = m44;
	}

	/// 
	/// overloaded operators
	/// 

	mat4 mat4::operator=(const mat4& value)
	{
		mat4 newMatrix;

		newMatrix.matrixData[0] = value.matrixData[0];
		newMatrix.matrixData[1] = value.matrixData[1];
		newMatrix.matrixData[2] = value.matrixData[2];
		newMatrix.matrixData[3] = value.matrixData[3];

		newMatrix.matrixData[4] = value.matrixData[4];
		newMatrix.matrixData[5] = value.matrixData[5];
		newMatrix.matrixData[6] = value.matrixData[6];
		newMatrix.matrixData[7] = value.matrixData[7];

		newMatrix.matrixData[8] = value.matrixData[8];
		newMatrix.matrixData[9] = value.matrixData[9];
		newMatrix.matrixData[10] = value.matrixData[10];
		newMatrix.matrixData[11] = value.matrixData[11];

		newMatrix.matrixData[12] = value.matrixData[12];
		newMatrix.matrixData[13] = value.matrixData[13];
		newMatrix.matrixData[14] = value.matrixData[14];
		newMatrix.matrixData[15] = value.matrixData[15];

		return newMatrix;
	}

	mat4 mat4::operator+(const mat4& value)
	{
		mat4 newMatrix;

		newMatrix.matrixData[0] = matrixData[0] + value.matrixData[0];
		newMatrix.matrixData[1] = matrixData[1] + value.matrixData[1];
		newMatrix.matrixData[2] = matrixData[2] + value.matrixData[2];
		newMatrix.matrixData[3] = matrixData[3] + value.matrixData[3];

		newMatrix.matrixData[4] = matrixData[4] + value.matrixData[4];
		newMatrix.matrixData[5] = matrixData[5] + value.matrixData[5];
		newMatrix.matrixData[6] = matrixData[6] + value.matrixData[6];
		newMatrix.matrixData[7] = matrixData[7] + value.matrixData[7];

		newMatrix.matrixData[8] = matrixData[8] + value.matrixData[8];
		newMatrix.matrixData[9] = matrixData[9] + value.matrixData[9];
		newMatrix.matrixData[10] = matrixData[10] + value.matrixData[10];
		newMatrix.matrixData[11] = matrixData[11] + value.matrixData[11];

		newMatrix.matrixData[12] = matrixData[12] + value.matrixData[12];
		newMatrix.matrixData[13] = matrixData[13] + value.matrixData[13];
		newMatrix.matrixData[14] = matrixData[14] + value.matrixData[14];
		newMatrix.matrixData[15] = matrixData[15] + value.matrixData[15];

		return newMatrix;
	}

	mat4 mat4::operator*(const mat4& m)
	{
		mat4 nm;

		nm.matrixData[0] = matrixData[0] * m.matrixData[0] + matrixData[1] * m.matrixData[4] + matrixData[2] * m.matrixData[8] + matrixData[3] * m.matrixData[12];
		nm.matrixData[1] = matrixData[0] * m.matrixData[1] + matrixData[1] * m.matrixData[5] + matrixData[2] * m.matrixData[9] + matrixData[3] * m.matrixData[13];
		nm.matrixData[2] = matrixData[0] * m.matrixData[2] + matrixData[1] * m.matrixData[6] + matrixData[2] * m.matrixData[10] + matrixData[3] * m.matrixData[14];
		nm.matrixData[3] = matrixData[0] * m.matrixData[3] + matrixData[1] * m.matrixData[7] + matrixData[2] * m.matrixData[11] + matrixData[3] * m.matrixData[15];

		nm.matrixData[4] = matrixData[4] * m.matrixData[0] + matrixData[5] * m.matrixData[4] + matrixData[6] * m.matrixData[8] + matrixData[7] * m.matrixData[12];
		nm.matrixData[5] = matrixData[4] * m.matrixData[1] + matrixData[5] * m.matrixData[5] + matrixData[6] * m.matrixData[9] + matrixData[7] * m.matrixData[13];
		nm.matrixData[6] = matrixData[4] * m.matrixData[2] + matrixData[5] * m.matrixData[6] + matrixData[6] * m.matrixData[10] + matrixData[7] * m.matrixData[14];
		nm.matrixData[7] = matrixData[4] * m.matrixData[3] + matrixData[5] * m.matrixData[7] + matrixData[6] * m.matrixData[11] + matrixData[7] * m.matrixData[15];

		nm.matrixData[8] = matrixData[8] * m.matrixData[0] + matrixData[9] * m.matrixData[4] + matrixData[10] * m.matrixData[8] + matrixData[11] * m.matrixData[12];
		nm.matrixData[9] = matrixData[8] * m.matrixData[1] + matrixData[9] * m.matrixData[5] + matrixData[10] * m.matrixData[9] + matrixData[11] * m.matrixData[13];
		nm.matrixData[10] = matrixData[8] * m.matrixData[2] + matrixData[9] * m.matrixData[6] + matrixData[10] * m.matrixData[10] + matrixData[11] * m.matrixData[14];
		nm.matrixData[11] = matrixData[8] * m.matrixData[3] + matrixData[9] * m.matrixData[7] + matrixData[10] * m.matrixData[11] + matrixData[11] * m.matrixData[15];

		nm.matrixData[12] = matrixData[12] * m.matrixData[0] + matrixData[13] * m.matrixData[4] + matrixData[14] * m.matrixData[8] + matrixData[15] * m.matrixData[12];
		nm.matrixData[13] = matrixData[12] * m.matrixData[1] + matrixData[13] * m.matrixData[5] + matrixData[14] * m.matrixData[9] + matrixData[15] * m.matrixData[13];
		nm.matrixData[14] = matrixData[12] * m.matrixData[2] + matrixData[13] * m.matrixData[6] + matrixData[14] * m.matrixData[10] + matrixData[15] * m.matrixData[14];
		nm.matrixData[15] = matrixData[12] * m.matrixData[3] + matrixData[13] * m.matrixData[7] + matrixData[14] * m.matrixData[11] + matrixData[15] * m.matrixData[15];

		return nm;
	}
}