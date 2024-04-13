#include <kma/kma.hpp>
#include <catch.hpp>

TEST_CASE("Rotation", "[transform-tests]")
{
	std::cout << "Rotation Tests " << std::endl;

	kma::vec4 Pos{ -2,-5,-10,1 };
	kma::vec4 Axis{ 1,1,1,0 };
	float Angle = kma::radians(-45.0f);

	std::cout << Pos << std::endl;

	kma::mat4 rotationMatrix = kma::rotate(Angle, Axis);

	std::cout << "rotationMatrix" << std::endl;
	std::cout << rotationMatrix << std::endl;

	kma::vec4 result = Pos * rotationMatrix;

	std::cout << "Result Rotation" << std::endl;
	std::cout << result << std::endl;

}

TEST_CASE("Scaling", "[transform-tests]")
{
	std::cout << "Scale Test" << std::endl;

	kma::vec4 Pos{ 5,5,5,1 };
	kma::vec4 ScaleFactor{ 1,2,3,0 };
	kma::mat4 scaleMatrix = kma::scale(ScaleFactor);

	std::cout << "scaleMatrix\n";
	std::cout << scaleMatrix << std::endl;

	kma::vec4 result = Pos * scaleMatrix;

	std::cout << result << std::endl;

}

TEST_CASE("Translation", "[transform-tests]")
{
	std::cout << "Translation Test" << std::endl;

	kma::vec4 Pos{ 5,5,5,1 };
	kma::vec4 TranslationFactor{ 3,3,3,0 };
	kma::mat4 TranslationMatrix = kma::translate(TranslationFactor);

	std::cout << "translationMatrix\n";
	std::cout << TranslationMatrix << std::endl;

	kma::vec4 result = Pos * TranslationMatrix;

	std::cout << result << std::endl;

}


