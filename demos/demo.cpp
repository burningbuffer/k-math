#include <iostream>
#include <kma/kma.hpp>

void testVec4()
{
	kma::vec4  vecA{ 1, 2, 3, 0};
	std::cout << "vecA: " << vecA << std::endl;
	kma::vec4  vecB{2.04567f, 5, 8, 0};
	std::cout << "vecB: " << vecB << std::endl;
	
	vecB.x = 9;
	vecB.y = 8;
	vecB.z = 7;
	vecB.w = 6;

	std::cout << "vecB: " << vecB << std::endl;

	/*float dotproduct = kma::dot(vecA, vecB);
	std::cout << "vec4 dot product: " << dotproduct << std::endl;

	kma::vec4 crossproduct = kma::cross(vecA, vecB);
	std::cout << "vec4 cross product: " << crossproduct << std::endl;

	std::cout << "vec4 normalized vector: " << vecA.normalize() << std::endl;*/
}

KMA_INLINE void print_m128(__m128 value) {
	float result[4]; 
	_mm_store_ps(result, value); 

	std::cout << "[" << result[0] << ", " << result[1] << ", " << result[2] << ", " << result[3] << "]" << std::endl;
}

void testMat4()
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

	std::cout << vectorA * matrixA << std::endl;
	kma::mat4 matrixC = matrixA * matrixB;
	//std::cout <<  << std::endl;

	//MulMatMat_sse(matrixA, matrixB);

	std::cout << "matrixC\n";
	print_m128(matrixC.m[0]);
	print_m128(matrixC.m[1]);
	print_m128(matrixC.m[2]);
	print_m128(matrixC.m[3]);


}
//
//void testVec3()
//{
//	kma::vec3  vecC{ 1, 2, 3};
//	std::cout << "vecC: " << vecC << std::endl;
//	kma::vec3  vecD{2, 5, 8};
//	std::cout << "vecD: " << vecD << std::endl;
//
//	float dot3product = kma::dot(vecC, vecD);
//	std::cout << "vec3 dot product: " << dot3product << std::endl;
//
//	kma::vec3 cross3product = kma::cross(vecC, vecD);
//	std::cout << "vec3 cross product: " << cross3product << std::endl;
//
//	std::cout << "vec3 normalized vector: " << vecC.normalize() << std::endl;
//
//	std::cout << "vec3 normalized vector: " << vecC << std::endl;
//
//}
//
//void testVec2()
//{
//	kma::vec2  vecC{ 1, 2};
//	std::cout << "vecC: " << vecC << std::endl;
//	kma::vec2  vecD{2, 5};
//	std::cout << "vecD: " << vecD << std::endl;
//
//	std::cout << "vec2 normalized vector: " << vecC.normalize() << std::endl;
//}
//
//void testQuaternions()
//{
//	float AngleA = 90.0f;
//	kma::vec4 vecA{1.0f, 2.0f, 3.0f,0.0f};
//	kma::quat quaternionA {AngleA, vecA};
//	std::cout << "quaternionA: " << quaternionA << std::endl;
//	float AngleB = 45.0f;
//	kma::vec4 vecB{4.0f, 5.0f, 6.0f, 0.0f};
//	kma::quat quaternionB {AngleB, vecB};
//	std::cout << "quaternionB: " << quaternionB << std::endl;
//
//	kma::quat mult = quaternionA * quaternionB;
//	std::cout << "quaternion mult: " << mult << std::endl;
//
//}

void generalTest()
{
	std::cout << "test" << std::endl;

	kma::vec3 Normal = {0.0f,1.0f,0.0f};
	kma::vec3 lightDir = { 1.0f,-1.0f,0.0f };

	//std::cout << kma::dot(Normal, lightDir) << std::endl;

	kma::vec3 a{ 2.5,6.4,3.0 };
	// length 7.49733
	// normalize (0.333452, 0.853637, 0.400142)
	kma::vec3 b{ -4.5,2.4,-2.0 };
	// length 5.47814
	// normalize (-0.821447, 0.438105, -0.365088)

	kma::vec3 c{ 1.0, 2.0, 3.0 };
	kma::vec3 d{ 6.0, 7.0, 8.0 };

	float dotp = kma::dot(c, d);

	std::cout << "Before normalize" << std::endl;
	std::cout << dotp << std::endl;

	kma::vec3 aN = c.normalize();
	kma::vec3 bN = d.normalize();

	dotp = kma::dot(c, d);

	std::cout << "After normalize" << std::endl;
	std::cout << dotp << std::endl;

	//std::cout << a.length() << std::endl;
	//std::cout << b.length() << std::endl;

}

int main()
{
//
	testVec4();
	testMat4();
//	testQuaternions();
	//testVec3();
//	testVec2();
	//generalTest();
//	
//
//	
//
	return 0;
 }