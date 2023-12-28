#include <iostream>
#include <kma/kma.hpp>

//void Rotationkmarix(kma::vec4  iPos, kma::vec4  iAxis, float iAngle)
//{
//	kma::kma4 Rotation = kma::rotate(30, iAxis);
//	iPos = iPos * Rotation;
//	iPos.show();
//}

//void Quaternions(kma::vec4  iPos, kma::vec4  iAxis, float iAngle)
//{
//	kma::quat quaternion = kma::rotate(Position, Angle, Axis);
//}

int main()
{
	std::cout << "Test Demo" << std::endl;

	kma::vec4  Position{ 5, -5, -5, 0};
	kma::vec4  Axis{1, 1, 0, 0};
	float Angle = 30;
	float scalar = 5;

	//kma::vec4  Pos = Position * scalar;
	kma::vec4  Pos = Position * scalar;
	//kma::vec4  SumB = kma::Add(Position, Position);
	std::cout << "Pos: " << Pos << std::endl;

	kma::vec4  vecA{ 1, 2, 3, 4};
	kma::vec4  vecB{2, 5, 8, 0};

	std::cout << "vecA: " << vecA << std::endl;

	float dotproduct = kma::dot(vecA, vecB);
	std::cout << "dotproduct: " << std::endl;

	std::cout << "dotproduct: " << dotproduct << std::endl;

	kma::vec4 crossproduct = kma::cross(vecA, vecB);
	std::cout << "crossproduct: " << crossproduct << std::endl;

	std::cout << "normalizedvector: " << vecA.normalize() << std::endl;


	//Quaternions(kma::vec4  iPos, kma::vec4  iAxis, float iAngle); 

	return 0;
}