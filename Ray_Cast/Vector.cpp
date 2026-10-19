#include "Vector.h"


Vector::Vector()
{

}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector::getXPos() const
{
	return x;
}

float Vector::getYPos() const
{
	return y;
}

float Vector::getZPos() const
{
	return z;
}

float Vector::magnitude() const //length // 
{
	return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::normalize() const
{
	float mag = magnitude();

	if (mag <= 1e-6f)
	{
		return Vector(0, 0, 0);
	}

	float inverse = 1.0f / mag;

	return Vector(x * inverse, y * inverse, z * inverse);
}

Vector Vector::operator-(const Vector & v) const
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator-() const
{
	return Vector(-x,-y,-z);
}

Vector Vector::operator+(const Vector & v) const
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator/(const Vector & v) const
{
	return Vector(x / v.x, y / v.y, z / v.z);
}

Vector Vector::operator*(const Vector & v) const
{
	return Vector(x * v.x, y * v.y, z * v.z);
}

Vector Vector::operator*(const float & t) const
{
	return Vector(x*t,y*t,z*t);
}

std::ostream & operator<<(std::ostream & os, const Vector & v)
{
	return os << v.x << " " << v.y << " " << v.z << "\n";
}
