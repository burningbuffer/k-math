#pragma once
#include "../include/kma/vec4.hpp"
namespace kma
{
	class quat
	{

	public:

		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
		
			__m128 q;
		};

		///
		/// constructors
		///

		quat(float uS, vec4& uV);

		quat(__m128 iq);

		quat(vec4 v);

		quat(const  quat& value);

		///
		/// overloaded operators
		///
		
		quat operator*(const quat& q)const;

		quat& operator=(const quat& value);

		/// 
		/// 
		/// 

		quat inverse();

		__m128 conjugate();

		__m128 norm();

		__m128 normalize();


	};

}