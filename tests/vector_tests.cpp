#include <iostream>
#include <kma/kma.hpp>
#include <catch.hpp>

TEST_CASE("Vec2 Operations", "[vector-tests]") 
{

    kma::vec2 a{ 1,2 };
    kma::vec2 b{ 2,3 };

    kma::vec2 vec2mul = a * b;
    kma::vec2 vec2add = a + b;
    kma::vec2 vec2sub = a - b;

    REQUIRE(vec2mul.x == 2);
    REQUIRE(vec2mul.y == 6);

    REQUIRE(vec2add.x == 3);
    REQUIRE(vec2add.y == 5);

    REQUIRE(vec2sub.x == -1);
    REQUIRE(vec2sub.y == -1);
}

TEST_CASE("Vec3 Operations", "[vector-tests]") 
{

    kma::vec3 a{ 1,2,-3 };
    kma::vec3 b{ 2,3,4 };

    kma::vec3 vec3mul = a * b;
    kma::vec3 vec3add = a + b;
    kma::vec3 vec3sub = a - b;

    REQUIRE(vec3mul.x == 2);
    REQUIRE(vec3mul.y == 6);
    REQUIRE(vec3mul.z == -12);

    REQUIRE(vec3add.x == 3);
    REQUIRE(vec3add.y == 5);
    REQUIRE(vec3add.z == 1);

    REQUIRE(vec3sub.x == -1);
    REQUIRE(vec3sub.y == -1);
    REQUIRE(vec3sub.z == -7);
}

TEST_CASE("Vec4 Operations", "[vector-tests]") 
{

    kma::vec4 a{ 1,2,5,3 };
    kma::vec4 b{ 2,9,4,6 };

    kma::vec4 vec4mul = a * b;
    kma::vec4 vec4add = a + b;
    kma::vec4 vec4sub = a - b;

    REQUIRE(vec4mul.x == 2);
    REQUIRE(vec4mul.y == 18);
    REQUIRE(vec4mul.z == 20);
    REQUIRE(vec4mul.w == 18);

    REQUIRE(vec4add.x == 3);
    REQUIRE(vec4add.y == 11);
    REQUIRE(vec4add.z == 9);
    REQUIRE(vec4add.w == 9);

    REQUIRE(vec4sub.x == -1);
    REQUIRE(vec4sub.y == -7);
    REQUIRE(vec4sub.z == 1);
    REQUIRE(vec4sub.w == -3);

   
}