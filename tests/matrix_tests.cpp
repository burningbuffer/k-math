#include <kma/kma.hpp>
#include <catch.hpp>
#include <iostream>

using namespace Catch::Matchers;

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

	REQUIRE_THAT(matrixMul.matrix[0][0], WithinRel(vecmul.x, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[0][1], WithinRel(vecmul.y, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[0][2], WithinRel(vecmul.z, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[0][3], WithinRel(vecmul.w, 0.1f));

	REQUIRE_THAT(matrixMul.matrix[1][0], WithinRel(vecmul.x, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[1][1], WithinRel(vecmul.y, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[1][2], WithinRel(vecmul.z, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[1][3], WithinRel(vecmul.w, 0.1f));

	REQUIRE_THAT(matrixMul.matrix[2][0], WithinRel(vecmul.x, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[2][1], WithinRel(vecmul.y, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[2][2], WithinRel(vecmul.z, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[2][3], WithinRel(vecmul.w, 0.1f));

	REQUIRE_THAT(matrixMul.matrix[3][0], WithinRel(vecmul.x, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[3][1], WithinRel(vecmul.y, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[3][2], WithinRel(vecmul.z, 0.1f));
	REQUIRE_THAT(matrixMul.matrix[3][3], WithinRel(vecmul.w, 0.1f));

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

	kma::vec4 vectorAA_expected{ 9, 18, 36, 18 };
	kma::vec4 vectorAB_expected{ 14, 21, 36, 26 };

	REQUIRE_THAT(vectorAA.x, WithinRel(vectorAA_expected.x, 0.1f));
	REQUIRE_THAT(vectorAA.y, WithinRel(vectorAA_expected.y, 0.1f));
	REQUIRE_THAT(vectorAA.z, WithinRel(vectorAA_expected.z, 0.1f));
	REQUIRE_THAT(vectorAA.w, WithinRel(vectorAA_expected.w, 0.1f));

	REQUIRE_THAT(vectorAB.x, WithinRel(vectorAB_expected.x, 0.1f));
	REQUIRE_THAT(vectorAB.y, WithinRel(vectorAB_expected.y, 0.1f));
	REQUIRE_THAT(vectorAB.z, WithinRel(vectorAB_expected.z, 0.1f));
	REQUIRE_THAT(vectorAB.w, WithinRel(vectorAB_expected.w, 0.1f));

}
