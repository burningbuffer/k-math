#ifndef MAT_H
#define MAT_H

#include "vec4.h"
#include "mat4.h"
#include "vec3.h"
#include "quat.h"


namespace gym {


    inline float radians(double iAngle)
	{
		return (float)(iAngle * M_PI / 180);
	}


    mat4 rotate(float iAngle, gym::vec4& Axis) 
	{
		const float a =  radians(iAngle);
		const float c = cos(a);
		const float s = sin(a);
		gym::vec4 axis = Axis.normalize();
		gym::mat4 Rotate;
		Rotate.matrixData[0] = c + (axis.v[0] * axis.v[0]) * (float(1) - c);
		Rotate.matrixData[1] = (axis.v[0] * axis.v[1]) * (float(1) - c) - axis.v[2] * s;
		Rotate.matrixData[2] = (axis.v[0] * axis.v[2]) * (float(1) - c) + axis.v[1] * s;
		Rotate.matrixData[4] = (axis.v[1] * axis.v[0]) * (float(1) - c) + axis.v[2] * s;
		Rotate.matrixData[5] = c + (axis.v[1] * axis.v[1]) * (float(1) - c);
		Rotate.matrixData[6] = (axis.v[1] * axis.v[2]) * (float(1) - c) - axis.v[0] * s;
		Rotate.matrixData[8] = (axis.v[2] * axis.v[0]) * (float(1) - c) -  axis.v[1] * s;
		Rotate.matrixData[9] = (axis.v[2] * axis.v[1]) * (float(1) - c) +  axis.v[0] * s;
		Rotate.matrixData[10] = c + (axis.v[2] * axis.v[2]) * (float(1) - c);
		Rotate.matrixData[15] = 1;
		Rotate.show();
		return Rotate;
	}

	quat rotate(vec4& vec,float iAngle, vec4&  iAxis)
    {
        quat p(0, vec.v[0],vec.v[1],vec.v[2]);
        iAxis = iAxis.normalize();
        quat q(iAngle, iAxis.v[0], iAxis.v[1], iAxis.v[2]);
        q.unitNorm();
        quat qInverse = q.inverse();
        quat rotateVector = q * p * qInverse;
        rotateVector.show();
        return rotateVector;
    }
}

#endif