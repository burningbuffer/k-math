#include <iostream>
#include "vec4.h"
namespace gym
{

	vec4::vec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
		
	}
	
	vec4::vec4(float uX, float uY, float uZ, float uW)
	{
		x = uX;
		y = uY;
		z = uZ;
		w = uW;
	}

	vec4::vec4(__m128 iv)
	{
		v = iv;
	}
	
	vec4& vec4::operator=(const vec4& ivec)
	{
		x = ivec.x;
		y = ivec.y;
		z = ivec.z;
		w = ivec.w;

		return *this;
	}

	void vec4::operator+=(const vec4& ivec)
	{
		x += ivec.x;
		y += ivec.y;
		z += ivec.z;
		w += ivec.w;
	}

	vec4 vec4::operator+(const vec4& ivec)const
	{
		//return vec4(x + ivec.x, y + ivec.y, z + ivec.z, w + ivec.w);
		return vec4(_mm_add_ps(v,ivec.v));
	}

	void vec4::operator-=(const vec4& ivec)
	{
		x -= ivec.x;
		y -= ivec.y;
		z -= ivec.z;
		w -= ivec.w;
	}

	vec4 vec4::operator-(const vec4& ivec)const
	{
		//return vec4(x - ivec.x, y - ivec.y, z - ivec.z, w - ivec.w);
		return vec4(_mm_sub_ps(v,ivec.v));
	}

	void vec4::operator*=(const vec4& ivec)
	{
		x *= ivec.x;
		y *= ivec.y;
		z *= ivec.z;
		w *= ivec.w;
	}

	vec4 vec4::operator*(const float s)const
	{
		//return vec4(s * x, s * y, s * z, s * w);
		return vec4(_mm_mul_ps(v,_mm_set1_ps(s)));
	}

	vec4 vec4::operator*(const vec4& ivec)
	{
		//return vec4( x * ivec.x, y * ivec.y, z * ivec.z, w * ivec.w);
		return vec4(_mm_mul_ps(v,ivec.v));
	}
	
	void vec4::operator/=(const vec4& ivec)
	{
		x /= ivec.x;
		y /= ivec.y;
		z /= ivec.z;
		z /= ivec.w;
	}

	vec4 vec4::operator/(const vec4& ivec)const
	{
		//return vec4(x / ivec.x, y / ivec.y, z / ivec.z, w / ivec.w);
		return vec4(_mm_div_ps(v,ivec.v));
	}

	vec4 vec4::cross(const vec4& ivec)const
	{
		//return vec4(y * ivec.z - z * ivec.y, z * ivec.x - x * ivec.z, x * ivec.y - y * ivec.x, 1);

		__m128 x = v;
		__m128 y = ivec.v;
		__m128 tmp0 = _mm_shuffle_ps(x, x, _MM_SHUFFLE(3, 0, 2, 1));
		__m128 tmp1 = _mm_shuffle_ps(y, y, _MM_SHUFFLE(3, 1, 0, 2));
		__m128 tmp2 = _mm_shuffle_ps(x, x, _MM_SHUFFLE(3, 1, 0, 2));
		__m128 tmp3 = _mm_shuffle_ps(y, y, _MM_SHUFFLE(3, 0, 2, 1));
		return vec4(_mm_sub_ps(_mm_mul_ps(tmp0, tmp1),_mm_mul_ps(tmp2, tmp3)));
	}

	void vec4::operator%=(const vec4& ivec)
	{
		*this = cross(ivec);
	}

	vec4 vec4::operator%(const vec4& ivec)const
	{
		return vec4(y * ivec.z - z * ivec.y,
					z * ivec.x - x * ivec.z,
					x * ivec.y - y * ivec.x,
					1);
	}
	
	vec4 vec4::operator*(const gym::mat4& imat) 
	{
		// vec4 nv;
		// nv.x = x * m.matrixData[0] + y * m.matrixData[1] + z * m.matrixData[2] + w * m.matrixData[3];
		// nv.y = x * m.matrixData[4] + y * m.matrixData[5] + z * m.matrixData[6] + w * m.matrixData[7];
		// nv.z = x * m.matrixData[8] + y * m.matrixData[9] + z * m.matrixData[10] + w * m.matrixData[11];
		// nv.w = x * m.matrixData[12] + y * m.matrixData[13] + z * m.matrixData[14] + w * m.matrixData[15];
		// return nv;
		 
		//__m128 v = _mm_load_ps(vec.v);
		__m128 m0 = _mm_load_ps(&imat.matrixData[0]);
		__m128 m1 = _mm_load_ps(&imat.matrixData[4]);
		__m128 m2 = _mm_load_ps(&imat.matrixData[8]);
		__m128 m3 = _mm_load_ps(&imat.matrixData[12]);

		_MM_TRANSPOSE4_PS(m0, m1, m2, m3);

		__m128 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
		__m128 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
		__m128 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
		__m128 w = _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3));

		__m128 r0 = _mm_mul_ps(m0, x);
		__m128 r1 = _mm_mul_ps(m1, y);
		__m128 r2 = _mm_mul_ps(m2, z);
		__m128 r3 = _mm_mul_ps(m3, w);

		__m128 r01 = _mm_add_ps(r0, r1);
		__m128 r23 = _mm_add_ps(r2, r3);
		__m128 r = _mm_add_ps(r01, r23);

		return vec4(r);
	}
	
	float vec4::magnitude()
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	vec4 vec4::normalize()
	{
		float mag = std::sqrt(x * x + y * y + z * z);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;

		}
		return (*this);
	}

	vec4 vec4::normalizeQ()
	{
		float mag = std::sqrt(y * y + z * z + w * w);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;

		}
		return (*this);
	}

	void vec4::show()
	{
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << x << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << y << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << z << " ";
		std::cout << std::setw(10) << std::setprecision(6) << std::fixed << w << " ";
		std::cout << std::endl;

	}
}