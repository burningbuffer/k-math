#include <iostream>
#include <kma/kma.hpp>
#include <cassert>

void vector_multiplication()
{
	// VEC2
	kma::vec2 a{ 1,2 };
	kma::vec2 b{ 3,4 };
	kma::vec2 c = a * b;

	assert(c.x() == 3);
	assert(c.y() == 8);

	// VEC3
	kma::vec3 d{ 1,2,3 };
	kma::vec3 e{ 3,4,5 };
	kma::vec3 f = d * e;

	assert(f.x() == 3);
	assert(f.y() == 8);
	assert(f.z() == 15);

	// VEC4
	kma::vec4 g{ 1,2,3,4 };
	kma::vec4 h{ 3,4,5,6 };
	kma::vec4 i = g * h;

	assert(i.x() == 3);
	assert(i.y() == 8);
	assert(i.z() == 15);
	assert(i.w() == 24);
}

void test_vectors()
{
	vector_multiplication();

}

int main()
{
	test_vectors();
}