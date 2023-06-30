#ifndef VEC4_H
#define VEC4_H
#include "mat4.h"
#include <immintrin.h>
#include <xmmintrin.h>
#include <iomanip>


namespace gym
{

	class mat4;
	class vec4
	{
	private:

	public:
		
		union {

			struct{
				float x;
				float y;
				float z;
				float w;
			};

			__m128 v;

		};

		vec4();
		vec4(float uX, float uY, float uZ, float uW);
		
		//~vec4();

		//vec4(const vec4& ivec);
		vec4& operator=(const vec4& ivec);


		void operator+=(const vec4& ivec);
		vec4 operator+(const vec4& ivec)const;
		void operator-=(const vec4& ivec);
		vec4 operator-(const vec4& ivec)const;
		void operator *=(const vec4& ivec);
		vec4 operator*(const float s)const;
		vec4 operator*(const vec4& ivec);


		void operator/=(const vec4& ivec);
		vec4 operator/(const vec4& ivec)const;
		vec4 cross(const vec4& ivec)const;
		void operator %=(const vec4& ivec);
		vec4 operator%(const vec4& ivec)const;

		vec4 operator*(const gym::mat4& m);

		float magnitude();
		
		vec4 normalize();
		vec4 normalizeQ();

		void show();


		
	};
}





#endif