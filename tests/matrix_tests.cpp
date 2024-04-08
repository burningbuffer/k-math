#include <iostream>
#include <kma/kma.hpp>
#include <catch.hpp>

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

    REQUIRE(matrixMul.matrix[0][0] == 14);
	REQUIRE(matrixMul.matrix[0][1] == 21);
	REQUIRE(matrixMul.matrix[0][2] == 36);
	REQUIRE(matrixMul.matrix[0][3] == 26);

	REQUIRE(matrixMul.matrix[1][0] == 14);
	REQUIRE(matrixMul.matrix[1][1] == 21);
	REQUIRE(matrixMul.matrix[1][2] == 36);
	REQUIRE(matrixMul.matrix[1][3] == 26);

	REQUIRE(matrixMul.matrix[2][0] == 14);
	REQUIRE(matrixMul.matrix[2][1] == 21);
	REQUIRE(matrixMul.matrix[2][2] == 36);
	REQUIRE(matrixMul.matrix[2][3] == 26);

	REQUIRE(matrixMul.matrix[3][0] == 14);
	REQUIRE(matrixMul.matrix[3][1] == 21);
	REQUIRE(matrixMul.matrix[3][2] == 36);
	REQUIRE(matrixMul.matrix[3][3] == 26);
}

TEST_CASE("Vec4 Mat4 Multiplication", "[matrix-tests]") 
{

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

	kma::vec4 vectorAB = vectorA * matrixB;


	REQUIRE(vectorAA.x == 9);
	REQUIRE(vectorAA.y == 18);
	REQUIRE(vectorAA.z == 36);
	REQUIRE(vectorAA.w == 18);

	REQUIRE(vectorAB.x == 14);
	REQUIRE(vectorAB.y == 21);
	REQUIRE(vectorAB.z == 36);
	REQUIRE(vectorAB.w == 26);
}
