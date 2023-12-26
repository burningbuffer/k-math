#include <iostream>
#include <mat/mat.hpp>

//void RotationMatrix(mat::vec4  iPos, mat::vec4  iAxis, float iAngle)
//{
//	mat::mat4 Rotation = mat::rotate(30, iAxis);
//	iPos = iPos * Rotation;
//	iPos.show();
//}

//void Quaternions(mat::vec4  iPos, mat::vec4  iAxis, float iAngle)
//{
//	MAT::quat quaternion = MAT::rotate(Position, Angle, Axis);
//}

int main()
{
	std::cout << "Test Demo" << std::endl;

	mat::vec4  Position{ 5, -5, -5, 0};
	mat::vec4  Axis{1, 1, 0, 0};
	float Angle = 30;
	float scalar = 5;

	//mat::vec4  Pos = Position * scalar;
	mat::vec4  Pos = Position * scalar;
	//mat::vec4  SumB = mat::Add(Position, Position);
	std::cout << "Pos: " << Pos << std::endl;



	//Quaternions(mat::vec4  iPos, mat::vec4  iAxis, float iAngle); 

	return 0;
}