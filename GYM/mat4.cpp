#include <iostream>
#include "mat4.h"

namespace gym
{

	mat4::mat4()
	{

		for (int i = 0; i != 16; i++)
		{
			matrixData[i] = 0.0f;
		}

		matrixData[0] = 1.0f;
		matrixData[5] = 1.0f;
		matrixData[10] = 1.0f;
		matrixData[15] = 1.0f;
	}
	
	// vec4 mat4::operator*(const vec4& inputv)
	// {
	// 	vec4 nv;
	// 	nv.v[0] = matrixData[0] * inputv.v[0] + matrixData[1] * inputv.v[1] + matrixData[2] * inputv.v[2] + matrixData[3] * inputv.v[3];
	// 	nv.v[1] = matrixData[4] * inputv.v[0] + matrixData[5] * inputv.v[1] + matrixData[6] * inputv.v[2] + matrixData[7] * inputv.v[3];
	// 	nv.v[2] = matrixData[8] * inputv.v[0] + matrixData[9] * inputv.v[1] + matrixData[10] * inputv.v[2] + matrixData[11] * inputv.v[3];
	// 	nv.v[3] = matrixData[12] * inputv.v[0] + matrixData[13] * inputv.v[1] + matrixData[14] * inputv.v[2] + matrixData[15] * inputv.v[3];

	// 	return nv;
	// }

	void mat4::show()
	{
		int c = 0;
		for (int i = 0; i < 16; i++)
		{
			if (c == 4)
			{
				std::cout << std::endl;
				c = 0;
			}

			std::cout
				<< std::setw(10)
				<< std::setprecision(6)
				<< std::fixed
				<< matrixData[i] << " ";
			c++;
		}
		std::cout << std::endl;
	}

	mat4::~mat4()
	{
	}




}