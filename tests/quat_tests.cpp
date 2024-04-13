#include <kma/kma.hpp>
#include <catch.hpp>

TEST_CASE("Quaternion Multiplication", "[quaternion-tests]") 
{
    float AngleA = 90.0f;
    kma::vec4 vecA{1.0f, 2.0f, 3.0f,0.0f};
    kma::quat quaternionA {AngleA, vecA};

    float AngleB = 45.0f;
    kma::vec4 vecB{4.0f, 5.0f, 6.0f, 0.0f};
    kma::quat quaternionB {AngleB, vecB};
    
    kma::quat mult = quaternionA * quaternionB;

    REQUIRE(mult.x == 4018);
    REQUIRE(mult.y == 402);
    REQUIRE(mult.z == 546);
    REQUIRE(mult.w == 672);
}

TEST_CASE("Quaternion Operations", "[quaternion-tests]") 
{

}

TEST_CASE("Quaternion Rotations", "[quaternion-tests]") 
{

}