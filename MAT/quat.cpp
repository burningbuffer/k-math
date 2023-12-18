#include "quat.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>

namespace mat
{

	quat::quat(float w, float x, float y, float z)
	{
		q = vec4(w, x, y, z);
	}

	quat::quat(const quat& value)
	{
		q = value.q;
	}

	quat::quat(vec4 v)
	{
		q = v;
	}

	quat::~quat(){}

	quat quat::operator*(const quat& iq)const
	{
		vec4 nvec;
		nvec.x = q.x * iq.q.x - q.y * iq.q.y - q.z * iq.q.z - q.w * iq.q.w;
		nvec.y = q.y * iq.q.x + q.x * iq.q.y + q.z * iq.q.w - q.w * iq.q.z;
		nvec.z = q.z * iq.q.x + q.x * iq.q.z + q.w * iq.q.y - q.y * iq.q.w;
		nvec.w = q.w * iq.q.x + q.x * iq.q.w + q.y * iq.q.z - q.z * iq.q.y;
		return quat(nvec);
	}

	quat& quat::operator=(const quat& iq)
	{
		q = iq.q;
		return (*this);
	}

	void quat::operator*=(const float value)
	{
		q = q * value;
	}

	inline float radians(double Angle)
	{
		return (float)(Angle * M_PI / 180);
	}

	void quat::unitNorm()
	{
		auto half = radians(q.x) * 0.5;
		q.normalizeQ();

		q.x = cosf(half);
		q.y = q.y * sinf(half);
		q.z = q.z * sinf(half);
		q.w = q.w * sinf(half);
	}

	quat quat::inverse()
	{
	
		float abs = norm();
		abs = abs * abs;
		abs = 1 / abs;
		quat conjugateValue = conjugate();
		vec4 ax = vec4(abs, abs, abs, abs);
		vec4 az = vec4(conjugateValue.q.x, conjugateValue.q.y, conjugateValue.q.z, conjugateValue.q.w);
		vec4 at = az * ax;
		return quat(at);

	}

	quat quat::conjugate()
	{
		vec4 aux = vec4(q.x, -q.y, -q.z, -q.w);
		return quat(aux);
	}

	float quat::norm()
	{
		 float scalar = q.x * q.x;
		 float imaginary = q.y * q.y + q.z * q.z + q.w * q.w;
		 return sqrt(scalar+imaginary);
	}

	void quat::normalize()
	{
		if (norm() != 0)
		{
			float normValue = 1 / norm();
			q.x = q.x * normValue;
			q.y = q.y * normValue;
			q.z = q.z * normValue;
			q.w = q.w * normValue;
		}
	}

	void quat::show()
	{
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.x << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.y << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.z << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.w << " ";
		std::cout << std::endl;
	}
}