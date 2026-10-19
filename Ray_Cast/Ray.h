#pragma once
#include "Vector.h"
class Ray
{
private:
	Vector origin;
	Vector direction;
public:
	Ray(const Vector& i, const Vector& j);
	Vector getOrigin() const;
	Vector getDirection() const;
};

