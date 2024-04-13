#include <kma/kma.hpp>
#include <catch.hpp>
#include <iostream>

TEST_CASE("Mat4 Multiplication", "[matrix-tests]") 
{

	kma::mat4 matrixA{ 1.0f,2.0f,4.0f,2.0f,
					   1.0f,2.0f,4.0f,2.0f,
					   1.0f,2.0f,4.0f,2.0f,
					   1.0f,2.0f,4.0f,2.0f };

	kma::mat4 matrixB{ 2.0f,1.0f,4.0f,2.0f,
					   1.0f,2.0f,3.0f,6.0f,
					   2.0f,3.0f,4.0f,1.0f,
					   1.0f,2.0f,5.0f,4.0f };

	kma::mat4 matrixMul = matrixA * matrixB;

	kma::vec4 vecmul{ 14,21,36,26 };

    REQUIRE(matrixMul.matrix[0][0] == vecmul.x);
	REQUIRE(matrixMul.matrix[0][1] == vecmul.y);
	REQUIRE(matrixMul.matrix[0][2] == vecmul.z);
	REQUIRE(matrixMul.matrix[0][3] == vecmul.w);

	REQUIRE(matrixMul.matrix[1][0] == vecmul.x);
	REQUIRE(matrixMul.matrix[1][1] == vecmul.y);
	REQUIRE(matrixMul.matrix[1][2] == vecmul.z);
	REQUIRE(matrixMul.matrix[1][3] == vecmul.w);

	REQUIRE(matrixMul.matrix[2][0] == vecmul.x);
	REQUIRE(matrixMul.matrix[2][1] == vecmul.y);
	REQUIRE(matrixMul.matrix[2][2] == vecmul.z);
	REQUIRE(matrixMul.matrix[2][3] == vecmul.w);

	REQUIRE(matrixMul.matrix[3][0] == vecmul.x);
	REQUIRE(matrixMul.matrix[3][1] == vecmul.y);
	REQUIRE(matrixMul.matrix[3][2] == vecmul.z);
	REQUIRE(matrixMul.matrix[3][3] == vecmul.w);
}

TEST_CASE("Vec4 Mat4 Multiplication", "[matrix-tests]") 
{
	std::cout << "Vec4 Mat4 Multiplication" << std::endl;

	kma::mat4 matrixA{ 1.0f,2.0f,4.0f,2.0f,
					   1.0f,2.0f,4.0f,2.0f,
					   1.0f,2.0f,4.0f,2.0f,
					   1.0f,2.0f,4.0f,2.0f };

	kma::mat4 matrixB{ 2.0f,1.0f,4.0f,2.0f,
					   1.0f,2.0f,3.0f,6.0f,
					   2.0f,3.0f,4.0f,1.0f,
					   1.0f,2.0f,5.0f,4.0f };

	kma::vec4 vectorA{ 1.0f,2.0f,4.0f,2.0f };

	kma::vec4 vectorAA = vectorA * matrixA;

	std::cout << vectorAA << std::endl;

	kma::vec4 vectorAB = vectorA * matrixB;

	std::cout << vectorAB << std::endl;


	REQUIRE(vectorAA.x == 9);
	REQUIRE(vectorAA.y == 18);
	REQUIRE(vectorAA.z == 36);
	REQUIRE(vectorAA.w == 18);

	REQUIRE(vectorAB.x == 14);
	REQUIRE(vectorAB.y == 21);
	REQUIRE(vectorAB.z == 36);
	REQUIRE(vectorAB.w == 26);
}
