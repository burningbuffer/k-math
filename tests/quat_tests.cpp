#include <kma/kma.hpp>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("Quaternion Multiplication", "[quaternion-tests]") 
{
    float AngleA = 90.0f;
    kma::vec4 vecA{1.0f, 2.0f, 3.0f,0.0f};
    kma::quat quaternionA {AngleA, vecA};

    float AngleB = 45.0f;
    kma::vec4 vecB{4.0f, 5.0f, 6.0f, 0.0f};
    kma::quat quaternionB {AngleB, vecB};
    
    kma::quat mult = quaternionA * quaternionB;

    kma::vec4 mult_expected{ 4018, 402, 546, 672 };

    REQUIRE_THAT(mult.x, WithinRel(mult_expected.x, 0.1f));
    REQUIRE_THAT(mult.y, WithinRel(mult_expected.y, 0.1f));
    REQUIRE_THAT(mult.z, WithinRel(mult_expected.z, 0.1f));
    REQUIRE_THAT(mult.w, WithinRel(mult_expected.w, 0.1f));

}

TEST_CASE("Quaternion Operations", "[quaternion-tests]") 
{

}

TEST_CASE("Quaternion Rotations", "[quaternion-tests]") 
{

}