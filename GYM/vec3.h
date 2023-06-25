#ifndef VEC3_H
#define VEC3_H

namespace gym
{
	class vec3
	{
	private:

	public:

		float x;
		float y;
		float z;

		vec3();
		vec3(float uX, float uY, float uZ);
		vec3(const vec3& v);
		~vec3();

		vec3& operator=(const vec3& v);
		vec3 operator*(const float s) const;
		float operator*(const vec3& v) const;
		vec3 operator+(const vec3& v)const;
		void operator*=(const float s);

		float magnitude();
		void normalize();

		float dot(const vec3& v) const;
		vec3 cross(const vec3& v)const;
	};




}





#endif