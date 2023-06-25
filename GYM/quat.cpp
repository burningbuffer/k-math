#include "quat.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>

namespace gym
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
		nvec.v[0] = q.v[0] * iq.q.v[0] - q.v[1] * iq.q.v[1] - q.v[2] * iq.q.v[2] - q.v[3] * iq.q.v[3];
		nvec.v[1] = q.v[1] * iq.q.v[0] + q.v[0] * iq.q.v[1] + q.v[2] * iq.q.v[3] - q.v[3] * iq.q.v[2];
		nvec.v[2] = q.v[2] * iq.q.v[0] + q.v[0] * iq.q.v[2] + q.v[3] * iq.q.v[1] - q.v[1] * iq.q.v[3];
		nvec.v[3] = q.v[3] * iq.q.v[0] + q.v[0] * iq.q.v[3] + q.v[1] * iq.q.v[2] - q.v[2] * iq.q.v[1];
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
		auto half = radians(q.v[0]) * 0.5;
		q.normalizeQ();

		q.v[0] = cosf(half);
		q.v[1] = q.v[1] * sinf(half);
		q.v[2] = q.v[2] * sinf(half);
		q.v[3] = q.v[3] * sinf(half);
	}

	quat quat::inverse()
	{
	
		float abs = norm();
		abs = abs * abs;
		abs = 1 / abs;
		quat conjugateValue = conjugate();
		vec4 ax = vec4(abs, abs, abs, abs);
		vec4 az = vec4(conjugateValue.q.v[0], conjugateValue.q.v[1], conjugateValue.q.v[2], conjugateValue.q.v[3]);
		vec4 at = az * ax;
		return quat(at);

	}

	quat quat::conjugate()
	{
		vec4 aux = vec4(q.v[0], -q.v[1], -q.v[2], -q.v[3]);
		return quat(aux);
	}

	float quat::norm()
	{
		 float scalar = q.v[0] * q.v[0];
		 float imaginary = q.v[1] * q.v[1] + q.v[2] * q.v[2] + q.v[3] * q.v[3];
		 return sqrt(scalar+imaginary);
	}

	void quat::normalize()
	{
		if (norm() != 0)
		{
			float normValue = 1 / norm();
			q.v[0] = q.v[0] * normValue;
			q.v[1] = q.v[1] * normValue;
			q.v[2] = q.v[2] * normValue;
			q.v[3] = q.v[3] * normValue;
		}
	}

	void quat::show()
	{
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.v[0] << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.v[1] << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.v[2] << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << q.v[3] << " ";
		std::cout << std::endl;
	}
}