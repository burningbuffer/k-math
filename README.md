# k-math

This project began as a small SIMD math library intended for rotations, and will evolve into a SIMD generalist graphics math library.

## SIMD

SIMD (Simple Instruction Multiple Data) is the resource in microprocessors that permit optimizations with multiple data operations in one machine instruction and it comes as different instruction sets like MMX, SSE (Streaming SIMD Extensions) and AVX (Advanced Vector Extensions).

This library uses SSE with 128 bits registers.

## Usage example
~~~{.cpp}
#include <kma/kma.hpp>

// Vectors

kma::vec2  vecA{ 1, 2 };

kma::vec3  vecB{ 1, 2, 3 };
kma::vec3  vecC{ 4, 5, 6 };

kma::vec3  vecBC = vecB * vecC;

float dot3product = kma::dot(vecB, vecC);
kma::vec3 cross3product = kma::cross(vecB, vecC);

kma::vec4  vecD{ 1, 2, 3, 0 };
kma::vec4  vecE{ 4, 5, 6, 0 };

kma::vec3  vecDE = vecD * vecE;

float dot4product = kma::dot(vecD, vecE);
kma::vec4 cross4product = kma::cross(vecD, vecE);


// Matrix 4x4

kma::mat4 matrixA{}// Identity matrix

kma::mat4 matrixB
{1.0f, 5.0f, 5.0f, 5.0f,
 5.0f, 1.0f, 5.0f, 5.0f,
 5.0f, 5.0f, 1.0f, 5.0f,
 5.0f, 5.0f, 5.0f, 1.0f};

kma::mat4 matrixAB = matrixA * matrixB;

// Quaternions

float AngleA = 90.0f;
kma::vec4 vecA{1.0f, 2.0f, 3.0f,0.0f};
kma::quat quaternionA {AngleA, vecA};// 90.000000   1.000000   2.000000   3.000000 

float AngleB = 45.0f;
kma::vec4 vecB{4.0f, 5.0f, 6.0f, 0.0f};
kma::quat quaternionB {AngleB, vecB};// 45.000000   4.000000   5.000000   6.000000

kma::quat quaternionAB = quaternionA * quaternionB;

~~~

