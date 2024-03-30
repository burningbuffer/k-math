#pragma once

namespace kma
{
	struct vec3
	{

		struct 
		{
			float x;
			float y;
			float z;
		};
		
		vec3() :x(0.0), y(0.0), z(0.0) {};

		vec3(float uX, float uY, float uZ) :x(uX), y(uY), z(uZ) {};

		vec3 operator+(const vec3& ivec)	const {return vec3(x + ivec.x, y + ivec.y, z + ivec.z);}
		vec3 operator-(const vec3& ivec)	const {return vec3(x - ivec.x, y - ivec.y, z - ivec.z);}
		vec3 operator*(const vec3& ivec)    const {return vec3(x * ivec.x, y * ivec.y, z * ivec.z);}
		vec3 operator*(const float s)		const {return vec3(s * x, s * y, s * z);}
		vec3 operator/(const vec3& ivec)	const {return vec3(x / ivec.x, y / ivec.y, z / ivec.z);}
		vec3& operator=(const vec3& ivec) {
			x = ivec.x;
			y = ivec.y;
			z = ivec.z;

			return *this;
		}

		vec3 Add(const vec3& a, const vec3& b) const {return vec3(a.x + b.x, a.y + b.y, a.z + b.z);}
		vec3 Sub(const vec3& a, const vec3& b) const {return vec3(a.x - b.x, a.y - b.y, a.z - b.z);}
		vec3 Mul(const vec3& a, const vec3& b) const {return vec3(a.x * b.x, a.y * b.y, a.z * b.z);}
		vec3 Mul(const vec3& a, const float s) const {return vec3(a.x * s, a.y * s, a.z * s);}
		vec3 Div(const vec3& a, const vec3& b) const {return vec3(a.x / b.x, a.y / b.y, a.z / b.z);}

		vec3 normalize() {
			float mag = std::sqrt(x * x + y * y + z * z);
			if (mag > 0.0f)
			{
				x = x * 1.0f / mag;
				y = y * 1.0f / mag;
				z = z * 1.0f / mag;
			}
			return *this;
		}
		
		float length() {return sqrt(x * x + y * y + z * z);}

	};

	float dot(vec3 a, vec3 b) {return a.x * b.x + a.y * b.y + a.z * b.z;}

	vec3 cross(vec3 a, vec3 b) {
		return vec3(a.y * b.z - a.z * b.y,
					a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x);
	}

	/// temporary ///
	vec3 RotateOnX(vec3 v, float Angle) {
		vec3 rotated
		{
			v.x,
				v.y * cos(Angle) - v.z * sin(Angle),
				v.y * sin(Angle) + v.z * cos(Angle)
		};
		return rotated;
	}

	vec3 RotateOnY(vec3 v, float Angle) {
		vec3 rotated
		{
			v.x * cos(Angle) - v.z * sin(Angle),
				v.y,
				v.x * sin(Angle) + v.z * cos(Angle)
		};
		return rotated;
	}

	vec3 RotateOnZ(vec3 v, float Angle)
	{
		vec3 rotated
		{
			v.x * cos(Angle) - v.y * sin(Angle),
				v.x * sin(Angle) + v.y * cos(Angle),
				v.z
		};
		return rotated;
	}
	/// ////
}