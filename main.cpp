#include <iostream>
#include <GYM.h>

// std::ostream& operator<<(std::ostream& os, const vec4& inputv)
// {
// 	std::cout << "(" << inputv.v[0] << " " << inputv.v[1] << " " << inputv.v[2] << " " << inputv.v[3] << ")";
// 	return os;
// }

void RotationMatrix(gym::vec4 iPos, gym::vec4 iAxis, float iAngle)
{
	gym::mat4 Rotation = gym::rotate(30, iAxis);
	iPos = iPos * Rotation;
	iPos.show();
}

void Quaternions(gym::vec4 iPos, gym::vec4 iAxis, float iAngle)
{
	//MAT::quat quaternion = MAT::rotate(Position, Angle, Axis);
}

int main()
{
	std::cout << "Test begin " << std::endl;

	gym::vec4 Position{ 5, -5, -5, 0};
	gym::vec4 Axis{1, 1, 0, 0};
	float Angle = 30;
	RotationMatrix(Position, Axis, Angle);
	//Quaternions(gym::vec4 iPos, gym::vec4 iAxis, float iAngle); 

	return 0;
}