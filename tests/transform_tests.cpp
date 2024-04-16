#include <kma/kma.hpp>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("Rotation", "[transform-tests]")
{
	kma::vec4 Pos{ 2, 5, -10, 1 };
	kma::vec4 Axis{ 1, 1, 1, 0 };
	float Angle = kma::radians(90.0f);

	kma::mat4 rotationMatrix = kma::rotate(Angle, Axis);

	kma::vec4 result = Pos * rotationMatrix;

	kma::vec4 rotation_expected{ -9.66025, 5.9282, 0.73205, 1 };

	REQUIRE_THAT(result.x, WithinRel(rotation_expected.x, 0.1f));
	REQUIRE_THAT(result.y, WithinRel(rotation_expected.y, 0.1f));
	REQUIRE_THAT(result.z, WithinRel(rotation_expected.z, 0.1f));
	REQUIRE_THAT(result.w, WithinRel(rotation_expected.w, 0.1f));

}

TEST_CASE("Scaling", "[transform-tests]")
{

	kma::vec4 Pos{ 5,5,5,1 };
	kma::vec4 ScaleFactor{ 1,2,3,0 };
	kma::mat4 scaleMatrix = kma::scale(ScaleFactor);

	kma::vec4 result = Pos * scaleMatrix;

	kma::vec4 scale_expected{ 5, 10, 15, 1 };

	REQUIRE_THAT(result.x, WithinRel(scale_expected.x, 0.1f));
	REQUIRE_THAT(result.y, WithinRel(scale_expected.y, 0.1f));
	REQUIRE_THAT(result.z, WithinRel(scale_expected.z, 0.1f));
	REQUIRE_THAT(result.w, WithinRel(scale_expected.w, 0.1f));

}

TEST_CASE("Translation", "[transform-tests]")
{

	kma::vec4 Pos{ 5,5,5,1 };
	kma::vec4 TranslationFactor{ 3,3,3,0 };
	kma::mat4 TranslationMatrix = kma::translate(TranslationFactor);

	kma::vec4 result = Pos * TranslationMatrix;

	kma::vec4 translation_expected{ 8, 8, 8, 1 };

	REQUIRE_THAT(result.x, WithinRel(translation_expected.x, 0.1f));
	REQUIRE_THAT(result.y, WithinRel(translation_expected.y, 0.1f));
	REQUIRE_THAT(result.z, WithinRel(translation_expected.z, 0.1f));
	REQUIRE_THAT(result.w, WithinRel(translation_expected.w, 0.1f));

}


