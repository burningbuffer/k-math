#ifndef QUAT_H
#define QUAT_H
#include "vec4.h"


namespace mat {

	class quat
	{

	public:

		vec4 q;

		quat(float w, float x, float y, float z);
		quat(vec4 v);
		quat(const  quat& value);
		~quat();

		quat operator*(const quat& q)const;
		quat& operator=(const quat& value);
		void operator*=(const float value);

		void unitNorm();
		quat inverse();
		quat conjugate();
		float norm();
		void normalize();

		void show();

		//quat rotate(vec4& vec,float iAngle, vec4&  uAxis);


	};
}


#endif