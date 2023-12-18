#ifndef MAT4_H
#define MAT4_H
#include "vec4.h"
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

namespace mat
{

	//mat4 rotate(float iAngle, MAT::vec4& Axis);

	class mat4
	{
	private:

	public:
	
		float matrixData[16] = { 0.0 };

		mat4();

		//vec4 operator*(const vec4& value);

		//static mat4 rotate(float iAngle, MAT::vec4& Axis);
		void show();


		~mat4();
	};













}

#endif
