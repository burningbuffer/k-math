#include <kma/kma.hpp>
#include <catch.hpp>
#include <iostream>
#include <iomanip>

using namespace Catch::Matchers;

TEST_CASE("Vec2 Operations", "[vector-tests]") 
{

    kma::vec2 a{ 1,2 };
    kma::vec2 b{ 2,3 };

    kma::vec2 vec2mul = a * b;
    kma::vec2 vec2add = a + b;
    kma::vec2 vec2sub = a - b;

    kma::vec2 vec2mul_expected{ 2, 6 };
    kma::vec2 vec2add_expected{ 3, 5 };
    kma::vec2 vec2sub_expected{ -1, -1 };

    REQUIRE_THAT(vec2mul.x, WithinRel(vec2mul_expected.x, 0.1f));
    REQUIRE_THAT(vec2mul.y, WithinRel(vec2mul_expected.y, 0.1f));

    REQUIRE_THAT(vec2add.z, WithinRel(vec2add_expected.z, 0.1f));
    REQUIRE_THAT(vec2add.x, WithinRel(vec2add_expected.x, 0.1f));

    REQUIRE_THAT(vec2sub.y, WithinRel(vec2sub_expected.y, 0.1f));
    REQUIRE_THAT(vec2sub.z, WithinRel(vec2sub_expected.z, 0.1f));

}

TEST_CASE("Vec3 Operations", "[vector-tests]") 
{

    kma::vec3 a{ 1,2,-3 };
    kma::vec3 b{ 2,3,4 };

    kma::vec3 vec3mul = a * b;
    kma::vec3 vec3add = a + b;
    kma::vec3 vec3sub = a - b;

    kma::vec3 vec3mul_expected{ 2, 6, -12};
    kma::vec3 vec3add_expected{ 3, 5, 1};
    kma::vec3 vec3sub_expected{ -1, -1, -7};

    REQUIRE_THAT(vec3mul.x, WithinRel(vec3mul_expected.x, 0.1f));
    REQUIRE_THAT(vec3mul.y, WithinRel(vec3mul_expected.y, 0.1f));
    REQUIRE_THAT(vec3mul.z, WithinRel(vec3mul_expected.z, 0.1f));

    REQUIRE_THAT(vec3add.x, WithinRel(vec3add_expected.x, 0.1f));
    REQUIRE_THAT(vec3add.y, WithinRel(vec3add_expected.y, 0.1f));
    REQUIRE_THAT(vec3add.z, WithinRel(vec3add_expected.z, 0.1f));

    REQUIRE_THAT(vec3sub.x, WithinRel(vec3sub_expected.x, 0.1f));
    REQUIRE_THAT(vec3sub.y, WithinRel(vec3sub_expected.y, 0.1f));
    REQUIRE_THAT(vec3sub.z, WithinRel(vec3sub_expected.z, 0.1f));

}

TEST_CASE("Vec4 Operations", "[vector-tests]") 
{

    kma::vec4 a{ 1,2,5,3 };
    kma::vec4 b{ 2,9,4,6 };

    kma::vec4 vec4mul = a * b;
    kma::vec4 vec4add = a + b;
    kma::vec4 vec4sub = a - b;

    kma::vec4 vec4mul_expected{2, 18, 20, 18};
    kma::vec4 vec4add_expected{3, 11, 9, 9};
    kma::vec4 vec4sub_expected{-1, -7, 1, -3};

    REQUIRE_THAT(vec4mul.x , WithinRel(vec4mul_expected.x, 0.1f));
    REQUIRE_THAT(vec4mul.y , WithinRel(vec4mul_expected.y, 0.1f));
    REQUIRE_THAT(vec4mul.z , WithinRel(vec4mul_expected.z, 0.1f));
    REQUIRE_THAT(vec4mul.w , WithinRel(vec4mul_expected.w, 0.1f));

    REQUIRE_THAT(vec4add.x , WithinRel(vec4add_expected.x, 0.1f));
    REQUIRE_THAT(vec4add.y , WithinRel(vec4add_expected.y, 0.1f));
    REQUIRE_THAT(vec4add.z , WithinRel(vec4add_expected.z, 0.1f));
    REQUIRE_THAT(vec4add.w , WithinRel(vec4add_expected.w, 0.1f));

    REQUIRE_THAT(vec4sub.x , WithinRel(vec4sub_expected.x, 0.1f));
    REQUIRE_THAT(vec4sub.y , WithinRel(vec4sub_expected.y, 0.1f));
    REQUIRE_THAT(vec4sub.z , WithinRel(vec4sub_expected.z, 0.1f));
    REQUIRE_THAT(vec4sub.w , WithinRel(vec4sub_expected.w, 0.1f));

}

TEST_CASE("Vec4 Normalize", "[vector-tests]")
{

    kma::vec4 vec{ 1,2,5,0 };

    kma::vec4 vec4_normalize = vec.normalize();

    kma::vec4 vec4_expected{ 0.182574, 0.365148, 0.912871, 0.000000 };

    REQUIRE_THAT(vec4_normalize.x, WithinRel(vec4_expected.x, 0.1f));
    REQUIRE_THAT(vec4_normalize.y, WithinRel(vec4_expected.y, 0.1f));
    REQUIRE_THAT(vec4_normalize.z, WithinRel(vec4_expected.z, 0.1f));
    REQUIRE_THAT(vec4_normalize.w, WithinRel(vec4_expected.w, 0.1f));

}

TEST_CASE("Vec3 Normalize", "[vector-tests]")
{

    kma::vec3 vec{ 1,2,5};

    kma::vec3 vec3_normalize = vec.normalize();

    kma::vec3 vec3_expected{ 0.182574, 0.365148, 0.912871 };

    REQUIRE_THAT(vec3_normalize.x, WithinRel(vec3_expected.x, 0.1f));
    REQUIRE_THAT(vec3_normalize.y, WithinRel(vec3_expected.y, 0.1f));
    REQUIRE_THAT(vec3_normalize.z, WithinRel(vec3_expected.z, 0.1f));

}

TEST_CASE("Radians Tests", "[radians-tests]")
{

    float Angle90 = 90;
    float AngleMinus90 = -90;

    float Angle90_expected = 1.570796;
    float AngleMinus90_expected = -1.570796;

    REQUIRE_THAT(kma::radians(Angle90), WithinRel(Angle90_expected, 0.1f));
    REQUIRE_THAT(kma::radians(AngleMinus90), WithinRel(AngleMinus90_expected, 0.1f));

}