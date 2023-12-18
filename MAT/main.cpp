#include <iostream>
#include "mat.h"

// std::ostream& operator<<(std::ostream& os, const vec4& inputv)
// {
// 	std::cout << "(" << inputv.v[0] << " " << inputv.v[1] << " " << inputv.v[2] << " " << inputv.v[3] << ")";
// 	return os;
// }

void RotationMatrix(mat::vec4 iPos, mat::vec4 iAxis, float iAngle)
{
	mat::mat4 Rotation = mat::rotate(30, iAxis);
	iPos = iPos * Rotation;
	iPos.show();
}

void Quaternions(mat::vec4 iPos, mat::vec4 iAxis, float iAngle)
{
	//MAT::quat quaternion = MAT::rotate(Position, Angle, Axis);
}

int main()
{
	std::cout << "Test begin B" << std::endl;

	mat::vec4 Position{ 5, -5, -5, 0};
	mat::vec4 Axis{1, 1, 0, 0};
	float Angle = 30;
	RotationMatrix(Position, Axis, Angle);
	//Quaternions(mat::vec4 iPos, mat::vec4 iAxis, float iAngle); 

	return 0;
}