#ifndef MAT_HPP
#define MAT_HPP

#include "vec.hpp"
#include "utils.hpp"
//#include "mat4.h"
//#include "vec3.h"
//#include "quat.h"


namespace mat {


    /*mat4 rotate(float iAngle, mat::vec4 & Axis) 
	{
		const float a =  radians(iAngle);
		const float c = cos(a);
		const float s = sin(a);
		mat::vec4  axis = Axis.normalize();
		mat::mat4 Rotate;
		Rotate.matrixData[0] = c + (axis.x * axis.x) * (float(1) - c);
		Rotate.matrixData[1] = (axis.x * axis.y) * (float(1) - c) - axis.z * s;
		Rotate.matrixData[2] = (axis.x * axis.z) * (float(1) - c) + axis.y * s;
		Rotate.matrixData[4] = (axis.y * axis.x) * (float(1) - c) + axis.z * s;
		Rotate.matrixData[5] = c + (axis.y * axis.y) * (float(1) - c);
		Rotate.matrixData[6] = (axis.y * axis.z) * (float(1) - c) - axis.x * s;
		Rotate.matrixData[8] = (axis.z * axis.x) * (float(1) - c) -  axis.y * s;
		Rotate.matrixData[9] = (axis.z * axis.y) * (float(1) - c) +  axis.x * s;
		Rotate.matrixData[10] = c + (axis.z * axis.z) * (float(1) - c);
		Rotate.matrixData[15] = 1;
		Rotate.show();
		return Rotate;
	}

	quat rotate(vec4 & vec,float iAngle, vec4 &  iAxis)
    {
        quat p(0, vec.x, vec.y, vec.z);
        iAxis = iAxis.normalize();
        quat q(iAngle, iAxis.x, iAxis.y, iAxis.z);
        q.unitNorm();
        quat qInverse = q.inverse();
        quat rotateVector = q * p * qInverse;
        rotateVector.show();
        return rotateVector;
    }*/
}

#endif