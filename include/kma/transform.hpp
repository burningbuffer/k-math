#include "vec4.hpp"
#include "mat4.hpp"

namespace kma
{
	mat4 scale(mat4 matrix, vec4 scalingFactor)
	{
		mat4 identity{};
		identity.matrix[0][0] = scalingFactor.x;
		identity.matrix[1][1] = scalingFactor.y;
		identity.matrix[2][2] = scalingFactor.z;

		return identity * matrix;
	}
}