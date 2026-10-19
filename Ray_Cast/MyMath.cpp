#include "MyMath.h"


Vector Math::crossProduct(const Vector& a, const Vector& b)
{
	float x = ((a.getYPos() * b.getZPos()) - (a.getZPos() * b.getYPos()));
	float y = ((a.getZPos() * b.getXPos()) - (a.getXPos() * b.getZPos()));
	float z = ((a.getXPos() * b.getYPos()) - (a.getYPos() * b.getXPos()));

	return Vector(x, y, z);
}

float  Math::dotProduct(const Vector& a, const Vector& b)
{
	return  (a.getXPos() * b.getXPos()) + 
			(a.getYPos() * b.getYPos()) + 
			(a.getZPos() * b.getZPos());
}


