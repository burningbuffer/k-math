#include <iostream>
#include <kma/kma.hpp>
#include <catch.hpp>

TEST_CASE("Vector Multiplication", "[vector-tests]") {

    kma::vec2 a{ 1,2 };
    kma::vec2 b{ 2,3 };

    kma::vec2 r = a * b;

    REQUIRE(r.x == 2);
    REQUIRE(r.y == 6);
}

TEST_CASE("Vector Addition", "[vector-tests]") {

    kma::vec2 a{ 1,2 };
    kma::vec2 b{ 2,3 };

    kma::vec2 r = a + b;

    REQUIRE(r.x == 3);
    REQUIRE(r.y == 5);
}

TEST_CASE("Vector Subtraction", "[vector-tests]") {

    kma::vec2 a{ 1,2 };
    kma::vec2 b{ 2,3 };

    kma::vec2 r = a - b;

    REQUIRE(r.x == -1);
    REQUIRE(r.y == -1);
}