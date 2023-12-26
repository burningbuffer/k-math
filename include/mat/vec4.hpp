#ifndef vec4 _HPP
#define vec4 _HPP
//#include "mat4.h"
#include <immintrin.h>
#include <xmmintrin.h>
#include <iomanip>

namespace mat
{

	class vec4
	{

	public:

		union {

			struct {
				float x;
				float y;
				float z;
				float w;
			};

			__m128 v;

		};

		vec4();
		vec4(float uX, float uY, float uZ, float uW);
		vec4(__m128 iv);

		vec4 operator+(const vec4& ivec)	const;
		vec4 operator-(const vec4& ivec)	const;
		vec4 operator*(const vec4& ivec)    const;
		vec4 operator*(const float s)		const;
		vec4 operator/(const vec4& ivec)	const;
		vec4 operator%(const vec4& ivec)	const;

		vec4& operator=(const vec4& ivec);
		//vec4  operator*(const mat::mat4& m);
		float magnitude() const;

		vec4 normalize();

		void show();


		
	};
}





#endif