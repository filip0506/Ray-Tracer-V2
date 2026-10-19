#pragma once
#include "Vector.h"
#include <limits>

class Math
{
private:


public:

	static constexpr float epsilon = std::numeric_limits<float>::epsilon();

	static Vector crossProduct(const Vector& a, const Vector& b);
	static float dotProduct(const Vector& a, const Vector& b);
};

