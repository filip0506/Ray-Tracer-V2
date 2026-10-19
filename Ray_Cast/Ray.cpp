#include "Ray.h"


Ray::Ray(const Vector& i, const Vector& j)
{
	origin = i;
	direction = j;
}

Vector Ray::getOrigin() const
{
	return origin;
}

Vector Ray::getDirection() const
{
	return direction;
}
